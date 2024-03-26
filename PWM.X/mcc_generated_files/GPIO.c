#include "GPIO.h"


/*method delcare*/
void GPIO_Toggle(void)
{
    GPIO_LAT ^= 1; // set as output
    GPIO_TRIS = 0;
}

void GPIO_ON(void)
{
    GPIO_TRIS = 0;
    GPIO_LAT = 1;
}

void GPIO_OFF(void)
{
    GPIO_TRIS = 0;
    GPIO_LAT = 0;
}

