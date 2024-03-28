/**
  PWM Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm.c

  @Summary
    This is the generated driver implementation file for the PWM driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for PWM.
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

#include "pwm.h"
#include "clock.h"
#include "GPIO.h"
/**
 Section: Driver Interface Function Definitions
 */

// PWM Default PWM Generator Interrupt Handler
static void (*PWM_Generator1InterruptHandler)(void) = NULL;

// PWM Default Event Interrupt Handler
static void (*PWM_EventAInterruptHandler)(void) = NULL;
static void (*PWM_EventBInterruptHandler)(void) = NULL;
static void PWM_Slaver_ON(void);
static void PWM_Slaver_OFF(void);
/*pravite var here*/
static uint8_t test_var;

void PWM_Initialize(void)
{
    // HREN disabled; MODSEL Independent Edge; TRGCNT 1; CLKSEL Master clock; ON enabled;
    PG1CONL = 0x8;
    // HREN disabled; MODSEL Independent Edge; TRGCNT 1; CLKSEL Master clock; ON enabled;
    PG2CONL = 0x8;
    // MCLKSEL AFPLLO - Auxiliary Clock with PLL Enabled; HRERR disabled; LOCK disabled; DIVSEL 1:2;
    PCLKCON = 0x03;
    // FSCL 0;
    FSCL = 0x00;
    // FSMINPER 0;
    FSMINPER = 0x00;
    // MPHASE 0;
    MPHASE = 0x00;
    // MDC 0;
    MDC = 0x00;
    // MPER 16;
    MPER = 0x10;
    // LFSR 0;
    LFSR = 0x00;
    // CTA7EN disabled; CTA8EN disabled; CTA1EN disabled; CTA2EN disabled; CTA5EN disabled; CTA6EN disabled; CTA3EN disabled; CTA4EN disabled;
    CMBTRIGL = 0x00;
    // CTB8EN disabled; CTB3EN disabled; CTB2EN disabled; CTB1EN disabled; CTB7EN disabled; CTB6EN disabled; CTB5EN disabled; CTB4EN disabled;
    CMBTRIGH = 0x00;
    // PWMLFA PWMS1 or PWMS2;; S1APOL Positive logic; S2APOL Positive logic; PWMLFAD No Assignment; PWMS1A PWM1H; PWMS2A PWM1H;
    LOGCONA = 0x00;
    // PWMLFB PWMS1 | PWMS2; S2BPOL Positive logic; PWMLFBD No Assignment; S1BPOL Positive logic; PWMS2B PWM1H; PWMS1B PWM1H;
    LOGCONB = 0x00;
    // PWMLFC PWMS1 | PWMS2; PWMLFCD No Assignment; S2CPOL Positive logic; S1CPOL Positive logic; PWMS1C PWM1H; PWMS2C PWM1H;
    LOGCONC = 0x00;
    // PWMS1D PWM1H; S1DPOL Positive logic; PWMLFD PWMS1 | PWMS2; PWMLFDD No Assignment; S2DPOL Positive logic; PWMS2D PWM1H;
    LOGCOND = 0x00;
    // PWMS1E PWM1H; PWMS2E PWM1H; S1EPOL Positive logic; PWMLFE PWMS1 | PWMS2; S2EPOL Positive logic; PWMLFED No Assignment;
    LOGCONE = 0x00;
    // S1FPOL Positive logic; PWMS2F PWM1H; PWMS1F PWM1H; S2FPOL Positive logic; PWMLFFD No Assignment; PWMLFF PWMS1 | PWMS2;
    LOGCONF = 0x00;
    // EVTASEL PGTRGSEL bits; EVTASYNC Not synchronized; EVTAPOL Active-high; EVTAPGS PG1; EVTASTRD Stretched to 8 PWM clock cycles minimum; EVTAOEN disabled;
    PWMEVTA = 0x00;
    // EVTBPGS PG1; EVTBSYNC Not synchronized; EVTBPOL Active-high; EVTBSEL PGTRGSEL bits; EVTBSTRD Stretched to 8 PWM clock cycles minimum; EVTBOEN disabled;
    PWMEVTB = 0x00;
    // EVTCPGS PG1; EVTCPOL Active-high; EVTCSEL PGTRGSEL bits; EVTCSTRD Stretched to 8 PWM clock cycles minimum; EVTCSYNC Not synchronized; EVTCOEN disabled;
    PWMEVTC = 0x00;
    // EVTDOEN disabled; EVTDSTRD Stretched to 8 PWM clock cycles minimum; EVTDPOL Active-high; EVTDPGS PG1; EVTDSEL PGTRGSEL bits; EVTDSYNC Not synchronized;
    PWMEVTD = 0x00;
    // EVTEOEN disabled; EVTEPOL Active-high; EVTEPGS PG1; EVTESTRD Stretched to 8 PWM clock cycles minimum; EVTESEL PGTRGSEL bits; EVTESYNC Not synchronized;
    PWMEVTE = 0x00;
    // EVTFPOL Active-high; EVTFPGS PG1; EVTFSTRD Stretched to 8 PWM clock cycles minimum; EVTFSEL PGTRGSEL bits; EVTFOEN disabled; EVTFSYNC Not synchronized;
    PWMEVTF = 0x00;
    // MSTEN disabled; TRGMOD Single trigger mode; SOCS Self-trigger; UPDMOD SOC update; MPHSEL disabled; MPERSEL disabled; MDCSEL disabled;
    PG1CONH = 0x00;
    // MSTEN disabled; TRGMOD Single trigger mode; SOCS Trigger output selected by PG1 or PG5; UPDMOD SOC update; MPHSEL disabled; MPERSEL disabled; MDCSEL disabled;
    PG2CONH = 0x01;
    // TRSET disabled; UPDREQ disabled; CLEVT disabled; TRCLR disabled; CAP disabled; SEVT disabled; FFEVT disabled; UPDATE disabled; FLTEVT disabled;
    PG1STAT = 0x00;
    // TRSET disabled; UPDREQ disabled; CLEVT disabled; TRCLR disabled; CAP disabled; SEVT disabled; FFEVT disabled; UPDATE disabled; FLTEVT disabled;
    PG2STAT = 0x00;
    // FLTDAT 0; DBDAT 0; SWAP disabled; OVRENH disabled; OVRENL disabled; OSYNC User output overrides are synchronized to the local PWM time base; CLMOD disabled; FFDAT 0; CLDAT 0; OVRDAT 0;
    PG1IOCONL = 0x00;
    // FLTDAT 0; DBDAT 0; SWAP disabled; OVRENH disabled; OVRENL disabled; OSYNC User output overrides are synchronized to the local PWM time base; CLMOD disabled; FFDAT 0; CLDAT 0; OVRDAT 0;
    PG2IOCONL = 0x00;
    // PENL enabled; DTCMPSEL PCI Sync Logic; PMOD Independent; POLL Active-high; PENH enabled; CAPSRC Software; POLH Active-high;
    PG1IOCONH = 0x1C;
    // PENL enabled; DTCMPSEL PCI Sync Logic; PMOD Independent; POLL Active-high; PENH enabled; CAPSRC Software; POLH Active-high;
    PG2IOCONH = 0x1C;
    // UPDTRG Manual; ADTR1PS 1:1; PGTRGSEL Trigger A compare event; ADTR1EN3 disabled; ADTR1EN1 disabled; ADTR1EN2 enabled;
    PG1EVTL = 0x201;
    // UPDTRG Duty Cycle; ADTR1PS 1:1; PGTRGSEL EOC event; ADTR1EN3 disabled; ADTR1EN1 disabled; ADTR1EN2 disabled;
    PG2EVTL = 0x08;
    // ADTR2EN1 disabled; IEVTSEL EOC; SIEN disabled; FFIEN disabled; ADTR1OFS None; CLIEN disabled; FLTIEN disabled; ADTR2EN2 disabled; ADTR2EN3 enabled;
    PG1EVTH = 0x80;
    // ADTR2EN1 disabled; IEVTSEL EOC; SIEN disabled; FFIEN disabled; ADTR1OFS None; CLIEN disabled; FLTIEN disabled; ADTR2EN2 disabled; ADTR2EN3 disabled;
    PG2EVTH = 0x00;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC;
    PG1FPCIL = 0x00;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC;
    PG2FPCIL = 0x00;
    // TQPS Not inverted; LATMOD disabled; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive;
    PG1FPCIH = 0x00;
    // TQPS Not inverted; LATMOD disabled; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive;
    PG2FPCIH = 0x00;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC;
    PG1CLPCIL = 0x00;
    // PSS Comparator 1 output; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Auto-Terminate; AQPS Inverted; AQSS LEB is active; TSYNCDIS PWM EOC;
    PG2CLPCIL = 0x1A1B;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive;
    PG1CLPCIH = 0x00;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Latched;
    PG2CLPCIH = 0x300;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC;
    PG1FFPCIL = 0x00;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC;
    PG2FFPCIL = 0x00;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive;
    PG1FFPCIH = 0x00;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive;
    PG2FFPCIH = 0x00;
    // PSS Comparator 1 output; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Auto-Terminate; AQPS Inverted; AQSS LEB is active; TSYNCDIS PWM EOC;
    PG1SPCIL = 0x1A1B;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC;
    PG2SPCIL = 0x00;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Latched;
    PG1SPCIH = 0x300;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive;
    PG2SPCIH = 0x00;
    // LEB 256;
    PG1LEBL = 0x100;
    // LEB 0;
    PG2LEBL = 0x00;
    // PWMPCI PWM1; PLR disabled; PLF disabled; PHR disabled; PHF disabled;
    PG1LEBH = 0x00;
    // PWMPCI PWM1; PLR disabled; PLF disabled; PHR disabled; PHF disabled;
    PG2LEBH = 0x00;
    // PHASE 0;
    PG1PHASE = 0x00;
    // PHASE 0;
    PG2PHASE = 0x00;
    // DC 2500;
    PG1DC = 0x9C4;
    // DC 2500;
    PG2DC = 0x9C4;
    // DCA 0;
    PG1DCA = 0x00;
    // DCA 0;
    PG2DCA = 0x00;
    // PER 4999;
    PG1PER = 0x1387;
    // PER 4999;
    PG2PER = 0x1387;
    // TRIGA 1250;
    PG1TRIGA = 0x4E2;
    // TRIGA 0;
    PG2TRIGA = 0x00;
    // TRIGB 1250;
    PG1TRIGB = 0x4E2;
    // TRIGB 0;
    PG2TRIGB = 0x00;
    // TRIGC 1250;
    PG1TRIGC = 0x4E2;
    // TRIGC 0;
    PG2TRIGC = 0x00;
    // DTL 50;
    PG1DTL = 0x32;
    // DTL 50;
    PG2DTL = 0x32;
    // DTH 50;
    PG1DTH = 0x32;
    // DTH 50;
    PG2DTH = 0x32;

    /*switch btn inital*/
    BUTTON_S1_PRESSED = 1;
    BUTTON_S2_TRIS = 1;
    BUTTON_S3_TRIS = 1;
    /*Rising edge of PWM1H trigger*/

    /*PCI setting*/
    // PG1IOCONL = 0x0010; /* 1 on PWM1L and 0 on PWM1H if CLMT event is active */
    // PG1CLPCIL = 0x123B; /* ACMP1 out selected as PCI input, latched PCI acceptance */
    // PG1CLPCIH = 0x0300; /* Latched PCI as acceptance qualifier, no termination qualifier */

    // PG1TRIGA = 1250; /*Generate Trig 1 at 1.25 us*/
    // PG1TRIGB = 2000; /*Generate Trig 2 towards eoc (2.5u-0.5u)for transition mode*/

    // PG1EVTL = 0x0118; /* Trigger1 updated by TrigA, Auto update of UPTRG */
    // PG1EVTH = 0x0340; /* Trigger1 updated by TrigB, Disable interrupts */

    /*PCI for PG1*/
    // PG1LEBH = 0x0008;   /*PHR=1 Rising edge*/
    // PG1LEBL = 200;      /*LEB=200*/
    // PG1IOCONL = 0x0010; /*PHR=1 Rising edge*/
    // PG1CLPCIL = 0x1A1B;
    // PG1CLPCIH = 0x0300;

    // /*PCI for PG2*/
    // PG2LEBH = 0x0008;   /*PHR=1 Rising edge*/
    // PG2LEBL = 200;      /*LEB=200*/
    // PG2IOCONL = 0x0010; /*PHR=1 Rising edge*/
    // PG2CLPCIL = 0x1A1B;
    // PG2CLPCIH = 0x0300;

    // PCLKCONbits.MCLKSEL = 3; /* Master Clock Source */
    // PG1CONLbits.CLKSEL = 1;  /* Clock selected by MCLKSEL */
    /*PWM DATA REGISTER*/
    // PG1DC = 0; /*PWM duty cycle set to 0*/
    /*PCI logic configuration for Hysteretic mode, comparator 1 output as PCI source*/
    // PG1CLPCIL = 0x123B; /* ACMP1 out selected as PCI input, latched PCI acceptance */
    // PG1CLPCIH = 0x0300; /* Latched PCI signal as acceptance criteria */
    // PG1LEBL = 0x0100;   /* LEB Count = 0x100 */

    // PG2CLPCIL = 0x123B; /* ACMP1 out selected as PCI input, latched PCI acceptance */
    // PG2CLPCIH = 0x0300; /* Latched PCI signal as acceptance criteria */
    // PG2LEBL = 0x0100;   /* LEB Count = 0x100 */
    /*Enable PWM macro*/
    // PG1CONLbits.ON = 1; /*PWM module is enabled*/

    /* Initialize PWM Generator Interrupt Handler*/
    PWM_SetGenerator1InterruptHandler(&PWM_Generator1_CallBack);

    // PWM Generator 1 Interrupt
    IFS4bits.PWM1IF = 0;
    IEC4bits.PWM1IE = 1;

    // Wait until AUX PLL clock is locked
    while (!CLOCK_AuxPllLockStatusGet())
        ;

    PG1CONLbits.ON = 1;
    PG2CONLbits.ON = 1;
}

