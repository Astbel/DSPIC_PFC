/**
  CMP1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cmp1.c

  @Summary
    This is the generated driver implementation file for the CMP1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for CMP1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
        Driver Version    :  1.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/**
  Section: Included Files
*/
#include "pwm.h"
#include "cmp1.h"
#include "cmp1.h"
#include "GPIO.h"
/**
  Section: CMP1 APIs
*****************************************************************************************/
/******************************************************************************
 *
 *    Function:			CMP1_Initialize
 *    Description:       Initialization of the Comparator with Slope Compensation module
 *
 *    Return Value:      None
 ******************************************************************************/

void CMP1_Initialize(void)
{

    // Disable the CMP module before the initialization
    CMP1_Disable();

	
    // Comparator Register settings
	DACCTRL1L = 0x80; //CLKDIV 1:1; DACON disabled; DACSIDL disabled; FCLKDIV 1:1; CLKSEL AFPLLO - Auxiliary Clock with PLL Enabled ; 
	DACCTRL2L = 0x55; //TMODTIME 85; 
	DACCTRL2H = 0x8A; //SSTIME 138; 
	DAC1CONH = 0x00; //TMCB 0; 
	DAC1CONL = 0xA700; //CMPPOL Non Inverted; HYSPOL Rising Edge; HYSSEL None; DACEN enabled; FLTREN enabled; CBE enabled; IRQM Rising edge detect; INSEL CMP1A; DACOEN enabled; 

	//Slope Settings
	SLP1CONH = 0x00; //HME disabled; PSE Negative; SLOPEN disabled; TWME disabled; 
	SLP1CONL = 0x1101; //HCFSEL PWM1H; SLPSTRT PWM1 Trigger1; SLPSTOPB None; SLPSTOPA PWM1 Trigger2; 
	SLP1DAT = 0x0F; //SLPDAT 15; 
	DAC1DATL = 0x9C4; //DACDATL 2500; 
	DAC1DATH = 0xFA0; //DACDATH 4000; 

	
    CMP1_Enable();

}

/******************************************************************************
 *
 *    Function:			CMP1_ComparatorOuputStatusGet
 *    Description:       Returns the status of the Comparator including the
 *						polarity
 *
 *    Return Value:      True if the Comparator Status is 1 and False if it is 0
 ******************************************************************************/
bool CMP1_ComparatorOuputStatusGet(void)
{
    return (DAC1CONLbits.CMPSTAT);
}

/******************************************************************************
 *
 *    Function:			CMP1_Enable
 *    Description:       Enables the common DAC module
 *
 *	 Parameters:		None
 *    Return Value:      None
 ******************************************************************************/
void CMP1_Enable(void)
{
    DACCTRL1Lbits.DACON = 1;
}

/******************************************************************************
 *
 *    Function:			CMP1_Disable
 *    Description:       Disables the common DAC module
 *
 *	 Parameters:		None
 *    Return Value:      None
 ******************************************************************************/
void CMP1_Disable(void)
{
    DACCTRL1Lbits.DACON = 0;
}

/******************************************************************************
 *
 *    Function:			CMP1_SetInputSource
 *    Description:       Set the source to the non-inverting input of the
 *						Comparator module
 *
 *	 Parameters:		Enumeration specifying the input source
 *    Return Value:      None
 ******************************************************************************/
void CMP1_SetInputSource(CMP1_INPUT inpSrc)
{
    DAC1CONLbits.INSEL = inpSrc;
}

/******************************************************************************
 *
 *    Function:		CMP1_SetDACDataHighValue
 *    Description:       Sets the DAC Data High Value
 *
 *    Parameters:        Value to be set as DAC Data High
 *    Return Value:      None
 ******************************************************************************/
void CMP1_SetDACDataHighValue(uint16_t dacVal)
{
    DAC1DATH = dacVal;
}

/******************************************************************************
 *
 *    Function:		CMP1_SetDACDataLowValue
 *    Description:       Sets the DAC Data Low Value
 *
 *    Parameters:        Value to be set as DAC Data Low
 *    Return Value:      None
 ******************************************************************************/
void CMP1_SetDACDataLowValue(uint16_t dacVal)
{
    DAC1DATL = dacVal;
}

/******************************************************************************
 *
 *    Function:		CMP1_EnableDACOutput
 *    Description:       Enables the DAC Output
 *
 *    Parameters:        None
 *    Return Value:      None
 ******************************************************************************/
