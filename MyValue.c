/*引用區*/
#include "MyValue.h"

/*宣告區  var,struct,etc...*/
PFC_parameter PFC_Class;
AC_parameter AC_CLass;

/*struct inital*/
PFC_parameter PFC_Class = {0, 0, 0};
AC_parameter AC_CLass = {0, 0, 0, 0, 0, 0};

/*ptr 建立*/
PFC_parameter *_PFC_Class;
AC_parameter *_AC_Class;

/*變數聲明*/
uint32_t ADC_Array[ADC_Size];
/*初始化變數*/
inline void initail_parameter(void)
{
    _PFC_Class = &PFC_Class;
    _AC_Class = &AC_CLass;
    
    /*inital adc value*/
    memset(ADC_Array,0,ADC_Size);
    
}
