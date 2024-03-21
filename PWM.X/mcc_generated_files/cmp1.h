/**
  CMP1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    cmp1.h

  @Summary
    This is the generated header file for the CMP1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for CMP1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
        Driver Version    :  1.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

#ifndef _CMP1_H
#define _CMP1_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

/*slope for DAC setting*/


#define AUX_CLOCK               (float) 500e+6  // Auxiliary Clock Frequency in [Hz]

// Default DAC peripheral declarations
#define DAC_REFERENCE           (float) 3.700   // DAC reference voltage (usually AVDD)
#define DAC_RESOLUTION          (float)12.000   // DAC resolution in [bit]
#define DAC_TRANSITION_TIME     (float)340e-9   // Transition Mode Time setting DA09 specified in data sheet
#define DAC_STEADY_STATE_TIME   (float)550e-9   // Steady-State Time setting DA10 specified in data sheet
#define DAC_LEADING_EDGE_BLNK   (float)120e-9   // DAC LEading Edge Blanking period
#define DAC_VOLTAGE_MAX         (float) 3.135   // Maximum DAC output voltage specification in data sheet, DA09
#define DAC_VOLTAGE_MIN         (float) 0.625   // Minimum DAC output voltage specification in data sheet, DA10

// DAC declarations 
#define DAC_INSTANCE            1U // Specify index of DAC instance (1=DAC1, 2=DAC2, etc)
#define DAC_VOLTAGE_HIGH_1      (float) 1.800 // Demo-mode DAC level #1
#define DAC_VOLTAGE_HIGH_2      (float) 2.500 // Demo-mode DAC level #2
#define SLOPE_START_DELAY       (float) 0.10  // Delay in {%] until the slope compensation ramp starts
#define SLOPE_STOP_DELAY        (float) 0.90  // Delay in [%] until the slope compensation ramp stops
#define SLOPE_SLEW_RATE_1       (float) 0.200 // Delay in [V/�s] 
#define SLOPE_SLEW_RATE_2       (float) 0.400 // Delay in [V/�s] 

// DAC Conversion Macros
#define DAC_GRANULARITY         (float)(DAC_REFERENCE / pow(2.0, DAC_RESOLUTION)) // DAC granularity in [V/tick]
#define DAC_CLOCK_FREQUENCY     (float) AUX_CLOCK   // DAC input clock in [Hz]
#define DAC_CLOCK_PERIOD        (float)(2.0 / DAC_CLOCK_FREQUENCY) // DAC input clock (period) selected in [sec]
#define DAC_TMODTIME            (uint16_t)((DAC_TRANSITION_TIME * DAC_CLOCK_FREQUENCY) / 2.0)   // DAC Reset Transition Mode Period
#define DAC_SSTIME              (uint16_t)((DAC_STEADY_STATE_TIME * DAC_CLOCK_FREQUENCY) / 2.0) // Settling time period
#define DAC_TMCB                (uint16_t)((DAC_LEADING_EDGE_BLNK * DAC_CLOCK_FREQUENCY) / 2.0) // DACx Leading-Edge Blanking

#define SLP_TRIG_START          (uint16_t)(PWM_PERIOD * SLOPE_START_DELAY) // Delay in {sec] until the slope compensation ramp starts
#define SLP_TRIG_STOP           (uint16_t)(PWM_PERIOD * SLOPE_STOP_DELAY) // Delay in {sec] until the slope compensation ramp stops
#define SLP_SLEW_RATE_1         (uint16_t)((16.0 * (SLOPE_SLEW_RATE_1 / DAC_GRANULARITY)) / (1.0e-6 / DAC_CLOCK_PERIOD)) // SLOPE DATA in [<DAC ticks>/<CLK-ticks>] representing [V/usec]
#define SLP_SLEW_RATE_2         (uint16_t)((16.0 * (SLOPE_SLEW_RATE_2 / DAC_GRANULARITY)) / (1.0e-6 / DAC_CLOCK_PERIOD)) // SLOPE DATA in [<DAC ticks>/<CLK-ticks>] representing [V/usec]
#define SLP_PERIOD              (float)((SLOPE_STOP_DELAY-SLOPE_START_DELAY)*PWM_PERIOD) // Slope duration from START to STOP

