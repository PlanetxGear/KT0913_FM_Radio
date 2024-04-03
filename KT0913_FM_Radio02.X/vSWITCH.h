/***************************************************************************//**
 * @file vSWITCH.h
 * @brief	switch menu control.
 * @author hiroshi murakami
 * @date	20231206
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#ifndef _vSWITCH_H
#define _vSWITCH_H

//******************************************************************************
// DEFINES
//******************************************************************************
#define SWITCH_ON		1
#define SWITCH_OFF		0

#define isSW1ON	(SW1_menu_GetValue()==0)	// Low is ON. Menu status go to forward. 
#define isSW2ON	(SW2_up_GetValue()==0)      // Low is ON. Menu up or Number Addition.
#define isSW3ON	(SW3_down_GetValue()==0)	// Low is ON. Menu down or Number Subtraction.

#define getSW0summaryStatus()   (eSW_status(eSW0))	// get switch status. 0:OFF/ 1:ON/ 2:PressedLong.
#define getSW1menuStatus()      (eSW_status(eSW1))	// get switch status. 0:OFF/ 1:ON/ 2:PressedLong.
#define getSW2upStatus()        (eSW_status(eSW2))  // get switch status. 0:OFF/ 1:ON/ 2:PressedLong. 
#define getSW3downStatus()      (eSW_status(eSW3))	// get switch status. 0:OFF/ 1:ON/ 2:PressedLong. 

#define NUMBER_OF_SW 4
typedef enum {
	eSW0 = 0,   // SW0 is summary of SW1-2-3.			
	eSW1,			
	eSW2,
    eSW3
} SWs;

typedef enum {
	eSW_off = 0,			
	eSW_on,
    eSW_pressedLong
} SW_STATUS;

typedef struct {
    SW_STATUS status;
	int16_t onTime; // Timer that counts down every 1ms
//	uint8_t on; 
} vSW_OBJECT;

typedef struct {
    vSW_OBJECT sw[NUMBER_OF_SW];
} vSWs_OBJECT;

//******************************************************************************
// VARIABLES
//******************************************************************************
#if defined _vSWITCH_C
    vSWs_OBJECT vSWsobj;
#else
    extern vSWs_OBJECT vSWsobj;
#endif

//******************************************************************************
// PROTOTYPES
//******************************************************************************
void vSWs_Check(void);    
SW_STATUS eSW_status(SWs eSW); 

#endif
