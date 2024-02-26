#ifndef __MYCONTROL_H_
#define __MYCONTROL_H_

#include "Systemdefine.h"

// 變數名稱
#define Orders 3

// Iref 限制間接限制I Limit
#define Iref_Limit_Max 4096
#define Iref_Limit_Min 0
// DPWM limit 暫定解析度
#define DPWM_MAX 4096
#define DPWM_MIN 0
// PID I 積分飽和定義
#define Intergal_MAX 1000
#define Intergal_MIN 0
// 結構體申明區

typedef struct
{
    float KM_90Vac;
    float KM_115Vac;
    float KM_230Vac;
    float KM_264Vac;
} Gain;

// PID class
typedef struct
{
    float Kp;
    float Ki;
    float Kd;
    float Kp_out;
    float Ki_out;
    float Kd_out;
    float Out;
} PID;

// 補償器 class
typedef struct
{
    float Xn[Orders];
    float Yn[Orders];
    float An[Orders];
    float Bn[Orders];
} Type_Compesation;

// struct class object建立
extern PID Voltage_Loop_PID;
extern Type_Compesation Voltage_Loop_2P2Z;

// 擴充方法區
void MyControl_Inital(void);
int32 Voltage_Loop_PI(uint16_t err);
int32 Voltage_Loop_Type(uint16_t err);
uint32_t Current_Loop_PI(uint32_t err);
uint32_t Current_Loop_Type(uint16_t err);
uint32_t Voltage_Feed_Forward(int32 Boost_Target, Gain my_gain);

#endif