void __attribute__((weak)) PWM_Generator1_CallBack(void)
{
    //    PWM_Duty_Increase();
}

void PWM_SetGenerator1InterruptHandler(void *handler)
{
    PWM_Generator1InterruptHandler = handler;
}

void __attribute__((interrupt, no_auto_psv)) _PWM1Interrupt()
{

/*BTN event */
#if (TEST_Slaver_ONOFF == True)
    if (check_BTN_Press() == False)
    {
        // PG2CONLbits.ON = 0;
        //  GPIO_OFF();

        // change PDC1
        // PG1DC = 0xFFF0;
        // PG1STATbits.UPDREQ = 1;
        // PG1STATbits.UPDREQ = 0;
    }
    else if (check_SW2_Press() == False)
    {
        // PG2CONLbits.ON = 1;
        //  GPIO_ON();

        // relase back pdc duty
        // PG1DC=0x4E20;
        //  PG1STATbits.UPDREQ = 1;
        //   PG1STATbits.UPDREQ = 0;
    }
    else
    {
        //  PG1DC = 0x9C4;
        //  PG1STATbits.UPDREQ = 0;
    }

#endif
    IFS4bits.PWM1IF = 0;
}

/*Test quit fault mode*/
void Quit_Fault(void)
{
    PG1IOCONLbits.OVRDAT = 0b00;
    PG1IOCONLbits.OVRENH = 1;
    PG1IOCONLbits.OVRENL = 1;

    /*Reset latch mode*/
    PG1STATbits.FLTEVT = 0;   // clear fault event
    PG1CLPCIHbits.LATMOD = 1; // reset mode

    /**/
    PG1CLPCIHbits.LATMOD = 0; // Enable fault module again
    /*fault isr guess now not sure*/
    IEC10bits.PEVTAIE = 0;
    IEC10bits.PEVTAIE = 1;
    /*disable override*/
    PG1IOCONLbits.OVRENH = 0;
    PG1IOCONLbits.OVRENL = 0;

    PG1CLPCIHbits.SWPCI = 0;
}

