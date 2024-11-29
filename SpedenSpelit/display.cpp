#include "display.h"



int resetPin = 12;
int shiftClockPin = 11;
int latchClockPin = 10;
int outEnablePin = 9;
int serialInputPin = 8;

void initializeDisplay(void)
{

// See requirements for this function from display.h

pinMode(resetPin, OUTPUT);
pinMode(shiftClockPin, OUTPUT);
pinMode(latchClockPin, OUTPUT);
pinMode(outEnablePin, OUTPUT);
pinMode(serialInputPin, OUTPUT);
}


void writeByte(uint8_t bits,bool last)
{
// See requirements for this function from display.h
}


void writeHighAndLowNumber(uint8_t tens,uint8_t ones)
{
// See requirements for this function from display.h
}

void showResult(byte number)
{
// See requirements for this function from display.h
}