#define DACOUT_VALUE_HIGH_1     (uint16_t)(DAC_VOLTAGE_HIGH_1 / DAC_GRANULARITY)
#define DACOUT_VALUE_HIGH_2     (uint16_t)(DAC_VOLTAGE_HIGH_2 / DAC_GRANULARITY)

/**
  @Summary
    The input sources to the comparator (Non inverting inputs)

  @Description
    The source values that are provided to the Non-inverting inputs of the 
    Comparator.  These could be CMPxA, CMPxB, CMPxD, SPGA1 and SPGA2 (INSEL).

*/

/*DAC 改變斜率測試*/
void slew_rate_1Dac(void);
void slew_rate_2Dac(void);

typedef enum
{
	CMP1_INPUT_CMP1D = 0x3, //CMP1D
	CMP1_INPUT_CMP1C = 0x2, //CMP1C
	CMP1_INPUT_CMP1B = 0x1, //CMP1B
	CMP1_INPUT_CMP1A = 0x0, //CMP1A
}CMP1_INPUT;

/**
  @Summary
    Comparator Filter Clock Divider enumeration values

  @Description
    The Filter clock divider values range from 1X to Divide by 8.  This enumerator 
	helps the user set the value in a readable form (FCLKDIV)

*/
typedef enum
{
	CMP1_FCLKDIV_1_8 = 0x7, 
	CMP1_FCLKDIV_1_7 = 0x6, 
	CMP1_FCLKDIV_1_6 = 0x5, 
	CMP1_FCLKDIV_1_5 = 0x4, 
	CMP1_FCLKDIV_1_4 = 0x3, 
	CMP1_FCLKDIV_1_3 = 0x2, 
	CMP1_FCLKDIV_1_2 = 0x1, 
	CMP1_FCLKDIV_1_1 = 0x0, 
}CMP1_FILTER_CLOCK_DIVIDER;

/**
  @Summary
    DAC Clock sources enumeration values

  @Description
    Clock sources to the DAC could be one of FPLLO, AFPLLO, FVCODIVMUX OR AFVCODIVMUX
	(CLKSEL)

*/
typedef enum
{
	CMP1_CLK_FPLLO___SYSTEM_CLOCK_WITH_PLL_ENABLED = 0x3, 
	CMP1_CLK_AFPLLO___AUXILIARY_CLOCK_WITH_PLL_ENABLED_ = 0x2, 
	CMP1_CLK_FVCODIV2___SYSTEM_VCO_CLOCK = 0x1, 
	CMP1_CLK_AFVCODIV2___AUXILIARY_VCO_CLOCK = 0x0, 
}CMP1_DAC_CLOCK_SOURCE;

/**
  @Summary
    DAC Clock Divider values

  @Description
    The divider values to be applied on the DAC Input clock source (CLKDIV)

*/
typedef enum
{
	CMP1_CLKDIV_1_4 = 0x3, 
	CMP1_CLKDIV_1_3 = 0x2, 
	CMP1_CLKDIV_1_2 = 0x1, 
	CMP1_CLKDIV_1_1 = 0x0, 
}CMP1_DAC_CLOCK_DIVIDER;

/**
  @Summary
    Interrupt Mode Selection values

  @Description
    Values that help the application to disable or set interrupts on the Falling, Rising 
	or both edges of the comparator output (IRQM)

*/
typedef enum
{
	CMP1_RISING_OR_FALLING_EDGE_DETECT = 0x3, 
	CMP1_FALLING_EDGE_DETECT = 0x2, 
	CMP1_RISING_EDGE_DETECT = 0x1, 
	CMP1_INTERRUPTS_ARE_DISABLED = 0x0, 
}CMP1_IRQ_MODE;

