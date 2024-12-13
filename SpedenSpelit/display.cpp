#include "display.h"



int resetPin = 12;
int shiftClockPin = 11;
int latchClockPin = 10;
int outEnablePin = 9;
int serialInputPin = 8;



int digits[10][8]{
  { 1, 1, 1, 1, 1, 1, 0, 0 },  //digit 0
  { 0, 1, 1, 0, 0, 0, 0, 0 },  //digit 1
  { 1, 1, 0, 1, 1, 0, 1, 0 },  //digit 2
  { 1, 1, 1, 1, 0, 0, 1, 0 },  //digit 3
  { 0, 1, 1, 0, 0, 1, 1, 0 },  //digit 4
  { 1, 0, 1, 1, 0, 1, 1, 0 },  //digit 5
  { 1, 0, 1, 1, 1, 1, 1, 0 },  //digit 6
  { 1, 1, 1, 0, 0, 0, 0, 0 },  //digit 7
  { 1, 1, 1, 1, 1, 1, 1, 0 },  //digit 8
  { 1, 1, 1, 0, 0, 1, 1, 0 }   //digit 9
};


void initializeDisplay(void) {

  // See requirements for this function from display.h

  pinMode(resetPin, OUTPUT);
  pinMode(shiftClockPin, OUTPUT);
  pinMode(latchClockPin, OUTPUT);
  pinMode(outEnablePin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
  digitalWrite(outEnablePin, LOW);
}


void writeByte(uint8_t number) {
  digitalWrite(resetPin, HIGH);
  // See requirements for this function from display.h
  digitalWrite(latchClockPin, LOW);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(shiftClockPin, LOW);
    if (digits[number][i] == 0) digitalWrite(serialInputPin, LOW);
    if (digits[number][i] == 1) digitalWrite(serialInputPin, HIGH);
    digitalWrite(shiftClockPin, HIGH);
  }
  //digitalWrite(latchClockPin, HIGH);
  //digitalWrite(resetPin, LOW);
};



void writeHighAndLowNumber(uint8_t tens, uint8_t ones) {
  // See requirements for this function from display.h
  
  writeByte(ones);
  writeByte(tens);
  digitalWrite(latchClockPin, HIGH);
}

void showResult(byte number) {
  // See requirements for this function from display.h
  byte ones = number % 10;
  byte tens = number / 10 % 10;
  writeHighAndLowNumber(tens, ones);



}