/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/
/* ********************************************************************* *
 * Digital Power Development Board (DM330029) Test Pin Assignment:
 * *********************************************************************
 *
 * Board Overview:
 *
 *         ------------------------------------
 *        |        DIGITAL TEST POINTS         |
 *        |------------------------------------|
 *        |           __________           ----|
 *        |          |__________|         | USB|
 *        |         DP PIM SOCKET          ----|
 *        |                               -----|
 *        |                   RESET O    | ICSP|
 *        |      _   _                    -----|
 *        |   P2|O| |O|P1      USER O          |
 *         ------------------------------------
 *
 * Signal     | Test-Pin              | Comment
 *            | dsPIC33CK | dsPIC33CH |
 * ---------------------------------------------------------------------
 * PWM1H      | TP45      | TP35      | PWM Generator #1 output HIGH
 * PWM1L      | TP47      | TP38      | PWM Generator #1 output LOW
 *            |           |           |
 * PWM2H      | TP42      | TP25      | PWM Generator #2 output HIGH
 * PWM2L      | TP40      | TP27  (2) | PWM Generator #2 output LOW
 *            |           |           |
 * PWM3H      | TP37      | TP36      | PWM Generator #3 output HIGH
 * PWM3L      | TP41      | TP34      | PWM Generator #3 output LOW
 *            |           |           |
 * PWM4H      | TP43      | TP46      | PWM Generator #4 output HIGH
 * PWM4L      | TP44      | TP48      | PWM Generator #4 output LOW
 *            |           |           |
 * PWM5H      | TP35      | (n/a) (3) | PWM Generator #5 output HIGH
 * PWM5L      | TP38      | (n/a) (3) | PWM Generator #5 output LOW
 *            |           |           |
 * PWM6H      | TP31      | (n/a) (3) | PWM Generator #6 output HIGH
 * PWM6L      | TP33      | (n/a) (3) | PWM Generator #6 output LOW
 *            |           |           |
 * PWM7H      | TP25      | (n/a) (3) | PWM Generator #7 output HIGH
 * PWM7L      | TP27 (1)  | (n/a) (3) | PWM Generator #7 output LOW
 *            |           |           |
 * PWM8H      | TP46      | (n/a) (3) | PWM Generator #8 output HIGH
 * PWM8L      | TP48      | (n/a) (3) | PWM Generator #8 output LOW
 * ---------------------------------------------------------------------
/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pwm.h"
#include "sources/Gdac.h"
#include "sources/Gpwm.h"
#include "sources/config/demo.h"
/*
                         Main application
 */
int main(void)
{
  /*inital for Generics method*/
  volatile uint16_t retval = True; // Local function return verification variable
  volatile uint8_t test_value = 1;
  /*BTN PIN*/
  //  BUTTON_S1_TRIS = 1;
  // initialize the device
  SYSTEM_Initialize();

  /* Generics of  pwm and dac*/
//  retval &= PWM_Initialize_Generics();
  // retval &= DAC_Initialize_Generics();

  /*Enable Generics method*/
  // retval &= PWM_Enable_Generics();
  // retval &= DAC_Enable_Generics();

  while (1)
  {
/*BTN switch change DAC simultion slope compsation*/
#if (Test_Dac_Slopee_Comp == True)
    if (check_SW2_Press() == True)
    {
      switch (test_value)
      {
      case 1:
        my_dac->DACxDATH.value = DACOUT_VALUE_HIGH_2; // Decrease the DAC Lower value to increase the Slope rate
        my_dac->SLPxDAT.value = SLP_SLEW_RATE_2;      // DAC slope rate is set to 400mV/uS
        test_value = 2;
        break;

      default:
        my_dac->SLPxDAT.value = SLP_SLEW_RATE_1;      // DAC slope rate is set to 200mV/uS
        my_dac->DACxDATH.value = DACOUT_VALUE_HIGH_1; // Decrease the DAC Lower value to increase the Slope rate
        test_value = 1;
        break;
      }
    }
#endif
  }
  return 1;
}
/**
 End of File
*/