/**
  @Summary
    Comparator Hysteresis mode Selection values

  @Description
    Values that help the application set the Hysteresis level in the generated code (HYSSEL).
	The values could be one among No Hysteresis, 15mV, 30mV or 45mV.

*/
typedef enum
{
	CMP1_HYSTERESIS_45MV = 0x3, 
	CMP1_HYSTERESIS_30MV = 0x2, 
	CMP1_HYSTERESIS_15MV = 0x1, 
	CMP1_HYSTERESIS_NONE = 0x0, 
}CMP1_HYSTERESIS_SELECTION;

/**
  @Summary
    Slope Start Trigger values

  @Description
    Values that help the application set the trigger which starts the slope. The
    triggers could be associated with the different PWM instances

*/
typedef enum
{
	CMP1_START_PWM8_TRIGGER1 = 0x8, 
	CMP1_START_PWM7_TRIGGER1 = 0x7, 
	CMP1_START_PWM6_TRIGGER1 = 0x6, 
	CMP1_START_PWM5_TRIGGER1 = 0x5, 
	CMP1_START_PWM4_TRIGGER1 = 0x4, 
	CMP1_START_PWM3_TRIGGER1 = 0x3, 
	CMP1_START_PWM2_TRIGGER1 = 0x2, 
	CMP1_START_PWM1_TRIGGER1 = 0x1, 
	CMP1_START_NONE = 0x0, 
}CMP1_START_TRIGGER;

/**
  @Summary
    Slope Stop A Trigger values

  @Description
    Values that help the application set the trigger which stops the slope. The
    triggers could be associated with the different PWM instances

*/
typedef enum
{
	CMP1_STOPA_PWM8_TRIGGER2 = 0x8, 
	CMP1_STOPA_PWM7_TRIGGER2 = 0x7, 
	CMP1_STOPA_PWM6_TRIGGER2 = 0x6, 
	CMP1_STOPA_PWM5_TRIGGER2 = 0x5, 
	CMP1_STOPA_PWM4_TRIGGER2 = 0x4, 
	CMP1_STOPA_PWM3_TRIGGER2 = 0x3, 
	CMP1_STOPA_PWM2_TRIGGER2 = 0x2, 
	CMP1_STOPA_PWM1_TRIGGER2 = 0x1, 
	CMP1_STOPA_NONE = 0x0, 
}CMP1_STOPA_TRIGGER;

/**
  @Summary
    Slope Stop B Trigger values

  @Description
    Values that help the application set the trigger which stops the slope. The
    triggers could be associated with the different CMP instances

*/
typedef enum
{
	CMP1_STOPB_CMP3_OUTPUT = 0x3, 
	CMP1_STOPB_CMP2_OUTPUT = 0x2, 
	CMP1_STOPB_CMP1_OUTPUT = 0x1, 
	CMP1_STOPB_NONE = 0x0, 
}CMP1_STOPB_TRIGGER;

/**
  @Summary
    Hysteretic mode Trigger values

  @Description
    Values that help the application set the triggers in the Hysteretic mode

*/
typedef enum
{
	CMP1_HYSTERETIC_FUNCTION_PWM8H = 0x8, 
	CMP1_HYSTERETIC_FUNCTION_PWM7H = 0x7, 
	CMP1_HYSTERETIC_FUNCTION_PWM6H = 0x6, 
	CMP1_HYSTERETIC_FUNCTION_PWM5H = 0x5, 
	CMP1_HYSTERETIC_FUNCTION_PWM4H = 0x4, 
	CMP1_HYSTERETIC_FUNCTION_PWM3H = 0x3, 
	CMP1_HYSTERETIC_FUNCTION_PWM2H = 0x2, 
	CMP1_HYSTERETIC_FUNCTION_PWM1H = 0x1, 
	CMP1_HYSTERETIC_FUNCTION_NONE = 0x0, 
}CMP1_HYSTERETIC_FUNCTION;

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
      Section: CMP1 APIs
*/
/**
  @Summary
    Initialization function for the CMP1, DAC and Slope compensation.

  @Description
    This routine is the first API to be called among the Comparator with DAC module APIs.  
	This ensures the settings are in place before other operations are attempted.

  @Param
    None.

  @Returns 
    None
 
*/

