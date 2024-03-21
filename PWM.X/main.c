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
  retval &= PWM_Initialize_Generics();
  retval &= DAC_Initialize_Generics();

  /*Enable Generics method*/
  retval &= PWM_Enable_Generics();
  retval &= DAC_Enable_Generics();

  while (1)
  {
      /*BTN switch change DAC simultion slope compsation*/
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
  }
  return 1;
}
/**
 End of File
*/
