/***************************************************************************//**
 * @file vSWITCH_MENU.h
 * @brief	switchs menu
 * @author hiroshi murakami
 * @date	20231209
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#ifndef _vSWITCH_MENU_H
#define _vSWITCH_MENU_H

//******************************************************************************
// DEFINES
//******************************************************************************
// switch menu status
typedef enum {
	eSWITCH_MENU_channelSet = 0,
	eSWITCH_MENU_channelDisplay1,
	eSWITCH_MENU_channelDisplay2,
	eSWITCH_MENU_channelSelect,	

	eSWITCH_MENU_volumeDisplay,	
	eSWITCH_MENU_volume,

	eSWITCH_MENU_powerOffSet1,
	eSWITCH_MENU_powerOffCountDown,
    eSWITCH_MENU_powerOff,

	eSWITCH_MENU_speakerOnOffStart,	
	eSWITCH_MENU_speakerOnOffDisplay,	
	eSWITCH_MENU_speakerOnOff,

	eSWITCH_MENU_seek1Set1,
	eSWITCH_MENU_seek1SetFreq,
	eSWITCH_MENU_seek1Display,
	eSWITCH_MENU_seek1Check,


	eSWITCH_MENU_memorySwap1Title,
	eSWITCH_MENU_memorySwap2,
	eSWITCH_MENU_memorySwapSelect,
            

            
    eSWITCH_MENU_end,
	eSWITCH_MENU_error = -1
} SWITCH_MENU_STATUS;

typedef struct {
	SWITCH_MENU_STATUS status;
//	SWITCH_MENU_STATUS jump;
} SW_MENUobjECT;

//******************************************************************************
// VARIABLES
//******************************************************************************
#if defined _vSWITCH_MENU_C
    SW_MENUobjECT SW_MENUobj;
#else
	extern SW_MENUobjECT SW_MENUobj;
#endif

//******************************************************************************
// PROTOTYPES
//******************************************************************************
void vSWITCH_MENU_init(void);
void vSWITCH_MENU_TaskControl(void);	// LCD menu control

int16_t iAddNumber(int16_t iNowNumber, int16_t iAddNumber, int16_t iMinNumber, int16_t iMaxNumber);
int16_t iSubNumber(int16_t iNowNumber, int16_t iSubNumber, int16_t iMinNumber, int16_t iMaxNumber);

#endif
