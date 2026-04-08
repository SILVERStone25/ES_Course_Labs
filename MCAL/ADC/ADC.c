#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

void ADC_Init(void)
{
    /* AN0 is Analog, Right Justified result */
    ADCON1_REG = ADCON1_CONFIG;      
    
    /* Ensure RA0 is an input */
    TRISA_REG |= (1 << 0);       
    
    /* Fosc/32 clock, Turn ADC ON */
    ADCON0_REG = 0x81;      
    Delay_ms(2);
}

u16 ADC_Read(u8 channel)
{
    /* Clear channel bits (Bits 5, 4, 3) safely */
    ADCON0_REG &= 0xC7;
    
    /* Insert the new channel */
    ADCON0_REG |= (channel << 3);
    
    /* Give capacitor time to charge */
    Delay_us(50);
    
    /* Start conversion using Bit 2 (GO/DONE) */
    ADCON0_REG |= (1 << 2);
    
    /* Wait for conversion to finish (hardware pulls it back to 0) */
    while (ADCON0_REG & (1 << 2));
    
    /* Return result directly from the registers */
    return ((u16)ADRESH_REG << 8) | ADRESL_REG;
}

u16 ADC_Read_mV(u8 channel)
{
    /* Using standard 'unsigned long' since 'u32' isn't in STD_TYPES.h yet */
    unsigned long voltage;
    u16 raw = ADC_Read(channel);
    
    /* Break the math into multiple steps to prevent the optimizer from failing */
    voltage = (unsigned long)raw * 5000UL;
    voltage = voltage / 1023UL;
    
    return (u16)voltage;
}

u16 ADC_ReadTemperatureC(u8 channel)
{
    return ADC_Read_mV(channel) / 10U;
}