#ifndef GPIO_H
#define GPIO_H

#include <xc.h>
#include <stdbool.h>

/*This file is set from user gpio pins*/

#define GPIO_LAT LATEbits.LATE5
#define GPIO_TRIS TRISEbits.TRISE5

/*public  method prottype */
void GPIO_Toggle(void);
void GPIO_ON(void);
void GPIO_OFF(void);




#endif
