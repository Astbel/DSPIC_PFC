/**
  TMR1 Generated Driver Source File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.c

  @Summary
    This is the generated driver source file for TMR1 driver using CCL.

  @Description
    This file provides API definitions for TMR1 driver.
    Generation Information :
        Product Revision  :  CCL
        Driver Revision   :  0.1.0
        Device            :  dsPIC33CK32MP102
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr1.h"

/**
  Section: TMR1 Module APIs
  FCY / PR1 = Frequency
  FCY 是MCU的OSC石英振盪
  假設要1ms發生一次中斷事件
  先假設Dspic Osc 是40Mhz
  那PR1 = 40Mhz/4000  =1000hz
*/

// Set the TMR1 module to the options selected in the user interface.
void TMR1_Initialize(void)
{
  // TON enabled; TSIDL disabled; TMWDIS disabled; TMWIP Write complete; PRWIP Write complete; TECS FOSC; TGATE disabled; TCKPS 1:64; TSYNC disabled; TCS FOSC/2;
  T1CON = 0x8220;
  // TMR 10000;
  TMR1 = 0x2710;
  // PR 10000;
  PR1 = 0x2710;

  IFS0bits.T1IF = 0;
  IEC0bits.T1IE = 1;
}

/*ISR 1 Funtion*/
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
  IFS0bits.T1IF = 0;
}
