/***************************************************************************//**
 * @file vTMR1.c
 * @brief	wait timer for any process.
 *			1000Hz 1msec interval.
 *			use TMR1.
 * @author hiroshi murakami
 * @date	20231205
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#define _vTMR1_C

#include "mcc_generated_files/mcc.h"
#include "vTMR1.h"

//******************************************************************************
/**	
 * @brief   Interrupt TIMER1. 
 * @param[in,out]   uiTMR_xxx
 * @details     1000Hz 1msec interval
 */
void vTMR1_CallBack(void)
{
    // 1000Hz decrement timer with zero stopped
    int i;
    for (i = 0; i < NUMBER_OF_TIMERS; i = i + 1)
    {
    	if (vTIMERsobj.timer[i].countDownTime > 0) --vTIMERsobj.timer[i].countDownTime; 
    }
}

void vTMR1_setTime(TIMERs number_of_timers, uint16_t settime )
{
    vTIMERsobj.timer[number_of_timers].setTime = settime;
    vTIMERsobj.timer[number_of_timers].countDownTime = settime;
}

int8_t vTMR1_isFinished(TIMERs number_of_timers)
{
    if(vTIMERsobj.timer[number_of_timers].countDownTime == 0)
    {
        vTIMERsobj.timer[number_of_timers].countDownTime = vTIMERsobj.timer[number_of_timers].setTime;
        return 1;
    } else {
        return 0;
    }
}

void vTMR1_init(void)
{
    int i;
    for (i = 0; i < NUMBER_OF_TIMERS; i = i + 1)
    {
        vTIMERsobj.timer[i].countDownTime = 0;
        vTIMERsobj.timer[i].setTime = 0;
    }
}