void __attribute__((weak)) PWM_Generator2_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator2_Tasks(void)
{
    if (IFS4bits.PWM2IF)
    {
        // PWM Generator2 callback function
        PWM_Generator2_CallBack();

        // clear the PWM Generator2 interrupt flag
        IFS4bits.PWM2IF = 0;
    }
}

void __attribute__((weak)) PWM_EventA_CallBack(void)
{
    if (check_BTN_Press() == True)
    {
        // GPIO_OFF();
        PG1CLPCIHbits.SWPCI = 1;
        test_var = True;
    }
    else
        test_var = False;
}

void PWM_SetEventAInterruptHandler(void *handler)
{
    PWM_EventAInterruptHandler = handler;
}

void __attribute__((interrupt, no_auto_psv)) _PEVTAInterrupt()
{
    if (PWM_EventAInterruptHandler)
    {
        // PWM EventA interrupt handler function
        PWM_EventAInterruptHandler();
    }

    // clear the PWM EventA interrupt flag
    IFS10bits.PEVTAIF = 0;
}

void __attribute__((weak)) PWM_EventB_CallBack(void)
{
    // Add Application code here
}

void PWM_SetEventBInterruptHandler(void *handler)
{
    PWM_EventBInterruptHandler = handler;
}

void __attribute__((interrupt, no_auto_psv)) _PEVTBInterrupt()
{
    if (PWM_EventBInterruptHandler)
    {
        // PWM EventB interrupt handler function
        PWM_EventBInterruptHandler();
    }

    // clear the PWM EventB interrupt flag
    IFS10bits.PEVTBIF = 0;
}

