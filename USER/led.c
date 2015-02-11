#include "led.h"
const char led_num[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

void LED_Init(void)
{
   //GPIO_Init(GPIOB,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5),GPIO_MODE_OUT_OD_HIZ_FAST);//定义LED的管脚的模式
   GPIO_Init(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_3|GPIO_PIN_4),GPIO_MODE_OUT_PP_HIGH_FAST);
   GPIO_Init(GPIOD,GPIO_PIN_2,GPIO_MODE_OUT_PP_HIGH_FAST);//GPIO_MODE_OUT_PP_HIGH_FAST);
   GPIO_Init(GPIOA,(GPIO_Pin_TypeDef)(GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3),GPIO_MODE_OUT_OD_HIZ_FAST);
   GPIO_Init(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7),GPIO_MODE_OUT_OD_HIZ_FAST);
   //GPIO_Init(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5),GPIO_MODE_OUT_OD_HIZ_FAST);
   GPIO_Init(GPIOB,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5),GPIO_MODE_OUT_OD_HIZ_FAST);
   GPIO_WriteLow(GPIOA,(GPIO_Pin_TypeDef)(GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3));
   GPIO_WriteLow(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7));
   //GPIO_WriteLow(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5));
   GPIO_WriteLow(GPIOB,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5));
   
   //GPIO_WriteHigh(GPIOB,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_5));
   GPIO_WriteHigh(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_3|GPIO_PIN_4));
   GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
}

void sendnumber(uint8_t num)
{
  uint8_t temp;
  temp = led_num[num];
    if(temp & 0x80)
      GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
    else
      GPIO_WriteLow(GPIOC,GPIO_PIN_7);
    temp <<= 1;
    if(temp & 0x80)
      GPIO_WriteHigh(GPIOA,GPIO_PIN_2);
    else
      GPIO_WriteLow(GPIOA,GPIO_PIN_2);
    temp <<= 1;
    if(temp & 0x80)
      //GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
      GPIO_WriteHigh(GPIOB,GPIO_PIN_5);
    else
      //GPIO_WriteLow(GPIOC,GPIO_PIN_4);
      GPIO_WriteLow(GPIOB,GPIO_PIN_5);
    temp <<= 1;
    if(temp & 0x80)
      //GPIO_WriteHigh(GPIOC,GPIO_PIN_5);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_5);
    else
      //GPIO_WriteLow(GPIOC,GPIO_PIN_5);
      GPIO_WriteLow(GPIOC,GPIO_PIN_5);
    temp <<= 1;
    if(temp & 0x80)
      GPIO_WriteHigh(GPIOC,GPIO_PIN_6);
    else
      GPIO_WriteLow(GPIOC,GPIO_PIN_6);
    temp <<= 1;
    if(temp & 0x80)
      GPIO_WriteHigh(GPIOA,GPIO_PIN_1);
    else
      GPIO_WriteLow(GPIOA,GPIO_PIN_1);
    temp <<= 1;  
    if(temp & 0x80)
      GPIO_WriteHigh(GPIOA,GPIO_PIN_3);
    else
      GPIO_WriteLow(GPIOA,GPIO_PIN_3);
    temp <<= 1;
    if(temp & 0x80)
      GPIO_WriteHigh(GPIOB,GPIO_PIN_4);
    else
      GPIO_WriteLow(GPIOB,GPIO_PIN_4);
  return;
}