void CMP1_EnableDACOutput(void)
{
    DAC1CONLbits.DACOEN = 1;
}

/******************************************************************************
 *
 *    Function:		CMP1_DisableDACOutput
 *    Description:       Disables the DAC Output
 *
 *    Parameters:        None
 *    Return Value:      None
 ******************************************************************************/
void CMP1_DisableDACOutput(void)
{
    DAC1CONLbits.DACOEN = 0;
}

/******************************************************************************
 *
 *    Function:		CMP1_SetStartTrigger
 *    Description:       Trigger set for the Start Signal of the Slope
 *
 *    Parameters:        Value indicating the trigger to be set
 *    Return Value:      None
 ******************************************************************************/
void CMP1_SetStartTrigger(CMP1_START_TRIGGER trigger)
{
    SLP1CONLbits.SLPSTRT = trigger;
}

/******************************************************************************
 *
 *    Function:		CMP1_SetStopATrigger
 *    Description:       Trigger set for the Stop A Signal of the Slope
 *
 *    Parameters:        Value indicating the trigger to be set
 *    Return Value:      None
 ******************************************************************************/
void CMP1_SetStopATrigger(CMP1_STOPA_TRIGGER trigger)
{
    SLP1CONLbits.SLPSTOPA = trigger;
}

/******************************************************************************
 *
 *    Function:		CMP1_SetStopBTrigger
 *    Description:       Trigger set for the Stop B Signal of the Slope
 *
 *    Parameters:        Value indicating the trigger to be set
 *    Return Value:      None
 ******************************************************************************/
void CMP1_SetStopBTrigger(CMP1_STOPB_TRIGGER trigger)
{
    SLP1CONLbits.SLPSTOPB = trigger;
}

/******************************************************************************
 *
 *    Function:		CMP1_SetHystereticTrigger
 *    Description:       Trigger set for the Hysteretic mode
 *
 *    Parameters:        Value indicating the trigger to be set
 *    Return Value:      None
 ******************************************************************************/
void CMP1_SetHystereticTrigger(CMP1_HYSTERETIC_FUNCTION trigger)
{
    SLP1CONLbits.HCFSEL = trigger;
}

/* Callback function for the CMP1 module */
void __attribute__ ((weak)) CMP1_CallBack(void)
{
    // Add your custom callback code here
}

/******************************************************************************
 *    Function:			CMP1_Tasks
 *    Description:       The Task function can be called in the main application
 *						using the High Speed Comparator, when interrupts are not
 *						used.  This would thus introduce the polling mode feature
 *						of the Analog Comparator.
 *
 *	 Parameters:		None
 *    Return Value:      None
 ******************************************************************************/
void CMP1_Tasks(void)
{
	if(IFS4bits.CMP1IF)
    {
        // CMP1 callback function
        CMP1_CallBack();

        // clear the CMP1 interrupt flag
        IFS4bits.CMP1IF = 0;
    }
}
/******************************************************************************
 *    Function:		slope method simulation  CBC function LBE protection
 *    Description:  Pressing switch changing DAC value switching value
 *                  DAC change for swape value to touch the CBC function
 *                  here need to print DAC value 
 *	 Parameters:	   None
 *   Return Value:     None
 ******************************************************************************/
void CBC_Function_Task(CBC_Simulation CBC_Level)
{
    switch (CBC_Level)
    {
    case Slope_A:      /*80 Current limit duty output*/
        PG1DC = 0x9C4; /*duty 50*/
        PG2DC = 0x9C4;
        /*manuel SOC updata*/
        PG1STATbits.UPDREQ = 1;
        PG2STATbits.UPDREQ = 1;
        /*Updata DAC value*/
        DAC1DATH = 0x9A0; /*Upper limit*/
        break;

    case Slope_B: /*90 Current limit duty output*/

        // PG1DC = 0x1194; /*duty 90*/
        /*manuel SOC updata*/
        // PG1STATbits.UPDREQ = 1;
        /*Updata DAC value*/
        // DAC1DATH = 0xFA0; /*Upper limit 80 duty*/
           DAC2DATH  = 0xFA0;
        break;

    case Slope_C: /*Shunt down*/

        PG1DC = 0x1194; /*duty 50*/
                        /*manuel SOC updata*/
        PG1STATbits.UPDREQ = 1;
        /*Updata DAC value*/
        DAC1DATH = 0xFA0; /*Upper limit 80duty*/
        break;
    }
}

/**
 End of File
*/
