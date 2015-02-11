
#include "stm8s_uart1.h"
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "beep.h"
#include "wwdg.h"
//u8 RxBuffer[RxBufferSize];
//u8 UART_RX_NUM=0;

volatile static u16 display_num = 0;
u8 display_count = 0;
u16 ReloadDogTime = 0;

u8 uart_data_flag = 0;
u8 uart_rec_count = 0;
u8 uart_rec_data[7] = {0};
u16 vout_value = 0;

void send_display_num(u16 num)
{
   display_num = num;
   return;
}

#pragma vector=1
__interrupt void TRAP_IRQHandler(void)
{
  
}
#pragma vector=2
__interrupt void TLI_IRQHandler(void)
{
  
}
#pragma vector=3
__interrupt void AWU_IRQHandler(void)
{
  
}
#pragma vector=4
__interrupt void CLK_IRQHandler(void)
{
  
  
}
#pragma vector=5
__interrupt void EXTI_PORTA_IRQHandler(void)
{
  
}
#pragma vector=6
__interrupt void EXTI_PORTB_IRQHandler(void)
{
  
}
#pragma vector=7
__interrupt void EXTI_PORTC_IRQHandler(void)
{
  
}
#pragma vector=8
__interrupt void EXTI_PORTD_IRQHandler(void)
{
  
}
#pragma vector=9
__interrupt void EXTI_PORTE_IRQHandler(void)
{
   
}
#ifdef STM8S903
#pragma vector=0xA
__interrupt void EXTI_PORTF_IRQHandler(void)
{
  
}
#endif
#ifdef STM8S208
#pragma vector=0xA
__interrupt void CAN_RX_IRQHandler(void)
{
  
}
#pragma vector=0xB
__interrupt void CAN_TX_IRQHandler(void)
{
  
}
#endif
#pragma vector=0xC
__interrupt void SPI_IRQHandler(void)
{
  
}
#pragma vector=0xD
__interrupt void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void)
{
  display_count ++;
  switch(display_count)
  {
  case 1:
    {
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      GPIO_WriteLow(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_4|GPIO_PIN_3));
      sendnumber(display_num%10);
    }
    break;
  case 2:
    {
      GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
      GPIO_WriteLow(GPIOC,GPIO_PIN_3);
      GPIO_WriteLow(GPIOD,GPIO_PIN_2);
      sendnumber(display_num%100/10);
    }
    break;
  case 3:
    {
      GPIO_WriteHigh(GPIOC,GPIO_PIN_3);
      GPIO_WriteLow(GPIOC,GPIO_PIN_4);
      GPIO_WriteLow(GPIOD,GPIO_PIN_2);
      sendnumber(display_num%1000/100);
    }
    break;
  default:
    break;
  }
  if(display_count == 3)
    display_count = 0;
  TIM1_ClearITPendingBit(TIM1_IT_UPDATE);
}
#pragma vector=0xE
__interrupt void TIM1_CAP_COM_IRQHandler(void)
{
  
}
#ifdef STM8S903
#pragma vector=0xF
__interrupt void TIM5_UPD_OVF_BRK_TRG_IRQHandler(void)
{
  
}
#pragma vector=0x10
__interrupt void TIM5_CAP_COM_IRQHandler(void)
{
  
}
#else
#pragma vector=0xF
__interrupt void TIM2_UPD_OVF_BRK_IRQHandler(void)
{
  adc_irq();
  Beep_tick();
  ReloadDogTime++;
  if(ReloadDogTime==200)//206
  {    
    ReloadDogTime=0;
    IWDG_ReloadCounter();
  }
  Refresh_WWDG_Window();
  TIM2_ClearITPendingBit(TIM2_IT_UPDATE);
}
#pragma vector=0x10
__interrupt void TIM2_CAP_COM_IRQHandler(void)
{
  
}
#endif
#if defined (STM8S208) || defined(STM8S207) || defined(STM8S105)
#pragma vector=0x11
__interrupt void TIM3_UPD_OVF_BRK_IRQHandler(void)
{
  
}
#pragma vector=0x12
__interrupt void TIM3_CAP_COM_IRQHandler(void)
{
  
}
#endif
//#ifndef STM8S105
#if defined (STM8S208) || defined(STM8S207) || defined(STM8S105)
#pragma vector=0x13
__interrupt void UART1_TX_IRQHandler(void)
{
  
}
#pragma vector=0x14
__interrupt void UART1_RX_IRQHandler(void)
{ 
     u8 USART1_RX_BUF; 

     while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
     USART1_RX_BUF = UART1_ReceiveData8();
     
     if(USART1_RX_BUF == 0xaa)
     {
       uart_data_flag = 1;
       uart_rec_count = 0;
     }
     if(uart_data_flag == 1)
     {
       uart_rec_data[uart_rec_count] = USART1_RX_BUF;
       
       if(uart_rec_count == 6)
       {
         uart_data_flag = 0;
         if((uart_rec_data[6] == 0xFF) && (uart_rec_data[5] == (u8)(uart_rec_data[1] \
           + uart_rec_data[2] + uart_rec_data[3] + uart_rec_data[4])))
         {
           vout_value = uart_rec_data[1] *256 + uart_rec_data[2];
           //Send_ADC_Value(vout_value);
           send_uart_value(vout_value);
         }
       }
       uart_rec_count ++;
     }
     
     //UART1_SendData8(USART1_RX_BUF);
      /* Loop until the end of transmission */
      //while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
}
#endif
#pragma vector=0x15
__interrupt void I2C_IRQHandler(void)
{
  
}
#ifdef STM8S105
#pragma vector=0x16
__interrupt void UART2_TX_IRQHandler(void)
{
   
}
#pragma vector=0x17
__interrupt void UART2_RX_IRQHandler(void)
{
   
}
#endif
#if defined(STM8S207) || defined(STM8S208)
#pragma vector=0x16
__interrupt void UART3_TX_IRQHandler(void)
{
  
}
#pragma vector=0x17
__interrupt void UART3_RX_IRQHandler(void)
{
  
}
#endif
#if defined(STM8S207) || defined(STM8S208)
#pragma vector=0x18
__interrupt void ADC2_IRQHandler(void)
{
   
}
#else
#pragma vector=0x18
__interrupt void ADC1_IRQHandler(void)
{
   
}
#endif
#ifdef STM8S903
#pragma vector=0x19
__interrupt void TIM6_UPD_OVF_TRG_IRQHandler(void)
{
  
}
#else
#pragma vector=0x19
__interrupt void TIM4_UPD_OVF_IRQHandler(void)
{
  
}
#endif
#pragma vector=0x1A
__interrupt void EEPROM_EEC_IRQHandler(void)
{
  
}

