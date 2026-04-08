#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/Std_TYPES.h"

/* Registers - using MikroC built-in names */
#define TMR0_REG          TMR0
#define OPTION_REG_CUSTOM OPTION_REG
#define INTCON_REG        INTCON

/* Interrupt Bits */
#define T0IF_BIT 2
#define T0IE_BIT 5
#define GIE_BIT  7

#endif