void __attribute__((weak)) PWM_EventC_CallBack(void)
{
    // Add Application code here
}

void PWM_EventC_Tasks(void)
{
    if (IFS10bits.PEVTCIF)
    {

        // PWM EventC callback function
        PWM_EventC_CallBack();

        // clear the PWM EventC interrupt flag
        IFS10bits.PEVTCIF = 0;
    }
}

void __attribute__((weak)) PWM_EventD_CallBack(void)
{
    // Add Application code here
}

void PWM_EventD_Tasks(void)
{
    if (IFS10bits.PEVTDIF)
    {

        // PWM EventD callback function
        PWM_EventD_CallBack();

        // clear the PWM EventD interrupt flag
        IFS10bits.PEVTDIF = 0;
    }
}

void __attribute__((weak)) PWM_EventE_CallBack(void)
{
    // Add Application code here
}

void PWM_EventE_Tasks(void)
{
    if (IFS10bits.PEVTEIF)
    {

        // PWM EventE callback function
        PWM_EventE_CallBack();

        // clear the PWM EventE interrupt flag
        IFS10bits.PEVTEIF = 0;
    }
}

void __attribute__((weak)) PWM_EventF_CallBack(void)
{
    // Add Application code here
}

void PWM_EventF_Tasks(void)
{
    if (IFS10bits.PEVTFIF)
    {

        // PWM EventF callback function
        PWM_EventF_CallBack();

        // clear the PWM EventF interrupt flag
        IFS10bits.PEVTFIF = 0;
    }
}

