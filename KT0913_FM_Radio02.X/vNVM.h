/***************************************************************************//**
 * @file vNVM.c
 * @brief	NVM Test.
 * @author hiroshi murakami
 * @date	20240125
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#ifndef _vNVM_H
#define _vNVM_H

#include "vKT0913.h"

//******************************************************************************
// DEFINES
//******************************************************************************

// NVM MEMORY 
#define NVM_ENTRY_SIZE 64
typedef union __attribute__ ((packed)) //__NVD
{
    uint8_t            d[NVM_ENTRY_SIZE];
    
    struct __attribute__ ((packed))
    {
        vKT0913_MEMORY_CHANNEL_OBJECT chList[CHANNEL_MAX + 1]; // 3byte * (CHANNEL_MAX=5 +1) = 18byte
        int8_t  channelNumber;
    	int8_t  speakerOnOFF;   // 1:ON 0:OFF
        int16_t volume;
        
        uint8_t nonval[NVM_ENTRY_SIZE - (18+4)];
    };

} NVM_ENTRY;

//******************************************************************************
// VARIABLES
//******************************************************************************
#if defined _vNVM_C
#else
//extern NVM_ENTRY    NVM_entry;
#endif

//******************************************************************************
// PROTOTYPES
//******************************************************************************
//NVM_ENTRY* vNVM_read (void);
NVM_ENTRY* vNVM_read(vKT0913_OBJECT *obj);
//void vNVM_save (void);
void vNVM_save (vKT0913_OBJECT *obj);

#endif



