#include "Switch.h"
void SWITCH_Init(uint8 pin) {
    if (pin == 0) {
        TRISB0_bit = 1;
    }
}