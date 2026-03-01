#include "EXT_INT0.h"
#include "LED.h"
#include "Switch.h"

void App_ButtonPressLogic(void) {
    Delay_ms(30); 
    
    if (PORTB.F0 == 0) { 
        LED_Toggle();
    }
}

void main() {
    LED_Init();
    SWITCH_Init(0); 
    EXT_INT0_Init();
    
    EXT_INT0_SetEdge(INT0_FALLING_EDGE); 
    
    EXT_INT0_SetCallback(App_ButtonPressLogic);
    
    EXT_INT0_Enable();
    
    while(1) {
    }
}