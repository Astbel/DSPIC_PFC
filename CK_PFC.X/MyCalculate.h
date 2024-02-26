#ifndef __MYCALCULATE_H_
#define __MYCALCULATE_H_

#define Moving_Sample_Rate 4

/*public 變數*/

/*Struct*/

/*類別物件化*/

/*類別物件指標*/

/*擴充方法聲明*/
// void Moving_AVG(uint8_t new_point, uint32_t Array[4], uint8_t *index);
void Zero_Cross_detcet(void);
void AC_Drop(void);
void Hold_Up_Time_Method(void);
void Bwron_Out_Method(void);
void AC_Gear(void);

#endif
