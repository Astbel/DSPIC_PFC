#include "GPIO.h"

GPIO_Pin_Name GPIO_Name;

/*Gerinec  initail GPIO method*/
void GPIO_Init(void)
{
    GPIO_TRIS_4 = 0;
    GPIO_TRIS_5 = 0;
}

/*method delcare*/
void GPIO_Toggle(GPIO_Pin_Name GPIO_Name)
{
    switch (GPIO_Name)
    {
    case PIN_4:
        GPIO_LAT_4 ^= 1; // set as output
        GPIO_TRIS_4 = 0;
        break;
    case PIN_5:
        GPIO_LAT_5 ^= 1; // set as output
        break;
    }
}

void GPIO_ON(GPIO_Pin_Name GPIO_Name)
{
    switch (GPIO_Name)
    {
    case PIN_4:
        GPIO_LAT_4 = 1; // set as output
        GPIO_TRIS_4 = 0;
        break;
    case PIN_5:
        GPIO_LAT_5 = 1; // set as output
        GPIO_TRIS_5 = 0;
        break;
    }
}

void GPIO_OFF(GPIO_Pin_Name GPIO_Name)
{
    switch (GPIO_Name)
    {
    case PIN_4:
        GPIO_LAT_4 = 0; // set as output
        break;
    case PIN_5:
        GPIO_LAT_5 = 0; // set as output
        GPIO_TRIS_5 = 0;
        break;
    }
}
