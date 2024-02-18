#ifndef __SYSTEMDEFINE_H_
#define __SYSTEMDEFINE_H_
/**Waring 這裡所有的定義是需要翻修過後重新計算由於尚未知道硬體配制這裡都是暫時定義**/
#include "stdlib.h"
#include "string.h"

/*資料型別定義*/
typedef unsigned char		uint8_t ;
typedef unsigned int		uint16_t ;
typedef unsigned long		uint32_t ;
typedef unsigned long long		uint64_t ;
typedef char				int8 ;
typedef int				int16 ;
typedef long				int32 ;

/*AC Side*/
#define AC_DROP_CNT 10
/*AC Zero Cross Level 定義額度不可能完全為0Vac下以5% offset誤差計算*/
#define Zero_Cross_Level 49 // 假設ADC 解析度12bit

/*ADC值暫定由於不知道shunt 電阻*/
/*ADC Channel*/
#define VBUS_CHANNEL 0
#define AC_N_CHANNEL 1
#define AC_L_CHANNEL 2
/*Bwron in   78Vac */
#define PSU_Bwron_IN 1623
/*Bwron out  72Vac*/
#define PSU_Bwron_OUT 1499
/*Bwron Out 計數*/
#define Bwron_Out_CNT 200
/*PGI PIN尚未定義*/

/*PGI LEVEL adc 取樣電阻後這個是要修正過這只是暫時 為了150ms */
#define PGI_High_Level 2641 // 380v
#define PGI_Low_Level 2341  // 360v

/*1次側保護 Hiccup OVP*/
/*這邊假定電容耐壓是450V OVP 則會定在*/
#define Hiccup_Volt_level 2927  // 450V
#define Over_Volt_Proction 3057 // 470V

/*時序 這裡假定ISR時間是100us執行一次然後目標設計 是20ms*/
#define Hold_Up_Time 200

/*Array 大小聲明*/
#define ADC_Size 5

/*Boolean*/
#define True   1
#define False  0
/*High Low*/
#define High   1
#define Low    0

#endif
