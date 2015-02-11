#include "uniqueid.h"

u8 ChipUniqueID[12];

/********************************************************
 * 函数名：Get_ChipID
 * 描述  ：获取芯片ID
 * 输入  ：无
 * 输出  ：无
 ********************************************************/
void Get_ChipID(void)
{
	ChipUniqueID[0] = *(__IO u16 *)(0X48CD); 
	ChipUniqueID[1] = *(__IO u16 *)(0X48CE); 
	ChipUniqueID[2] = *(__IO u16 *)(0X48CF);
        ChipUniqueID[3] = *(__IO u16 *)(0X48D0); 
	ChipUniqueID[4] = *(__IO u16 *)(0X48D1); 
	ChipUniqueID[5] = *(__IO u16 *)(0X48D2);
        ChipUniqueID[6] = *(__IO u16 *)(0X48D3); 
	ChipUniqueID[7] = *(__IO u16 *)(0X48D4); 
	ChipUniqueID[8] = *(__IO u16 *)(0X48D5);
        ChipUniqueID[9] = *(__IO u16 *)(0X48D6); 
	ChipUniqueID[10] = *(__IO u16 *)(0X48D7); 
	ChipUniqueID[11] = *(__IO u16 *)(0X48D8);
}
