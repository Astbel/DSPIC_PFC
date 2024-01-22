#ifndef __MYCVALUE_H_
#define __MYCVALUE_H_

/*引用區*/
#include "Systemdefine.h"

/*結構體聲明class建造*/

typedef struct 
{
    uint32_t VBulk;
    uint32_t Ind_Curr_Phase_A;
    uint32_t Ind_Curr_Phase_B;
}PFC_parameter;

typedef struct 
{
    uint32_t AC_L;
    uint32_t AC_N;
    uint32_t AC_PEAK;
    uint32_t AC_Zero_Cross;
    uint32_t AC_Sequence;
    uint8_t  AC_level;
}AC_parameter;

/*enum 聲明建造*/



/*結構體 & enum object建立*/
extern PFC_parameter PFC_Class;
extern AC_parameter  AC_CLass;
/*結構體PTR建立*/


/*變數聲明*/
extern uint32_t ADC_Array[ADC_Size];
extern uint32_t VBulk_Sqrt_2;

/*擴充方法聲明*/
inline void initail_parameter(void);



















#endif

