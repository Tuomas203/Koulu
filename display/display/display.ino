#include "display.h"
#include <arduino.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initializeDisplay();
}

void loop() {
  // i = 1
  // j= 10

  for (int i=0; i <= 99; i++) {

    showResult(i);

    delay(100);
    Serial.println(i);
  }
}
