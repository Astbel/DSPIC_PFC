#ifndef GPIO_H
#define GPIO_H

#include <xc.h>

/*This file is set from user gpio pins*/

#define GPIO_LAT  LATEbits.LATE5
#define GPIO_TRIS TRISEbits.TRISE5

 void GPIO_Toggle(void);

 void GPIO_Toggle(void)
{
    GPIO_LAT ^= 1; // set as output
    GPIO_TRIS  =0;
}


#endif
