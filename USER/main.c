/* Includes ------------------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_clk.h"
#include "intrinsics.h"
#include "stm8s_uart1.h"
#include "uart.h"
#include "led.h"
#include "tim1.h"
#include "adc.h"
#include "beep.h"
#include "alarm_judge.h"
#include "iwdg.h"
#include "wwdg.h"
void Delay(u32 nCount);

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
extern void send_display_num(u16 num);
u16 start_num[10] = {0,111,222,333,444,555,666,777,888,999};

void display_startup(void)
{
  u8 i;
  for(i=0;i<10;i++)
  {
    send_display_num(start_num[9-i]);
    Delay(0x7ffff);
  }
}

int main(void)
{
  /* Infinite loop */
  u16 PM2_5_value = 0;
  /*设置内部时钟16M为主时钟*/ 
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  /*!<Set High speed internal clock  */
   LED_Init();
   //ADC_Init();
   Tim1_Init();
   Tim2_Init();
   BEEP_LSICalibrationConfig(LSI_128kHz);
   Beep_Init(BEEP_FREQUENCY_2KHZ);
   Uart_Init();
   IWDG_Configuration();
   WWDG_Configuration();
   __enable_interrupt();
   start_beep();
   display_startup();
   while (1)
   {        
        PM2_5_value = get_PM2_5_value();
        //UART1_SendString("Conversion_Value is:",sizeof("Conversion_Value is:"));
        //Delay(0xffff);
        //Delay(0xff);
        //Send_ADC_Value(PM2_5_value);
        send_display_num(PM2_5_value);
        judge_grade(PM2_5_value);
   }
}

void Delay(u32 nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
