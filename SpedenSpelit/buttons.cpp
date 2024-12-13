#include "buttons.h"


const unsigned long debounceDelay = 250;

void initButtonsAndButtonInterrupts(void)
{
  // See requirements for this function from buttons.h
  
    for (int i = 2; i <= 6; i++) {
          pinMode(i, INPUT_PULLUP);
    }
    PCICR |= (1 << PCIE2); 
    PCMSK2 |= (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21) | (1 << PCINT22);
}



