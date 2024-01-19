// 標頭黨
#include "MyControl.h"

// 結構體 物件並初始化 電壓環,電流環
PID Voltage_Loop_PID = {0, 0, 0, 0, 0, 0, 0};
PID Current_Loop_PID = {0, 0, 0, 0, 0, 0, 0};
Gain Loop_Gain = {0, 0, 0, 0};
Type_Compesation Voltage_Loop_2P2Z = {{0}, {0}, {0}, {0}};
Type_Compesation Current_Loop_2P2Z = {{0}, {0}, {0}, {0}};

// 物件指標建立,只用指標傳遞struct內的值可以節省時間如直接回傳struct會要複製所有的副本
PID *_Volt_PID;
PID *_Curr_PID;
Gain *_Loop_Gain;
Type_Compesation *_Volt_2P2Z;
Type_Compesation *_Curr_2P2Z;
// 初始化用
void MyControl_Inital(void)
{
    _Volt_PID = &Voltage_Loop_PID;
    _Curr_PID = &Current_Loop_PID;
    _Volt_2P2Z = &Voltage_Loop_2P2Z;
    _Curr_2P2Z = &Current_Loop_2P2Z;
    _Loop_Gain = &Loop_Gain;
}

/**電壓環**/
/**
 * @brief 古典控制
 * 電壓環 PI版本 這裡需要新增換檔機制
 * output Iref PFC而言
 * @param err 目標與當前的誤差量
 */
inline int32 Voltage_Loop_PI(uint16_t err)
{
    int32 output;

    /*定義穩態誤差*/
    uint16_t steady_error = err;

    // Kp
    _Volt_PID->Kp_out = _Volt_PID->Kp * err;
    // Ki
    _Volt_PID->Ki_out = 0 + _Volt_PID->Ki * err;
    // 積分遇限削弱 要修正個人覺得思路不對
    if ((err > 0) && (_Volt_PID->Kp < 0))
        _Volt_PID->Ki_out = 0;

    else if ((err < 0) && (_Volt_PID->Kp > 0))
        _Volt_PID->Ki_out = 0;

    // 積分上下飽和限制
    if (_Volt_PID->Ki_out > Intergal_MAX)
        _Volt_PID->Ki_out = Intergal_MAX;

    else if (_Volt_PID->Ki_out < Intergal_MIN)
        _Volt_PID->Ki_out = Intergal_MIN;

    // PI 輸出
    _Volt_PID->Out = _Volt_PID->Kp_out + _Volt_PID->Ki_out;
    /*DPWM 輸出限制檢測*/
    if (_Volt_PID->Out > Iref_Limit_Max)
        _Volt_PID->Out = Iref_Limit_Max;
    else if (_Volt_PID->Out < Iref_Limit_Min)
        _Volt_PID->Out = Iref_Limit_Min;

    output = _Volt_PID->Out;

    return output;
}

/**
 * @brief POLE ZERO CANCEL
 * 電壓環 Type補償器版本
 * Xn 輸入
 * Yn 輸出
 * output Iref PFC而言
 * @param err 目標與當前的誤差量
 */
inline int32 Voltage_Loop_Type(uint16_t err)
{
    int32 output;
    /*差分方呈*/
    Voltage_Loop_2P2Z.Xn[0] = err;

    Voltage_Loop_2P2Z.Yn[0] = Voltage_Loop_2P2Z.Bn[3] * Voltage_Loop_2P2Z.Xn[3] +
                              Voltage_Loop_2P2Z.Bn[2] * Voltage_Loop_2P2Z.Xn[2] +
                              Voltage_Loop_2P2Z.Bn[1] * Voltage_Loop_2P2Z.Xn[1] +
                              Voltage_Loop_2P2Z.Bn[0] * Voltage_Loop_2P2Z.Xn[0] +
                              Voltage_Loop_2P2Z.An[3] * Voltage_Loop_2P2Z.Yn[3] +
                              Voltage_Loop_2P2Z.An[2] * Voltage_Loop_2P2Z.Yn[2] +
                              Voltage_Loop_2P2Z.An[1] * Voltage_Loop_2P2Z.Yn[1];
    /*iteration 紀錄上一筆*/
    for (int8_t i = Orders; i > 0; i--)
    {
        Voltage_Loop_2P2Z.Xn[i] = Voltage_Loop_2P2Z.Xn[i - 1];
        Voltage_Loop_2P2Z.Yn[i] = Voltage_Loop_2P2Z.Yn[i - 1];
    }

    /*限制輸出*/
    if (Voltage_Loop_2P2Z.Yn[0] > DPWM_MAX)
        Voltage_Loop_2P2Z.Yn[0] = DPWM_MAX;

    else if (Voltage_Loop_2P2Z.Yn[0] < DPWM_MIN)
        Voltage_Loop_2P2Z.Yn[0] = DPWM_MIN;

    output = Voltage_Loop_2P2Z.Yn[0];

    return output;
}

