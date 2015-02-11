#ifndef __LED_H
#define __LED_H
#include "stm8s_gpio.h"

#define ON  0
#define OFF 1
#define LED(ON_OFF)  if(ON_OFF==ON)GPIO_WriteLow(GPIOB, GPIO_PIN_5);\
                      else GPIO_WriteHigh(GPIOB, GPIO_PIN_5)

                        
void LED_Init(void);
void sendnumber(uint8_t num);
#endif
                        