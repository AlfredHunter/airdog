#include "alarm_judge.h"
#include "beep.h"

static u8 air_grade_now = 0;
static u8 air_grade_pre = 0;

void judge_grade(u16 value)
{
  u16 air_value;
  air_value = value;
  if((air_value>0)&&(air_value<100))
  {
    air_grade_now = 0;
  }
  if((air_value>=100)&&(air_value<200))
  {
    air_grade_now = 1;
  }
  if(air_value>=200)
  {    
    air_grade_now = 2;
  }
  if(air_grade_pre < air_grade_now)
  {
    start_alarm();
  }
  air_grade_pre = air_grade_now;
}