/*電流環*/
/**
 * @brief 古典控制
 * 電流環 PI版本 Iref這裡需要先經過VFF
 * @param err Iref & Ind的差距
 * @return uint32_t DPWM的duty
 */
inline uint32_t Current_Loop_PI(uint32_t err)
{
    uint32_t output;

    // Kp
    _Curr_PID->Kp_out = _Curr_PID->Kp * err;
    // Ki
    _Curr_PID->Ki_out = 0 + _Curr_PID->Ki * err;
    // 積分遇限削弱 要修正個人覺得思路不對
    if ((err > 0) && (_Curr_PID->Kp < 0))
        _Curr_PID->Ki_out = 0;

    else if ((err < 0) && (_Curr_PID->Kp > 0))
        _Curr_PID->Ki_out = 0;

    // 積分上下飽和限制
    if (_Curr_PID->Ki_out > Intergal_MAX)
        _Curr_PID->Ki_out = Intergal_MAX;

    else if (_Curr_PID->Ki_out < Intergal_MIN)
        _Curr_PID->Ki_out = Intergal_MIN;

    // PI 輸出
    _Curr_PID->Out = _Curr_PID->Kp_out + _Curr_PID->Ki_out;
    /*DPWM 輸出限制檢測*/
    if (_Curr_PID->Out > DPWM_MAX)
        _Curr_PID->Out = DPWM_MAX;
    else if (_Curr_PID->Out < DPWM_MIN)
        _Curr_PID->Out = DPWM_MIN;

    /*DPWM輸出*/
    output = _Curr_PID->Out;

    return output
}
/**
 * @brief POLE ZERO CANCEL
 * 電流環 Type補償器版本
 * Xn 輸入
 * Yn 輸出
 * @param err Iref & Ind的差距
 * @return uint32_t DPWM的duty
 */
inline uint32_t Current_Loop_Type(uint16_t err)
{
    uint32_t output;
    /*差分方呈*/
    Current_Loop_2P2Z.Xn[0] = err;

    Current_Loop_2P2Z.Yn[0] = Current_Loop_2P2Z.Bn[3] * Current_Loop_2P2Z.Xn[3] +
                              Current_Loop_2P2Z.Bn[2] * Current_Loop_2P2Z.Xn[2] +
                              Current_Loop_2P2Z.Bn[1] * Current_Loop_2P2Z.Xn[1] +
                              Current_Loop_2P2Z.Bn[0] * Current_Loop_2P2Z.Xn[0] +
                              Current_Loop_2P2Z.An[3] * Current_Loop_2P2Z.Yn[3] +
                              Current_Loop_2P2Z.An[2] * Current_Loop_2P2Z.Yn[2] +
                              Current_Loop_2P2Z.An[1] * Current_Loop_2P2Z.Yn[1];
    /*iteration 紀錄上一筆*/
    for (int8_t i = Orders; i > 0; i--)
    {
        Current_Loop_2P2Z.Xn[i] = Current_Loop_2P2Z.Xn[i - 1];
        Current_Loop_2P2Z.Yn[i] = Current_Loop_2P2Z.Yn[i - 1];
    }

    /*限制輸出*/
    if (Current_Loop_2P2Z.Yn[0] > DPWM_MAX)
        Current_Loop_2P2Z.Yn[0] = DPWM_MAX;

    else if (Current_Loop_2P2Z.Yn[0] < DPWM_MIN)
        Current_Loop_2P2Z.Yn[0] = DPWM_MIN;

    output = Current_Loop_2P2Z.Yn[0];

    return output;
}
/**
 * @brief 前饋控制 boost 在直流電取交流信號
 *        整流信號 取樣
 * @param Boost_Target 電壓環輸出
 * @Gain  my_gain AC交流增益
 * @return uint32_t  Iref
 */
inline uint32_t Voltage_Feed_Forward(int32 Boost_Target,Gain my_gain)
{
    /*Iref*/
    /*KM Gain 交流信號倍率 整留下取樣*/
    /* 1/Vrms^2,暫定90Vac下的AC增益,這裡欠缺AC ADC 取樣 */
    Iref = my_gain.KM_90Vac*Boost_Target;

    return Iref;
}
