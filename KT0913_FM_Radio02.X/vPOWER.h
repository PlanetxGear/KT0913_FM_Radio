/***************************************************************************//**
 * @file vPOWER.h
 * @brief	power control.
 * @author hiroshi murakami
 * @date	20231230
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#ifndef _vPOWER_H
#define _vPOWER_H

//******************************************************************************
// DEFINES
//******************************************************************************
#define POWER_AMP_ON()          POWER_AMP_SetHigh()
#define POWER_AMP_OFF()         POWER_AMP_SetLow()  
#define POWER_BACKLIGHT_ON()    POWER_BACKLIGHT_SetLow() 
#define POWER_BACKLIGHT_OFF()   POWER_BACKLIGHT_SetHigh()
#define POWER_RADIO_LCD_ON()    POWER_RADIO_LCD_SetHigh() 
#define POWER_RADIO_LCD_OFF()   POWER_RADIO_LCD_SetLow()

#define COUNTDOWN_MIN		0
#define COUNTDOWN_MAX		10    // 10sec

typedef struct {
	uint16_t countDown;
} vPOWER_OBJECT;


//******************************************************************************
// STATE
//******************************************************************************

//******************************************************************************
// VARIABLES
//******************************************************************************
#if defined _vPOWER_C
    vPOWER_OBJECT vPOWERobj;

#else
    extern vPOWER_OBJECT vPOWERobj;

#endif

//******************************************************************************
// PROTOTYPES
//******************************************************************************
void vPOWER_Off(void);
void vPOWER_Idle(void);

#endif