#include "LED.h"

void LED_Init(void) {
    TRISD0_bit = 0; // Configure RD0 as output
    RD0_bit = 0;    // Initialize LED to OFF
}

void LED_Toggle(void) {
    RD0_bit = ~RD0_bit; // Toggle RD0 state
}