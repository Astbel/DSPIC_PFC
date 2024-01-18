#ifndef __MYCONTROL_H_
#define __MYCONTROL_H_

// 變數名稱
#define Orders 3

// DPWM limit 暫定解析度
#define DPWM_MAX 4096
#define DPWM_MIN 0
// PID I 積分飽和定義
#define Intergal_MAX 1000
#define Intergal_MIN 0
// 結構體申明區

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
inline int32 Voltage_Loop_PI(uint16_t err);
inline int32 Voltage_Loop_Type(uint16_t err);

#endif