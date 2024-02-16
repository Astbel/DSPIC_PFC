/*include path*/
#include "MyCalculate.h"
#include "MyValue.h"
#include "MyState.h"

/*variable delcare for public*/
uint8_t AC_Drop_Event;
/*variable delcare for pravite*/

/*pravite mehtod delcare*/

/**
 * @brief
 *
 */
void Moving_AVG(void)
{
}

/**
 * @brief 零交越事件
 * 使用於Interleaved PFC 兩臂切換
 *
 */
void Zero_Cross_detcet(void)
{
    /*由於沒考慮整流測從Vac源看,如果從RECT下看就省一個判例*/
    if ((ADC_Array[AC_N_CHANNEL] < Zero_Cross_Level) && (ADC_Array[AC_L_CHANNEL] < Zero_Cross_Level))
    {
        /*blanktime旗標這時候master & slaver 臂都不能啟用*/

        /*輔助臂切換之類*/
    }
}

/**
 * @brief AC 跌落事件當ac消失時
 * 偵測Rect Vac下掉電如果發生則關閉PFC,如果及時復電則不動作
 *
 */
void AC_Drop(void)
{
    static uint8_t ac_drop_cnt = 0;

    while ((ADC_Array[AC_N_CHANNEL] < PSU_Bwron_OUT) && (ADC_Array[AC_L_CHANNEL] < PSU_Bwron_OUT))
    {
        ac_drop_cnt++;
        if (ac_drop_cnt > AC_DROP_CNT)
        {
            /*AC Drop Handle PFC DPWM & Freeze up duty cal*/
            AC_Drop_Event = True;
            my_state = Shut_Down;
        }
    }
    /*AC不穩定有斷續的狀況*/

    /*AC途中復電 PFC繼續工作不關閉PGI*/
    if ((ADC_Array[AC_N_CHANNEL] > PSU_Bwron_IN) && (ADC_Array[AC_L_CHANNEL] > PSU_Bwron_IN))
    {
        ac_drop_cnt = 0;
    }
}

/**
 * @brief
 * PSU 關機時序
 *
 * AC 消失和PSOFF都會發生
 */
void Hold_Up_Time_Method(void)
{
    static uint8_t hold_up_time_cnt = 0;

    if ((AC_Drop_Event == True) || (PSON == False))
    {
        hold_up_time_cnt++;
        if (hold_up_time_cnt >= Hold_Up_Time)
        {
            /*Freeze cal duty*/

            /*Off DPWM*/

            /*PGI off */
        }
    }
}
