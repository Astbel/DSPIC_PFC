#ifndef __SYSTEMDEFINE_H_
#define __SYSTEMDEFINE_H_
/**Waring 這裡所有的定義是需要翻修過後重新計算由於尚未知道硬體配制這裡都是暫時定義**/


/*AC Side*/

/*ADC值暫定由於不知道shunt 電阻*/
/*Bwron in   78Vac */
#define PSU_Bwron_IN   1623  
/*Bwron out  72Vac*/
#define PSU_Bwron_OUT  1499 

/*PGI PIN尚未定義*/

/*PGI LEVEL adc 取樣電阻後這個是要修正過這只是暫時 為了150ms */
#define PGI_High_Level 2641  //380v
#define PGI_Low_Level  2341  //360v

/*1次側保護 Hiccup OVP*/
/*這邊假定電容耐壓是450V OVP 則會定在*/
#define Hiccup_Volt_level    2927  //450V
#define Over_Volt_Proction   3057 //470V

/*時序 這裡假定ISR時間是100us執行一次然後目標設計 是20ms*/
#define Hold_Up_Time_CNT  200 




#endif
