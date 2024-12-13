#include "display.h"
#include "buttons.h"
#include "leds.h"
#include "SpedenSpelit.h"

// Use these 2 volatile variables for communicating between
// loop() function and interrupt handlers
volatile int buttonNumber = -1;           // for buttons interrupt handler
volatile bool newTimerInterrupt = false;  // for timer interrupt handler

volatile int randomNumbers[100] = {0};
volatile int userNumbers[100] = {0};
volatile int roundCheck = 0;
volatile int currentRound = 0;
volatile int userPresses = 0;
volatile bool timeToCheckGameStatus = false;
volatile int timerSpeed = 15624;
volatile bool gameOn = false;
volatile int buttonPressed[100] = {0};

volatile unsigned long lastPressTime[7] = {0};
const unsigned long debounceDelay = 250;

const int ledPins[] = {A2, A3, A4, A5};
volatile bool ledBlinking = false;     // Is the LED blinking for a new round?
volatile unsigned long blinkStartTime = 0; // When the blink started
const unsigned long blinkDuration = 50;  // How long to turn off the LED (in milliseconds)
volatile int lastRandomNumber = -1;   // Tracks the last random number

void setup()
{
    initializeTimer();
    initButtonsAndButtonInterrupts();
    initializeDisplay();
    initializeLeds();

    Serial.begin(9600);
}

void loop()
{
    if (buttonNumber >= 0) {
        if (buttonNumber == 6) {
            startTheGame();
            Serial.println("Game started");
        } else if (buttonNumber >= 2 && buttonNumber <= 5) {
            if (gameOn) {
                userNumbers[currentRound] = buttonNumber;
                checkGame();
            }
        }

        buttonNumber = -1; // Reset after processing
    }

    if (newTimerInterrupt) {
    newTimerInterrupt = false;

    // Get the next random number
    int nextRandom = random(0, 4);
    randomNumbers[currentRound] = nextRandom;

    Serial.println(currentRound);
    Serial.print("Random LED: ");
    Serial.println(nextRandom);

    // Check if the same LED is drawn consecutively
    if (nextRandom == lastRandomNumber) {
        // Turn off the LED briefly before reactivating
        for (int i = 0; i < 4; i++) {
            digitalWrite(ledPins[i], LOW);
        }
        ledBlinking = true;                 // Indicate that we're in the "blink off" state
        blinkStartTime = millis();          // Record the time we started the blink
    } else {
        // Activate the new LED immediately
        for (int i = 0; i < 4; i++) {
            digitalWrite(ledPins[i], (i == nextRandom) ? HIGH : LOW);
        }
    }

    lastRandomNumber = nextRandom;         // Update the last random number
    roundCheck++;
}

if (ledBlinking) {
    if (millis() - blinkStartTime >= blinkDuration) {
        // Reactivate the LED for the new round
        for (int i = 0; i < 4; i++) {
            digitalWrite(ledPins[i], (i == randomNumbers[currentRound]) ? HIGH : LOW);
        }
        ledBlinking = false; // Reset the blinking flag
    }
}


}

void initializeTimer(void) {
    cli(); 

    TCCR1A = 0; 
    TCCR1B = 0; 
    TCNT1 = 0;  
    OCR1A = timerSpeed; 
    TCCR1B |= (1 << WGM12);  
    TIMSK1 |= (1 << OCIE1A); 
    Serial.println("Timer initialized");
    sei(); 
}

ISR(TIMER1_COMPA_vect) {
    newTimerInterrupt = true;

    if (userPresses != 0 && userPresses % 10 == 0) {
        timerSpeed = max(500, (int)(timerSpeed * 0.9)); // Reduce by 10%, lower bound
        OCR1A = timerSpeed;
        Serial.println("Game sped up");
    }

    if (currentRound >= 100) {
        stopTheGame();
    }
}

void checkGame(void) {
    Serial.println("Game checked");
    Serial.println(userNumbers[currentRound]);
    Serial.println(randomNumbers[currentRound]);

    if (userNumbers[currentRound] - 2 != randomNumbers[currentRound]) {
        stopTheGame();
    } else {
        currentRound++;
        if (roundCheck == userPresses) {
          showResults();
        Serial.println("Correct press");
        }
        else {
          stopTheGame();
          Serial.println("Button not pressed");
        }
    }
}

void initializeGame() {
    currentRound = 0;
    userPresses = 0;
    roundCheck = 0;
    timeToCheckGameStatus = false;
    timerSpeed = 15624; 

    for (int i = 0; i < 100; i++) {
        randomNumbers[i] = -1;
        userNumbers[i] = -1;
    }
}

void startTheGame(void) {
    initializeGame();
    TCNT1 = 0;
    TCCR1B |= (1 << CS12) | (1 << CS10);
    gameOn = true;
    Serial.println("Game started");
}

void stopTheGame(void) {
    gameOn = false;
    TCCR1B &= ~((1 << CS12) | (1 << CS10));
    Serial.println("Game stopped");

    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }
    Serial.print("Final score is ");
    Serial.println(userPresses - 1);
    showResult(userPresses - 1);
}

void showResults() {
    Serial.print("Score: ");
    Serial.println(userPresses);
    showResult(userPresses);
}

ISR(PCINT2_vect) 
{
    unsigned long currentTime = millis();

    for (int i = 2; i <= 6; i++) {
        if ((currentTime - lastPressTime[i]) > debounceDelay && digitalRead(i) == LOW) {
            lastPressTime[i] = currentTime;
            buttonNumber = i;
            if (i >= 2 && i <= 5) {
                userNumbers[currentRound] = i;
                Serial.print("Button ");
                Serial.print(i);
                Serial.println(" pressed.");
                userPresses++;
            } else if (i == 6) {
                Serial.println("Start button pressed.");
            }
        }
    }
}
