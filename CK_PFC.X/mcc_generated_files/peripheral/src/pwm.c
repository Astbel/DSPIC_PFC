/**
  PWM Generated Driver Source File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    pwm.c
 
  @Summary
    This is the generated driver source file for PWM driver using CCL.
 
  @Description
    This file provides API definitions for PWM driver.
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
#include "../pwm.h"

/**
  Section: PWM Module APIs
*/

// Set the PWM module to the options selected in the user interface.
void PWM_Initialize(void) {
    // HRERR enabled; LOCK disabled; DIVSEL 1:2; MCLKSEL AFPLLO; 
    PCLKCON = 0xC003;
    // FSCL 1000; 
    FSCL = 0x3E8;
    // FSMINPER 1000; 
    FSMINPER = 0x3E8;
    // MPHASE 0x0; 
    MPHASE = 0x0;
    // MDC 0x0; 
    MDC = 0x0;
    // MPER 0x0; 
    MPER = 0x0;
    // LFSR 0x0; 
    LFSR = 0x0;
    // CTA4EN disabled; CTA3EN disabled; CTA2EN disabled; CTA1EN disabled; 
    CMBTRIGL = 0x0;
    // CTB4EN disabled; CTB3EN disabled; CTB2EN disabled; CTB1EN disabled; 
    CMBTRIGH = 0x0;
    // PWMS1A PWM1H; PWMS2A PWM1H; S1APOL Positive logic; S2APOL Positive logic; PWMLFA PWMS1 or PWMS2;; PWMLFAD No Assignment; 
    LOGCONA = 0x0;
    // PWMS1B PWM1H; PWMS2B PWM1H; S1BPOL Positive logic; S2BPOL Positive logic; PWMLFB PWMS1 | PWMS2; PWMLFBD No Assignment; 
    LOGCONB = 0x0;
    // PWMS1C PWM1H; PWMS2C PWM1H; S1CPOL Positive logic; S2CPOL Positive logic; PWMLFC PWMS1 | PWMS2; PWMLFCD No Assignment; 
    LOGCONC = 0x0;
    // PWMS1D PWM1H; PWMS2D PWM1H; S1DPOL Positive logic; S2DPOL Positive logic; PWMLFD PWMS1 | PWMS2; PWMLFDD No Assignment; 
    LOGCOND = 0x0;
    // PWMS1E PWM1H; PWMS2E PWM1H; S1EPOL Positive logic; S2EPOL Positive logic; PWMLFE PWMS1 | PWMS2; PWMLFED No Assignment; 
    LOGCONE = 0x0;
    // PWMS1F PWM1H; PWMS2F PWM1H; S1FPOL Positive logic; S2FPOL Positive logic; PWMLFF PWMS1 | PWMS2; PWMLFFD No Assignment; 
    LOGCONF = 0x0;
    // EVT1OEN disabled; EVTAPOL Active-high; EVTASTRD Stretched to 8 PWM clock cycles minimum; EVTASYNC Not synchronized; EVTASEL PGTRGSEL bits; EVTAPGS PG1; 
    PWMEVTA = 0x0;
    // EVT2OEN disabled; EVTBPOL Active-high; EVTBSTRD Stretched to 8 PWM clock cycles minimum; EVTBSYNC Not synchronized; EVTBSEL PGTRGSEL bits; EVTBPGS PG1; 
    PWMEVTB = 0x0;
    // EVT3OEN disabled; EVTCPOL Active-high; EVTCSTRD Stretched to 8 PWM clock cycles minimum; EVTCSYNC Not synchronized; EVTCSEL PGTRGSEL bits; EVTCPGS PG1; 
    PWMEVTC = 0x0;
    // EVT4OEN disabled; EVTDPOL Active-high; EVTDSTRD Stretched to 8 PWM clock cycles minimum; EVTDSYNC Not synchronized; EVTDSEL PGTRGSEL bits; EVTDPGS PG1; 
    PWMEVTD = 0x0;
    // EVT5OEN disabled; EVTEPOL Active-high; EVTESTRD Stretched to 8 PWM clock cycles minimum; EVTESYNC Not synchronized; EVTESEL PGTRGSEL bits; EVTEPGS PG1; 
    PWMEVTE = 0x0;
    // EVT6OEN disabled; EVTFPOL Active-high; EVTFSTRD Stretched to 8 PWM clock cycles minimum; EVTFSYNC Not synchronized; EVTFSEL PGTRGSEL bits; EVTFPGS PG1; 
    PWMEVTF = 0x0;
    // ON disabled; TRGCNT 1; HREN disabled; CLKSEL no clock; MODSEL Independent Edge; 
    PG1CONL = 0x0;
    // ON disabled; TRGCNT 1; HREN disabled; CLKSEL no clock; MODSEL Independent Edge; 
    PG2CONL = 0x0;
    // ON disabled; TRGCNT 1; HREN disabled; CLKSEL no clock; MODSEL Independent Edge; 
    PG3CONL = 0x0;
    // ON disabled; TRGCNT 1; HREN disabled; CLKSEL no clock; MODSEL Independent Edge; 
    PG4CONL = 0x0;
    // MDCSEL disabled; MPERSEL disabled; MPHSEL disabled; MSTEN disabled; UPDMOD SOC update; TRIGMOD Single trigger mode; SOCS Self-trigger; 
    PG1CONH = 0x0;
    // MDCSEL disabled; MPERSEL disabled; MPHSEL disabled; MSTEN disabled; UPDMOD SOC update; TRIGMOD Single trigger mode; SOCS Self-trigger; 
    PG2CONH = 0x0;
    // MDCSEL disabled; MPERSEL disabled; MPHSEL disabled; MSTEN disabled; UPDMOD SOC update; TRIGMOD Single trigger mode; SOCS Self-trigger; 
    PG3CONH = 0x0;
    // MDCSEL disabled; MPERSEL disabled; MPHSEL disabled; MSTEN disabled; UPDMOD SOC update; TRIGMOD Single trigger mode; SOCS Self-trigger; 
    PG4CONH = 0x0;
    // SEVT disabled; FLTEVT disabled; CLEVT disabled; FFEVT disabled; TRSET disabled; TRCLR disabled; CAP disabled; UPDATE disabled; UPDREQ disabled; 
    PG1STAT = 0x0;
    // SEVT disabled; FLTEVT disabled; CLEVT disabled; FFEVT disabled; TRSET disabled; TRCLR disabled; CAP disabled; UPDATE disabled; UPDREQ disabled; 
    PG2STAT = 0x0;
    // SEVT disabled; FLTEVT disabled; CLEVT disabled; FFEVT disabled; TRSET disabled; TRCLR disabled; CAP disabled; UPDATE disabled; UPDREQ disabled; 
    PG3STAT = 0x0;
    // SEVT disabled; FLTEVT disabled; CLEVT disabled; FFEVT disabled; TRSET disabled; TRCLR disabled; CAP disabled; UPDATE disabled; UPDREQ disabled; 
    PG4STAT = 0x0;
    // CLMOD disabled; SWAP disabled; OVRENH disabled; OVRENL disabled; OVRDAT 0x0; OSYNC User output overrides are synchronized to the local PWM time base; FLTDAT 0x0; CLDAT 0x0; FFDAT 0x0; DBDAT 0x0; 
    PG1IOCONL = 0x0;
    // CLMOD disabled; SWAP disabled; OVRENH disabled; OVRENL disabled; OVRDAT 0x0; OSYNC User output overrides are synchronized to the local PWM time base; FLTDAT 0x0; CLDAT 0x0; FFDAT 0x0; DBDAT 0x0; 
    PG2IOCONL = 0x0;
    // CLMOD disabled; SWAP disabled; OVRENH disabled; OVRENL disabled; OVRDAT 0x0; OSYNC User output overrides are synchronized to the local PWM time base; FLTDAT 0x0; CLDAT 0x0; FFDAT 0x0; DBDAT 0x0; 
    PG3IOCONL = 0x0;
    // CLMOD disabled; SWAP disabled; OVRENH disabled; OVRENL disabled; OVRDAT 0x0; OSYNC User output overrides are synchronized to the local PWM time base; FLTDAT 0x0; CLDAT 0x0; FFDAT 0x0; DBDAT 0x0; 
    PG4IOCONL = 0x0;
    // CAPSRC Software; DTCMPSEL PCI Sync Logic; PMOD Complementary; PENH disabled; PENL disabled; POLH Active-high; POLL Active-high; 
    PG1IOCONH = 0x0;
    // CAPSRC Software; DTCMPSEL PCI Sync Logic; PMOD Complementary; PENH disabled; PENL disabled; POLH Active-high; POLL Active-high; 
    PG2IOCONH = 0x0;
    // CAPSRC Software; DTCMPSEL PCI Sync Logic; PMOD Complementary; PENH disabled; PENL disabled; POLH Active-high; POLL Active-high; 
    PG3IOCONH = 0x0;
    // CAPSRC Software; DTCMPSEL PCI Sync Logic; PMOD Complementary; PENH disabled; PENL disabled; POLH Active-high; POLL Active-high; 
    PG4IOCONH = 0x0;
    // ADTR1PS 1:1; ADTR1EN3 disabled; ADTR1EN2 disabled; ADTR1EN1 disabled; UPDTRG Manual; PGTRGSEL EOC event; 
    PG1EVTL = 0x0;
    // ADTR1PS 1:1; ADTR1EN3 disabled; ADTR1EN2 disabled; ADTR1EN1 disabled; UPDTRG Manual; PGTRGSEL EOC event; 
    PG2EVTL = 0x0;
    // ADTR1PS 1:1; ADTR1EN3 disabled; ADTR1EN2 disabled; ADTR1EN1 disabled; UPDTRG Manual; PGTRGSEL EOC event; 
    PG3EVTL = 0x0;
    // ADTR1PS 1:1; ADTR1EN3 disabled; ADTR1EN2 disabled; ADTR1EN1 disabled; UPDTRG Manual; PGTRGSEL EOC event; 
    PG4EVTL = 0x0;
    // FLTIEN disabled; CLIEN disabled; FFIEN disabled; SIEN disabled; IEVTSEL EOC; ADTR2EN3 disabled; ADTR2EN2 disabled; ADTR2EN1 disabled; ADTR1OFS None; 
    PG1EVTH = 0x0;
    // FLTIEN disabled; CLIEN disabled; FFIEN disabled; SIEN disabled; IEVTSEL EOC; ADTR2EN3 disabled; ADTR2EN2 disabled; ADTR2EN1 disabled; ADTR1OFS None; 
    PG2EVTH = 0x0;
    // FLTIEN disabled; CLIEN disabled; FFIEN disabled; SIEN disabled; IEVTSEL EOC; ADTR2EN3 disabled; ADTR2EN2 disabled; ADTR2EN1 disabled; ADTR1OFS None; 
    PG3EVTH = 0x0;
    // FLTIEN disabled; CLIEN disabled; FFIEN disabled; SIEN disabled; IEVTSEL EOC; ADTR2EN3 disabled; ADTR2EN2 disabled; ADTR2EN1 disabled; ADTR1OFS None; 
    PG4EVTH = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG1FPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG2FPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG3FPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG4FPCIL = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; LATMOD disabled; TQPS Not inverted; TQSS None; 
    PG1FPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; LATMOD disabled; TQPS Not inverted; TQSS None; 
    PG2FPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; LATMOD disabled; TQPS Not inverted; TQSS None; 
    PG3FPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; LATMOD disabled; TQPS Not inverted; TQSS None; 
    PG4FPCIH = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG1CLPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG2CLPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG3CLPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG4CLPCIL = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG1CLPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG2CLPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG3CLPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG4CLPCIH = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG1FFPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG2FFPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG3FFPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG4FFPCIL = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG1FFPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG2FFPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG3FFPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG4FFPCIH = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG1SPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG2SPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG3SPCIL = 0x0;
    // TSYNCDIS PWM EOC; TERM Manual Terminate; AQPS Not inverted; AQSS None; SWTERM disabled; PSYNC disabled; PPS Not inverted; PSS Tied to 0; 
    PG4SPCIL = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG1SPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG2SPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG3SPCIH = 0x0;
    // BPEN disabled; BPSEL PWM Generator 1; ACP Level-sensitive; SWPCI Drives '0'; SWPCIM PCI acceptance logic; PCIGT disabled; TQPS Not inverted; TQSS None; 
    PG4SPCIH = 0x0;
    // LEB 0x0; 
    PG1LEBL = 0x0;
    // LEB 0x0; 
    PG2LEBL = 0x0;
    // LEB 0x0; 
    PG3LEBL = 0x0;
    // LEB 0x0; 
    PG4LEBL = 0x0;
    // PWMPCI PWM1; PHR disabled; PHF disabled; PLR disabled; PLF disabled; 
    PG1LEBH = 0x0;
    // PWMPCI PWM1; PHR disabled; PHF disabled; PLR disabled; PLF disabled; 
    PG2LEBH = 0x0;
    // PWMPCI PWM1; PHR disabled; PHF disabled; PLR disabled; PLF disabled; 
    PG3LEBH = 0x0;
    // PWMPCI PWM1; PHR disabled; PHF disabled; PLR disabled; PLF disabled; 
    PG4LEBH = 0x0;
    // PHASE1 0x0; 
    PG1PHASE = 0x0;
    // PHASE2 0x0; 
    PG2PHASE = 0x0;
    // PHASE3 0x0; 
    PG3PHASE = 0x0;
    // PHASE4 0x0; 
    PG4PHASE = 0x0;
    // DC1 0x0; 
    PG1DC = 0x0;
    // DC2 0x0; 
    PG2DC = 0x0;
    // DC3 0x0; 
    PG3DC = 0x0;
    // DC4 0x0; 
    PG4DC = 0x0;
    // DCA1 0x0; 
    PG1DCA = 0x0;
    // DCA2 0x0; 
    PG2DCA = 0x0;
    // DCA3 0x0; 
    PG3DCA = 0x0;
    // DCA4 0x0; 
    PG4DCA = 0x0;
    // PER1 0x0; 
    PG1PER = 0x0;
    // PER2 0x0; 
    PG2PER = 0x0;
    // PER3 0x0; 
    PG3PER = 0x0;
    // PER4 0x0; 
    PG4PER = 0x0;
    // TRIGA1 0x0; 
    PG1TRIGA = 0x0;
    // TRIGA2 0x0; 
    PG2TRIGA = 0x0;
    // TRIGA3 0x0; 
    PG3TRIGA = 0x0;
    // TRIGA4 0x0; 
    PG4TRIGA = 0x0;
    // TRIGB1 0x0; 
    PG1TRIGB = 0x0;
    // TRIGB2 0x0; 
    PG2TRIGB = 0x0;
    // TRIGB3 0x0; 
    PG3TRIGB = 0x0;
    // TRIGB4 0x0; 
    PG4TRIGB = 0x0;
    // TRIGC1 0x0; 
    PG1TRIGC = 0x0;
    // TRIGC2 0x0; 
    PG2TRIGC = 0x0;
    // TRIGC3 0x0; 
    PG3TRIGC = 0x0;
    // TRIGC4 0x0; 
    PG4TRIGC = 0x0;
    // DTL1 0x0; 
    PG1DTL = 0x0;
    // DTL2 0x0; 
    PG2DTL = 0x0;
    // DTL3 0x0; 
    PG3DTL = 0x0;
    // DTL4 0x0; 
    PG4DTL = 0x0;
    // DTH1 0x0; 
    PG1DTH = 0x0;
    // DTH2 0x0; 
    PG2DTH = 0x0;
    // DTH3 0x0; 
    PG3DTH = 0x0;
    // DTH4 0x0; 
    PG4DTH = 0x0;
    // 
    PG1CAP = 0x0;
    // 
    PG2CAP = 0x0;
    // 
    PG3CAP = 0x0;
    // 
    PG4CAP = 0x0;

    IFS4bits.PWM2IF = 0;
    IEC4bits.PWM2IE = 1;
    IFS4bits.PWM1IF = 0;
    IEC4bits.PWM1IE = 1;
}

void __attribute__ ((interrupt, no_auto_psv)) _PWM2Interrupt(void)
{
     IFS4bits.PWM2IF = 0;
}

void __attribute__ ((interrupt, no_auto_psv)) _PWM1Interrupt(void)
{
     IFS4bits.PWM1IF = 0;
}

