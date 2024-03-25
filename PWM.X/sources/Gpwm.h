/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   pwm.h
 * Author: A14426
 * Comments: Header file of the user-configuration source file pwm.c
 * Revision history: 0
 * 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_PWM_INITIALIZATION_H
#define	XC_PWM_INITIALIZATION_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "common/p33c_pwm.h" // Include dsPIC33C standard PWM driver header file


 /* *********************************************************************************
 * USER DEFINED GLOBAL VARIABLE DECLARATIONS
 * ********************************************************************************/    
    
/* Declare global, user-defined PWM generator object */    
extern volatile P33C_PWM_GENERATOR_t my_pg1;    
extern volatile P33C_PWM_GENERATOR_t my_pg2;
extern volatile P33C_PWM_GENERATOR_t my_pg3;

// Pre-compiler plausibility check if declared PWM generator index 
// points to an existing/available PWM generator on the selected device

#if (MY_PWM_GENERATOR > P33C_PG_COUNT)
  #pragma message "specified PWM generator peripheral instance not available (out of range)"
#endif

/* *********************************************************************************
 * USER FUNCTION PROTOTYPES
 * ********************************************************************************/    
// PWM declarations for demo code
#define MOTHER_PWM_GENERATOR      1           // Specify index of PWM generator instance (1=PG1, 3=PG2, etc)
#define CHILD_ONE_PWM_GENERATOR   2 
#define CHILD_TWO_PWM_GENERATOR   3    

/**/


extern volatile uint16_t PWM_Initialize_Generics(void);
extern volatile uint16_t PWM_Enable_Generics(void);
// extern volatile uint16_t PWM_Disable(void);

#define Test_Dac_Slopee_Comp  0
#endif	/* XC_PWM_INITIALIZATION_H */
