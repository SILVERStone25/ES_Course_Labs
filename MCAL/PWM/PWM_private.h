#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/Std_Types.h"

/* Timer2 and CCP Registers - using MikroC built-in names */
#define T2CON           T2CON
#define TMR2            TMR2
#define PR2             PR2

#define CCPR1L          CCPR1L
#define CCPR1H          CCPR1H
#define CCP1CON         CCP1CON

#define CCPR2L          CCPR2L
#define CCPR2H          CCPR2H
#define CCP2CON         CCP2CON

#define TRISC           TRISC

/* Timer2 Control Bits */
#define T2CKPS0         0   // Prescaler bits
#define T2CKPS1         1
#define TMR2ON          2   // Timer2 Enable

/* CCP Control Bits for PWM Mode */
#define CCP_PWM_MODE    0x0C  // 1100 binary

#endif
