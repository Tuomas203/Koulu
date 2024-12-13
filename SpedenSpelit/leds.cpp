#include "leds.h"

// Define LED pins
const int ledPins[] = {A2, A3, A4, A5};
byte currentLed = 255; // Keeps track of currently lit LED (255 means none)

// Initialize LED pins as outputs
void initializeLeds() {
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}

// Set a specific LED, turning off all others
void setLed(byte ledNumber) {
    if (ledNumber < 0 || ledNumber > 3) return;

    clearAllLeds(); // Turn off all LEDs
    digitalWrite(ledPins[ledNumber], HIGH); // Turn on the specified LED
    currentLed = ledNumber; // Update the currently lit LED
}

// Turn off all LEDs
void clearAllLeds(void) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }
    currentLed = 255; // No LED is lit
}

// Turn on all LEDs
void setAllLeds(void) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], HIGH);
    }
    currentLed = 255; // Special state: all LEDs are lit
}

// Show binary numbers 0–15 on LEDs
void show1(void) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                digitalWrite(ledPins[j], HIGH); // Turn on LED if bit is 1
            } else {
                digitalWrite(ledPins[j], LOW); // Turn off LED if bit is 0
            }
        }
        delay(500); // Pause for visibility
    }
}

// Sequentially light up LEDs with increasing speed
void show2(int rounds) {
    int delayTime = 300; // Initial delay
    for (int r = 0; r < rounds; r++) {
        for (int i = 0; i < 4; i++) {
            clearAllLeds();
            for (int j = 0; j <= i; j++) {
                digitalWrite(ledPins[j], HIGH); // Turn on LEDs from 0 to i
            }
            delay(delayTime);
        }
        if (delayTime > 50) delayTime -= 20; // Increase speed
    }
    clearAllLeds();
}