void CMP1_Initialize(void);
        
/**
  @Summary
    This function returns the current output state of the Comparator

  @Description
    This routine returns true if the comparator output status is high. It 
    returns false if the comparator output status is low.

  @Param
    None.

  @Returns 
    bool.
 
*/
bool CMP1_ComparatorOuputStatusGet(void);

/**
  @Summary
    This function enables the Comparator module

  @Description
    This routine enables the common DAC module

  @Param
    none.

  @Returns 
    none.
 
*/
void CMP1_Enable(void);
    
/**
  @Summary
    This function disables the Comparator module

  @Description
    This routine disables the common DAC module

  @Param
    none.

  @Returns 
    none.
 
*/
void CMP1_Disable(void);
	
/**
  @Summary
    This function sets the Non Inverting input to the Comparator

  @Description
    This routine accepts a Input source number (CMPxA, CMPXB, CMPxD, SPGA1 
	or SPGA2) and sets the same in the DACCONL register.

  @Param
    Input Source channel.

  @Returns 
    none.
 
*/
void CMP1_SetInputSource(CMP1_INPUT inpSrc);

/**
  @Summary
    Callback for CMP1.

  @Description
    This routine is callback for CMP1

  @Param
    None.

  @Returns
    None
 
  @Example 
	Refer to CMP1_Initialize(); for an example
*/
void CMP1_CallBack(void);

/**
  @Summary
    This function defines the a Task which can be used by the application in
    the polling mode.

  @Description
    The Task function can be called in the main application using the High Speed
    Comparator, when interrupts are not used.  This would thus introduce the 
    polling mode feature of the Analog Comparator.

  @Param
    None.

  @Returns 
    none.
 
*/
void CMP1_Tasks(void);

/**
  @Summary
    This function sets the value in the DACDATH register

  @Description
    Setting the DACDATA High value

  @Param
    Value to be set in the DACDATAH register.

  @Returns 
    none.
 
*/
void CMP1_SetDACDataHighValue(uint16_t dacVal);

/**
  @Summary
    This function sets the value in the DACDATL register

  @Description
    Setting the DACDATA Low value

  @Param
    Value to be set in the DACDATAL register.

  @Returns 
    none.
 
*/
void CMP1_SetDACDataLowValue(uint16_t dacVal);

/**
  @Summary
    This function enables the DAC Output

  @Description
    Enabling the DAC Output

  @Param
    none.

  @Returns 
    none.
 
*/
void CMP1_EnableDACOutput(void);

/**
  @Summary
    This function disables the DAC Output

  @Description
    Disabling the DAC Output

  @Param
    none.

  @Returns 
    none.
 
*/
void CMP1_DisableDACOutput(void);

/**
  @Summary
    This function sets the Start Trigger for the Slope mode

  @Description
    Set the PWM trigger that should start the Slope

  @Param
    Value indicating the trigger to be set

  @Returns 
    none.
 
*/
void CMP1_SetStartTrigger(CMP1_START_TRIGGER trigger);

/**
  @Summary
    This function sets the Stop Trigger A for the Slope mode

  @Description
    Set the PWM trigger that should stop the Slope

  @Param
    Value indicating the trigger for StopA to be set

  @Returns 
    none.
 
*/
void CMP1_SetStopATrigger(CMP1_STOPA_TRIGGER trigger);

/**
  @Summary
    This function sets the Stop Trigger B for the Slope mode

  @Description
    Set the PWM trigger that should stop the Slope

  @Param
    Value indicating the trigger for StopB to be set

  @Returns 
    none.
 
*/
void CMP1_SetStopBTrigger(CMP1_STOPB_TRIGGER trigger);

/**
  @Summary
    This function sets the Hysteretic function trigger

  @Description
    Set the PWM trigger in the Hysteretic mode

  @Param
    Value indicating the trigger for Hysteretic mode

  @Returns 
    none.
 
*/
void CMP1_SetHystereticTrigger(CMP1_HYSTERETIC_FUNCTION trigger);




#endif //_CMP1_H

/**
  End of File
*/
