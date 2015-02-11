#include "iwdg.h"


void IWDG_Configuration(void)
{
  /* Enable the IWDG*/
  IWDG_Enable();
  /* Enable the access to the IWDG registers*/
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  /* Fixe IWDG Reset period */
  IWDG_SetPrescaler(IWDG_Prescaler_256);
  IWDG_SetReload(0xFF);
  /* Refresh IWDG */
  IWDG_ReloadCounter();
}

void Test_IWDGReset(void)
{
  FlagStatus IwdgFlag;

  /*Get IWDG Reset Status */ 
  IwdgFlag = RST_GetFlagStatus(RST_FLAG_IWDGF);
  /* Test if a IWDG Reset has occured */
  if (IwdgFlag)
  {
    
    /* Clear IWDGF Flag */
    RST_ClearFlag(RST_FLAG_IWDGF);
   
  }
}
