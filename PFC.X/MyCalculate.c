/*include path*/
#include "MyCalculate.h"
#include "MyValue.h"
#include "MyState.h"

/*variable delcare for public*/
uint8_t AC_Drop_Event;
uint8_t ac_drop_cnt;
uint8_t hold_up_time_cnt;
uint32_t ac_sum;
/*variable delcare for pravite*/
/*ptr 建立*/
/*pravite mehtod delcare*/

/**
 * @brief
 * 移動平均計算Vac電壓 & Vac Peak & Zero Cross
 *
 *
 */
// void Moving_AVG(uint8_t new_point, uint32_t Array[Moving_Sample_Rate], uint8_t *index)
// {
//     sum -= Array[*index];      // 減去舊的節點
//     sum += new_point;          // 新的節點
//     Array[*index] = new_point; // 跟新儲存點

//     // 跟新index數組
//     *index = (*index + 1) % Moving_Sample_Rate;

//     // 檢查是否為峰值
//     if (new_point > Array[(*index - 1) % Moving_Sample_Rate] && new_point > Array[(*index + 1) % Moving_Sample_Rate])
//     {
//         _AC_CLass->AC_PEAK = new_point;
//     }
//     // 平均值
//     _AC_CLass->AC_Instance = sum / Moving_Sample_Rate;

//     // 零交越事件檢測考慮誤差5%
//     if (_AC_CLass->AC_Instance < Zero_Cross_Level)
//         Zero_Cross_detcet();
// }

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

/**
 * @brief
 * PSU Bwron out 功能
 * Vac低於特定電壓關閉PFC
 */
void Bwron_Out_Method(void)
{
    // if (_AC_CLass->AC_PEAK <= PSU_Bwron_OUT)
    // {
    //     _AC_CLass->AC_Bwron_Out_Cnt++;
    //     if (_AC_CLass->AC_Bwron_Out_Cnt >=Bwron_Out_CNT)
    //     {
    //          /*Freeze calculate duty disable DPWM Off PGI*/
    //     }
    // }
}

