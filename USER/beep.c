#include "beep.h"
#define Beep_OptionAdd  0x4803

u8 alarm_flag = 0;
u8 beepstart_flag = 0;
u16 alarm_count = 0;
u8 alarm_stop_count = 0;
typedef enum {
  RING = 0,
  QUIET,
}BUZZER_STATUS;

BUZZER_STATUS buzzer_state = RING;

void Beep_Init(BEEP_Frequency_TypeDef BEEP_Frequency)
{
  BEEP_Init(BEEP_Frequency);
  CLK_LSICmd(ENABLE);
  BEEP_Cmd(DISABLE);
}

void start_alarm(void)
{
  alarm_flag = 1;
  BEEP_Cmd(ENABLE);
}
void start_beep(void)
{
  beepstart_flag = 1;
  BEEP_Cmd(ENABLE);
}
void Beep_tick(void)
{
  if(alarm_flag)
  {
    switch(buzzer_state)
    {
    case RING:
      {
         alarm_count ++;
          if(alarm_count > 80)
          {
              alarm_count = 0;
              alarm_stop_count ++;
              if(alarm_stop_count == 2)
              {
                alarm_stop_count = 0;
                alarm_flag = 0;
                BEEP_Cmd(DISABLE);
                return;
              }
              BEEP_Cmd(DISABLE);
              buzzer_state = QUIET;
          }
      }
      break;
    case QUIET:
      {
         alarm_count ++;
          if(alarm_count > 10)
          {
              alarm_count = 0;
              BEEP_Cmd(ENABLE);
              buzzer_state = RING;
          }
      }
      break;
    default:
      break;
    }
  }
  if(beepstart_flag)
  {
    alarm_count ++;
          if(alarm_count > 80)
          {
              beepstart_flag = 0;
              alarm_count = 0;
              BEEP_Cmd(DISABLE);
          }
  }
}