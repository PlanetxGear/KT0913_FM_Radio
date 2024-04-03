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
#ifndef _vTMR1_H
#define _vTMR1_H


//******************************************************************************
// DEFINES
//******************************************************************************
#define vTMR1_NoOperation_INTERVAL 5000 // interval is 5s.
#define vTMR1_setWaitTime_for_NoOperation()  vTMR1_setTime(eTMR_SW_NoOperation,vTMR1_NoOperation_INTERVAL) // Set the interval to 7s.

#define NUMBER_OF_TIMERS 6
typedef enum {
	eTMR_LED1 = 0,			
	eTMR_BackLight,	
	eTMR_ChannelDisplay,
	eTMR_SW_checkInterval,
    eTMR_SW_NoOperation,
	eTMR_PowerOff
            
} TIMERs;

typedef struct {
	uint16_t setTime; // ms
	uint16_t countDownTime; // Timer that counts down every 1ms
} vTMR1_OBJECT;

typedef struct {
    vTMR1_OBJECT timer[NUMBER_OF_TIMERS];
} vTIMERs_OBJECT;

//******************************************************************************
// VARIABLES
//******************************************************************************


#if defined _vTMR1_C
    TIMERs eTimers;
    vTIMERs_OBJECT vTIMERsobj;
#else
    extern TIMERs eTimers;
    extern vTIMERs_OBJECT vTIMERsobj;
#endif

//******************************************************************************
// PROTOTYPES
//******************************************************************************
void vTMR1_CallBack(void);
void vTMR1_init(void);
void vTMR1_setTime(TIMERs number_of_timers, uint16_t settime );
int8_t vTMR1_isFinished(TIMERs number_of_timers);

#endif