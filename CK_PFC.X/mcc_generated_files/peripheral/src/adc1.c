/**
  ADC1 Generated Driver Source File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    adc1.c
 
  @Summary
    This is the generated driver source file for ADC1 driver using CCL.
 
  @Description
    This file provides API definitions for ADC1 driver.
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
#include "../adc1.h"

/**
  Section: ADC1 Module APIs
*/

// Set the ADC1 module to the options selected in the user interface.
void ADC1_Initialize(void) {
    // ADON enabled; ADSIDL disabled; CVDEN disabled; 
    ADCON1L = 0x8000;
    // FORM Integer; SHRRES 12-bit resolution; 
    ADCON1H = 0x60;
    // REFCIE disabled; REFERCIE disabled; EIEN disabled; PTGEN disabled; SHREISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; SHRADCS 2; 
    ADCON2L = 0x1;
    // CVDCAP disabled; SHRSAMC 0x0; 
    ADCON2H = 0x0;
    // REFSEL disabled; SUSPEND disabled; SUSPCIE disabled; SHRSAMP disabled; SWLCTRG disabled; SWCTRG disabled; CNVCHSEL AN0; 
    ADCON3L = 0x0;
    // CLKSEL FOSC/2; CLKDIV 1; SHREN disabled; C1EN disabled; C0EN disabled; 
    ADCON3H = 0x0;
    // SAMC1EN disabled; SAMC0EN disabled; 
    ADCON4L = 0x0;
    // C1CHS AN1; C0CHS AN0; 
    ADCON4H = 0x0;
    // DIFF7 disabled; SIGN7 disabled; DIFF6 disabled; SIGN6 disabled; DIFF5 disabled; SIGN5 disabled; DIFF4 disabled; SIGN4 disabled; DIFF3 disabled; SIGN3 disabled; DIFF2 disabled; SIGN2 disabled; DIFF1 disabled; SIGN1 disabled; DIFF0 disabled; SIGN0 disabled; 
    ADMOD0L = 0x0;
    // DIFF15 disabled; SIGN15 disabled; DIFF14 disabled; SIGN14 disabled; DIFF13 disabled; SIGN13 disabled; DIFF12 disabled; SIGN12 disabled; DIFF11 disabled; SIGN11 disabled; DIFF10 disabled; SIGN10 disabled; DIFF9 disabled; SIGN9 disabled; DIFF8 disabled; SIGN8 disabled; 
    ADMOD0H = 0x0;
    // DIFF20 disabled; SIGN20 disabled; DIFF19 disabled; SIGN19 disabled; DIFF18 disabled; SIGN18 disabled; DIFF17 disabled; SIGN17 disabled; DIFF16 disabled; SIGN16 disabled; 
    ADMOD1L = 0x0;
    // IE15 disabled; IE14 disabled; IE13 disabled; IE12 disabled; IE11 disabled; IE10 disabled; IE9 disabled; IE8 disabled; IE7 disabled; IE6 disabled; IE5 disabled; IE4 disabled; IE3 disabled; IE2 disabled; IE1 disabled; IE0 disabled; 
    ADIEL = 0x0;
    // IE20 disabled; IE19 disabled; IE18 disabled; IE17 disabled; IE16 disabled; 
    ADIEH = 0x0;
    // CSS15 disabled; CSS14 disabled; CSS13 disabled; CSS12 disabled; CSS11 disabled; CSS10 disabled; CSS9 disabled; CSS8 disabled; CSS7 disabled; CSS6 disabled; CSS5 disabled; CSS4 disabled; CSS3 disabled; CSS2 disabled; 
    ADCSSL = 0x0;
    // CSS20 disabled; CSS19 disabled; CSS18 disabled; CSS17 disabled; CSS16 disabled; 
    ADCSSH = 0x0;
    // 
    ADSTATL = 0x0;
    // 
    ADSTATH = 0x0;
    // CMPEN15 disabled; CMPEN14 disabled; CMPEN13 disabled; CMPEN12 disabled; CMPEN11 disabled; CMPEN10 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; 
    ADCMP0ENL = 0x0;
    // CMPEN15 disabled; CMPEN14 disabled; CMPEN13 disabled; CMPEN12 disabled; CMPEN11 disabled; CMPEN10 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; 
    ADCMP1ENL = 0x0;
    // CMPEN15 disabled; CMPEN14 disabled; CMPEN13 disabled; CMPEN12 disabled; CMPEN11 disabled; CMPEN10 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; 
    ADCMP2ENL = 0x0;
    // CMPEN15 disabled; CMPEN14 disabled; CMPEN13 disabled; CMPEN12 disabled; CMPEN11 disabled; CMPEN10 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; CMPEN6 disabled; CMPEN5 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; 
    ADCMP3ENL = 0x0;
    // CMPEN20 disabled; CMPEN19 disabled; CMPEN18 disabled; CMPEN17 disabled; CMPEN16 disabled; 
    ADCMP0ENH = 0x0;
    // CMPEN20 disabled; CMPEN19 disabled; CMPEN18 disabled; CMPEN17 disabled; CMPEN16 disabled; 
    ADCMP1ENH = 0x0;
    // CMPEN20 disabled; CMPEN19 disabled; CMPEN18 disabled; CMPEN17 disabled; CMPEN16 disabled; 
    ADCMP2ENH = 0x0;
    // CMPEN20 disabled; CMPEN19 disabled; CMPEN18 disabled; CMPEN17 disabled; CMPEN16 disabled; 
    ADCMP3ENH = 0x0;
    // CMPLO 0x0; 
    ADCMP0LO = 0x0;
    // CMPLO 0x0; 
    ADCMP1LO = 0x0;
    // CMPLO 0x0; 
    ADCMP2LO = 0x0;
    // CMPLO 0x0; 
    ADCMP3LO = 0x0;
    // CMPHI 0x0; 
    ADCMP0HI = 0x0;
    // CMPHI 0x0; 
    ADCMP1HI = 0x0;
    // CMPHI 0x0; 
    ADCMP2HI = 0x0;
    // CMPHI 0x0; 
    ADCMP3HI = 0x0;
    // 
    ADFL0DAT = 0x0;
    // 
    ADFL1DAT = 0x0;
    // 
    ADFL2DAT = 0x0;
    // 
    ADFL3DAT = 0x0;
    // FLEN disabled; MODE Oversampling Mode; OVRSAM 4x; IE disabled; FLCHSEL AN0; 
    ADFL0CON = 0x0;
    // FLEN disabled; MODE Oversampling Mode; OVRSAM 4x; IE disabled; FLCHSEL AN0; 
    ADFL1CON = 0x0;
    // FLEN disabled; MODE Oversampling Mode; OVRSAM 4x; IE disabled; FLCHSEL AN0; 
    ADFL2CON = 0x0;
    // FLEN disabled; MODE Oversampling Mode; OVRSAM 4x; IE disabled; FLCHSEL AN0; 
    ADFL3CON = 0x0;
    // TRGSRC1 None; TRGSRC0 None; 
    ADTRIG0L = 0x0;
    // TRGSRC3 None; TRGSRC2 None; 
    ADTRIG0H = 0x0;
    // TRGSRC5 None; TRGSRC4 None; 
    ADTRIG1L = 0x0;
    // TRGSRC7 None; TRGSRC6 None; 
    ADTRIG1H = 0x0;
    // TRGSRC9 None; TRGSRC8 None; 
    ADTRIG2L = 0x0;
    // TRGSRC11 None; TRGSRC10 None; 
    ADTRIG2H = 0x0;
    // TRGSRC13 None; TRGSRC12 None; 
    ADTRIG3L = 0x0;
    // TRGSRC15 None; TRGSRC14 None; 
    ADTRIG3H = 0x0;
    // TRGSRC17 None; TRGSRC16 None; 
    ADTRIG4L = 0x0;
    // TRGSRC19 None; TRGSRC18 None; 
    ADTRIG4H = 0x0;
    // TRGSRC20 None; 
    ADTRIG5L = 0x0;
    // CMPEN disabled; IE disabled; BTWN disabled; HIHI disabled; HILO disabled; LOHI disabled; LOLO disabled; 
    ADCMP0CON = 0x0;
    // CMPEN disabled; IE disabled; BTWN disabled; HIHI disabled; HILO disabled; LOHI disabled; LOLO disabled; 
    ADCMP1CON = 0x0;
    // CMPEN disabled; IE disabled; BTWN disabled; HIHI disabled; HILO disabled; LOHI disabled; LOLO disabled; 
    ADCMP2CON = 0x0;
    // CMPEN disabled; IE disabled; BTWN disabled; HIHI disabled; HILO disabled; LOHI disabled; LOLO disabled; 
    ADCMP3CON = 0x0;
    // LVLEN15 disabled; LVLEN14 disabled; LVLEN13 disabled; LVLEN12 disabled; LVLEN11 disabled; LVLEN10 disabled; LVLEN9 disabled; LVLEN8 disabled; LVLEN7 disabled; LVLEN6 disabled; LVLEN5 disabled; LVLEN4 disabled; LVLEN3 disabled; LVLEN2 disabled; LVLEN1 disabled; LVLEN0 disabled; 
    ADLVLTRGL = 0x0;
    // LVLEN20 disabled; LVLEN19 disabled; LVLEN18 disabled; LVLEN17 disabled; LVLEN16 disabled; 
    ADLVLTRGH = 0x0;
    // SAMC 0x0; 
    ADCORE0L = 0x0;
    // SAMC 0x0; 
    ADCORE1L = 0x0;
    // EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; RES 12-bit resolution; ADCS 2; 
    ADCORE0H = 0x301;
    // EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; RES 12-bit resolution; ADCS 2; 
    ADCORE1H = 0x301;
    // EIEN15 disabled; EIEN14 disabled; EIEN13 disabled; EIEN12 disabled; EIEN11 disabled; EIEN10 disabled; EIEN9 disabled; EIEN8 disabled; EIEN7 disabled; EIEN6 disabled; EIEN5 disabled; EIEN4 disabled; EIEN3 disabled; EIEN2 disabled; EIEN1 disabled; EIEN0 disabled; 
    ADEIEL = 0x0;
    // EIEN20 disabled; EIEN19 disabled; EIEN18 disabled; EIEN17 disabled; EIEN16 disabled; 
    ADEIEH = 0x0;
    // EISTAT15 disabled; EISTAT14 disabled; EISTAT13 disabled; EISTAT12 disabled; EISTAT11 disabled; EISTAT10 disabled; EISTAT9 disabled; EISTAT8 disabled; EISTAT7 disabled; EISTAT6 disabled; EISTAT5 disabled; EISTAT4 disabled; EISTAT3 disabled; EISTAT2 disabled; EISTAT1 disabled; EISTAT0 disabled; 
    ADEISTATL = 0x0;
    // EISTAT20 disabled; EISTAT19 disabled; EISTAT18 disabled; EISTAT17 disabled; EISTAT16 disabled; 
    ADEISTATH = 0x0;
    // SHRPWR disabled; C1PWR disabled; C0PWR disabled; 
    ADCON5L = 0x0;
    // WARMTIME 16 Source Clock Periods; SHRCIE disabled; C1CIE disabled; C0CIE disabled; 
    ADCON5H = 0x400;
    // 
    ADCBUF0 = 0x0;
    // 
    ADCBUF1 = 0x0;
    // 
    ADCBUF2 = 0x0;
    // 
    ADCBUF3 = 0x0;
    // 
    ADCBUF4 = 0x0;
    // 
    ADCBUF5 = 0x0;
    // 
    ADCBUF6 = 0x0;
    // 
    ADCBUF7 = 0x0;
    // 
    ADCBUF8 = 0x0;
    // 
    ADCBUF9 = 0x0;
    // 
    ADCBUF10 = 0x0;
    // 
    ADCBUF11 = 0x0;
    // 
    ADCBUF12 = 0x0;
    // 
    ADCBUF13 = 0x0;
    // 
    ADCBUF14 = 0x0;
    // 
    ADCBUF15 = 0x0;
    // 
    ADCBUF16 = 0x0;
    // 
    ADCBUF17 = 0x0;
    // 
    ADCBUF18 = 0x0;
    // 
    ADCBUF19 = 0x0;
    // 
    ADCBUF20 = 0x0;

}

