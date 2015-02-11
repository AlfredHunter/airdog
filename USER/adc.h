#ifndef __ADC_H
#define __ADC_H
#include "stm8s.h"

#define CONVERSIONMODE   1
#define CONVERSIONMODE_SINGLE  0
#define CONVERSIONMODE_CONTINUOUS  1

void ADC_Init(void);
void adc_irq(void);
u16 get_PM2_5_value(void);
void send_uart_value(u16 uart_value);
#endif