/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   Firmware Driver Version 1.0.2
 *
 * @skipline @version   PLIB Version 1.3.0
 *
 * @skipline  Device : dsPIC33CK32MP102
*/

/*
? [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of IO_RA0 to High
 * @pre      The RA0 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetHigh()          (_LATA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of IO_RA0 to Low
 * @pre      The RA0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetLow()           (_LATA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA0 GPIO Pin which has a custom name of IO_RA0
 * @pre      The RA0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA0_Toggle()           (_LATA0 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA0 GPIO Pin which has a custom name of IO_RA0
 * @param    none
 * @return   none  
 */
#define IO_RA0_GetValue()         _RA0

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of IO_RA0 as Input
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetDigitalInput()  (_TRISA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of IO_RA0 as Output
 * @param    none
 * @return   none  
 */
#define IO_RA0_SetDigitalOutput() (_TRISA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA4 GPIO Pin which has a custom name of IO_RA4 to High
 * @pre      The RA4 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RA4_SetHigh()          (_LATA4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA4 GPIO Pin which has a custom name of IO_RA4 to Low
 * @pre      The RA4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA4_SetLow()           (_LATA4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA4 GPIO Pin which has a custom name of IO_RA4
 * @pre      The RA4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA4_Toggle()           (_LATA4 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA4 GPIO Pin which has a custom name of IO_RA4
 * @param    none
 * @return   none  
 */
#define IO_RA4_GetValue()         _RA4

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA4 GPIO Pin which has a custom name of IO_RA4 as Input
 * @param    none
 * @return   none  
 */
#define IO_RA4_SetDigitalInput()  (_TRISA4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA4 GPIO Pin which has a custom name of IO_RA4 as Output
 * @param    none
 * @return   none  
 */
#define IO_RA4_SetDigitalOutput() (_TRISA4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB2 GPIO Pin which has a custom name of IO_RB2 to High
 * @pre      The RB2 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetHigh()          (_LATB2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB2 GPIO Pin which has a custom name of IO_RB2 to Low
 * @pre      The RB2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetLow()           (_LATB2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB2 GPIO Pin which has a custom name of IO_RB2
 * @pre      The RB2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB2_Toggle()           (_LATB2 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB2 GPIO Pin which has a custom name of IO_RB2
 * @param    none
 * @return   none  
 */
#define IO_RB2_GetValue()         _RB2

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB2 GPIO Pin which has a custom name of IO_RB2 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetDigitalInput()  (_TRISB2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB2 GPIO Pin which has a custom name of IO_RB2 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetDigitalOutput() (_TRISB2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB12 GPIO Pin which has a custom name of IO_RB12 to High
 * @pre      The RB12 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB12_SetHigh()          (_LATB12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB12 GPIO Pin which has a custom name of IO_RB12 to Low
 * @pre      The RB12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB12_SetLow()           (_LATB12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB12 GPIO Pin which has a custom name of IO_RB12
 * @pre      The RB12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB12_Toggle()           (_LATB12 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB12 GPIO Pin which has a custom name of IO_RB12
 * @param    none
 * @return   none  
 */
#define IO_RB12_GetValue()         _RB12

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB12 GPIO Pin which has a custom name of IO_RB12 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB12_SetDigitalInput()  (_TRISB12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB12 GPIO Pin which has a custom name of IO_RB12 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB12_SetDigitalOutput() (_TRISB12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB14 GPIO Pin which has a custom name of IO_RB14 to High
 * @pre      The RB14 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB14_SetHigh()          (_LATB14 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB14 GPIO Pin which has a custom name of IO_RB14 to Low
 * @pre      The RB14 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB14_SetLow()           (_LATB14 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB14 GPIO Pin which has a custom name of IO_RB14
 * @pre      The RB14 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB14_Toggle()           (_LATB14 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB14 GPIO Pin which has a custom name of IO_RB14
 * @param    none
 * @return   none  
 */
#define IO_RB14_GetValue()         _RB14

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB14 GPIO Pin which has a custom name of IO_RB14 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB14_SetDigitalInput()  (_TRISB14 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB14 GPIO Pin which has a custom name of IO_RB14 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB14_SetDigitalOutput() (_TRISB14 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
