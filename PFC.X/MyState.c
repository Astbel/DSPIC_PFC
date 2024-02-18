/*引用區*/
#include "MyState.h"
#include "Systemdefine.h"
#include "MyValue.h"
#include "math.h"
// struct enum 聲明
My_STATE my_state;

// Method 聲明

/**
 * @brief AC確認是否在Bwron in 模式
 * 第一皆softstart 緩啟動 Sqart 2 of Vac
 */
void Idle_State_handle(void)
{
    /*等待AC 對Bulk Cap 充電至sqart2的電壓才能致下一個狀態不然會會開機大電流*/
    if ((ADC_Array[VBUS_CHANNEL] > VBulk_Sqrt_2) && (PSON == True))
        my_state = Ramp_UP;
}

/**
 * @brief softstart緩啟動
 * 第二階緩啟動 150ms
 */
void Ramp_up_Handle(void)
{
    /* OVP Task */
    if (ADC_Array[VBUS_CHANNEL] > Over_Volt_Proction)
    {
        my_state = Shut_Down;
    }
    /*2nd SoftStart*/
    _PFC_Class->Vtarget = _PFC_Class->Boost_Softstart + _PFC_Class->Ramp_Step;
    /*Send PGI signal and state change*/
    if (_PFC_Class->Vtarget > PGI_Low_Level)
    {
        /*PGI High*/
        my_state = PFC_ON;
    }
    /*SLaw Rate slow down Ramp Up*/
    /*緩啟動命令-當前電壓小於10V爬升命令開始減速避免overshoot*/
    if (abs((_PFC_Class->Vtarget-ADC_Array[VBUS_CHANNEL]))<SoftStart_Smooth_V)
    {
        _PFC_Class->Ramp_Step >>2;
    }
    else
    {
        /*跟新下一次的softstart電壓達到緩啟動效果*/
        _PFC_Class->Boost_Softstart = _PFC_Class->Vtarget;
    }
}

/**
 * @brief PFC開機等待模式
 * 偵測2次側
 * OVP & Hiccup
 */
void PFC_ON_Handle(void)
{
    /* Hiccup */
    if (ADC_Array[VBUS_CHANNEL] > Hiccup_Volt_level)
    {
        /*確認VBulk是否有回到正常range 如果沒有latch住DPWM */
    }
    /* OVP Task */
    if (ADC_Array[VBUS_CHANNEL] > Over_Volt_Proction)
    {
        /*Shut Down mode*/
    }
}

/**
 * @brief 保護模式
 */
void Shut_Down_Handle(void)
{
    /*關閉DPWM */
}

/**
 * @brief PFC Task 切換
 * 系統狀態執行Task
 * @param state  切換task
 */
void PFC_Task_Handle(My_STATE my_state)
{
    switch (my_state)
    {
    case IDLE:
        Idle_State_handle();
        break;

    case Ramp_UP:
        Ramp_up_Handle();
        break;

    case PFC_ON:
        PFC_ON_Handle();
        break;

    case Shut_Down:
        Shut_Down_Handle();
        break;
    }
}
