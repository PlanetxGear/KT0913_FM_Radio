/***************************************************************************//**
 * @file vPOWER.c
 * @brief	power control.
 * @author hiroshi murakami
 * @date	20231230
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#define _vPOWER_C

#include "mcc_generated_files/mcc.h"
#include "vPOWER.h"
#include "vKT0913.h"

//******************************************************************************
// DEFINES
//******************************************************************************


//******************************************************************************
/**	
 * @brief	POWER Off.
 * @return Non.
 * @param[in,out]	Non.
 *   	
 */
void vPOWER_Off(void)
{
    // Disabling TMR1 interrupt.
    PIE1bits.TMR1IE = 0;

    POWER_RADIO_LCD_OFF();
    POWER_AMP_OFF();
    POWER_BACKLIGHT_OFF();

    I2C1_Close();
    TMR1_StopTimer();
    
    
    // <<< Sleep >>>
    SLEEP();
    NOP();
    // <<< Sleep >>>

    
    TMR1_StartTimer();
    
    POWER_RADIO_LCD_ON();
    if (vKT0913obj.speakerOnOFF == 1 )
    {
        POWER_AMP_ON();
    }
    else
    {
        POWER_AMP_OFF();
    }

    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE = 1;
    
}



//******************************************************************************
/**	
 * @brief	IDLE mode.
 * @return Non.
 * @param[in,out]	Non.
 * @details 
 *  The CPU pauses.
 *  Peripheral is working.
 * 
 */
void vPOWER_Idle(void)
{

    CPUDOZEbits.IDLEN = 1;
    // <<< Sleep >>>
    SLEEP();
    // <<< Sleep >>>
    CPUDOZEbits.IDLEN = 0;

}