/*Method 實作*/
uint8_t check_BTN_Press(void)
{
    if (BUTTON_S1_PORT == BUTTON_S1_PRESSED)
        return True;
    else
        return False;
}

/*latch off*/
uint8_t check_SW2_Press(void)
{
    if (BUTTON_S2_PORT == BUTTON_S2_PRESSED)
        return True;
    else
        return False;
}

/*restart PCI block */
uint8_t check_SW3_Press(void)
{
    if (BUTTON_S3_PORT == BUTTON_S3_PRESSED)
        return True;
    else
        return False;
}

/**
 * PDC只有在開始的時候才能調整duty
 * 需要找到可以同時調整Freq 和 Duty 的方式
 */
void PWM_Duty_Increase(void)
{
    // Test Duty Modulation  -result is PWM duty
#if (Test_Duty_Modulation == True)

    PG1PER = PG1PER + Freq_1_PER;
    // PG1DC = PG1DC + PWM_1_Duty;
    PG1DC = PG1DC;
    // if (PG1DC > PG1PER)
    // {
    //     PWM_DutyCycleSet(PWM_GENERATOR_1, PWM_1_Duty);
    // }
    if (PG1PER > 0x9C38)
        PWM_PeriodSet(PWM_GENERATOR_1, Freq_10KHz);
        // Test Freq Modulation ,need also fix for the pwm formula PTPER recalculate also have recalculate duty cycle
#elif (Test_Freq_Modulation == True)
    /*recored last times PTPER make a slope gain here*/
    uint32_t PG1PER_Last = PG1PER;
    uint32_t Freq_Gain;
    /*Update freq here*/
    PG1PER = PG1PER + Freq_1_PER;
    /*slope gain for new PTPER*/
    Freq_Gain = PG1PER_Last / PG1PER;
    /*undo here if cross over how to fix duty cycle*/
    /*Synrconzie update duty with new PTPER here */

    PG1DC = Freq_Gain * PG1DC;

    /*越界就Freq調變為10kHz*/
    if (PG1PER > 0x9C38)
        PWM_PeriodSet(PWM_GENERATOR_1, Freq_10KHz);

        /*移動phase 其實也是修正PDC 的變化量-result is PWM duty */
#elif (Test_Phase == True)
    PG1PHASE = PG1PHASE + Freq_1_PER;
    if (PG1PHASE > 0x9C38)
    {
        PWM_PhaseSet(PWM_GENERATOR_1, Freq_10KHz);
    }
#elif (Test_PTPER_RESET == True)
    /*variable delcare*/

    uint32_t PG1PER_Last = PG1PER;
    uint32_t Freq_Gain;
    /*Update freq here*/
    PG1PER = PG1PER + Freq_1_PER;
    /*slope gain for new PTPER*/
    Freq_Gain = PG1PER_Last / PG1PER;
    /*undo here if cross over how to fix duty cycle*/
    /*Synrconzie update duty with new PTPER here */

    PG1DC = Freq_Gain * PG1DC;

    /*越界就Freq調變為10kHz*/
    if (PG1PER > 0x9C38)
        PWM_PeriodSet(PWM_GENERATOR_1, Freq_10KHz);

#endif
}

/*On off slaver side PWM*/
static void PWM_Slaver_ON(void)
{
    PG2CONLbits.ON = 1;
}

static void PWM_Slaver_OFF(void)
{
    PG2CONLbits.ON = 0;
}
