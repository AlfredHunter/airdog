#include "tim1.h"

void Tim1_Init(void)
{
  TIM1_TimeBaseInit(16,TIM1_COUNTERMODE_UP,5000,0);
  TIM1_ARRPreloadConfig(ENABLE);
  TIM1_ITConfig(TIM1_IT_UPDATE , ENABLE);
  TIM1_Cmd(ENABLE);
}
void Tim2_Init(void)
{
  TIM2_TimeBaseInit(TIM2_PRESCALER_16,5000);
  TIM2_ARRPreloadConfig(ENABLE);
  TIM2_ITConfig(TIM2_IT_UPDATE , ENABLE);
  TIM2_Cmd(ENABLE);
}