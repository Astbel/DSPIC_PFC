/*include path*/
#include "MyCalculate.h"
#include "MyValue.h"

/**
 * @brief
 *
 */
inline void Moving_AVG(void)
{
}

/**
 * @brief 零交越事件
 * 使用於Interleaved PFC 兩臂切換
 *
 */
inline void Zero_Cross_detcet(void)
{
    /*由於沒考慮整流測從Vac源看,如果從RECT下看就省一個判例*/
    if ((ADC_Array[AC_N_CHANNEL] < Zero_Cross_Level) && (ADC_Array[AC_L_CHANNEL] < Zero_Cross_Level))
    {
        /*執行事件*/

        /*輔助臂切換之類*/
    }
}

/**
 * @brief AC 跌落事件當ac消失時
 * 偵測Rect Vac下掉電如果發生則關閉PFC,如果及時復電則不動作
 *
 */
inline void AC_Drop(void)
{
    static uint8_t ac_drop_cnt = 0;

    while ((ADC_Array[AC_N_CHANNEL] < PSU_Bwron_OUT) && (ADC_Array[AC_L_CHANNEL] < PSU_Bwron_OUT))
    {
        ac_drop_cnt++;
        if (ac_drop_cnt > AC_DROP_CNT)
        {
            /*AC Drop Handle close PGI OFF PFC DPWM*/
        }
    }
    /*AC途中復電 PFC繼續工作不關閉PGI*/
    if ((ADC_Array[AC_N_CHANNEL] > PSU_Bwron_IN) && (ADC_Array[AC_L_CHANNEL] > PSU_Bwron_IN))
    {
        ac_drop_cnt = 0;
    }
}
