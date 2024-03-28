#ifndef GPIO_H
#define GPIO_H

#include <xc.h>
#include <stdbool.h>

/*This file is set from user gpio pins*/

#define PIN_4  1
#define PIN_5  2
#define PIN_6  3

#define GPIO_LAT_4 LATEbits.LATE4
#define GPIO_TRIS_4 TRISEbits.TRISE4

#define GPIO_LAT_5 LATEbits.LATE5
#define GPIO_TRIS_5 TRISEbits.TRISE5

#define GPIO_LAT_6 LATEbits.LATE6
#define GPIO_TRIS_6 TRISEbits.TRISE6


typedef enum
{
    GPIO_4=1,
    GPIO_5,
    GPIO_6,
}GPIO_Pin_Name;

extern GPIO_Pin_Name GPIO_Name;

// 定义 GPIO 的指针类型
typedef struct
{
    volatile unsigned int *port; // 指向端口的指针
    uint8_t pin_mask;            // 用于掩码的位
} GPIO_Pin;

extern GPIO_Pin My_GPIO;


/*public  method prottype */
void GPIO_Toggle(GPIO_Pin_Name GPIO_Name);
void GPIO_ON(GPIO_Pin_Name GPIO_Name);
void GPIO_OFF(GPIO_Pin_Name GPIO_Name);
void GPIO_Init(void);
#endif
