/***************************************************************************//**
 * @file vNVM.c
 * @brief	Save the date parameters to EEPROM memory.
 * @author hiroshi murakami
 * @date	20240125
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#define _vNVM_C

#include "mcc_generated_files/mcc.h"
#include "vNVM.h"
//#include "vKT0913.h"

//#include <string.h>		// for memcpy

//******************************************************************************
// DEFINES
//******************************************************************************
NVM_ENTRY   NVM_entry;
#define     EEPADDRESS 0xF000
//#define     EEPADDRESS 0x7000

//******************************************************************************
/**
 * @brief   vNVM_save. 
 * @param[in,out]   
 * @return          
 * @details Save the value for Number of calibration & current Date & Time.
 *   1.Erase EEPROM by block. 
 *   2.save the NVM_entry data to EEPROM memory 1 byte by1.  
 *
 */
void vNVM_save (vKT0913_OBJECT *obj)
{
    uint8_t i;
    
    NVM_entry.channelNumber = obj->channelNumber;
    NVM_entry.volume = obj->volume;
    NVM_entry.speakerOnOFF = obj->speakerOnOFF;
    for (i=0; i<=CHANNEL_MAX; i++)
    {
        NVM_entry.chList[i].RSlistIdx = obj->chList[i].RSlistIdx;
        NVM_entry.chList[i].freq = obj->chList[i].freq;
    }
    
    
    FLASH_EraseBlock(EEPADDRESS);    
    for (i=0; i<NVM_ENTRY_SIZE; i++)
    {
        DATAEE_WriteByte((EEPADDRESS + i), NVM_entry.d[i]);
    }

}

//******************************************************************************
/**
 * @brief   vNVM_read. 
 * @param[in,out]   
 * @return          
 * @details read from the EEPROM memory and set to the NVM_entry data area 1 byte by1.
 *
 */
//void vNVM_read (
NVM_ENTRY* vNVM_read(vKT0913_OBJECT *obj)
{
    uint8_t i;
    for (i=0; i<NVM_ENTRY_SIZE; i++)
    {
        NVM_entry.d[i] = DATAEE_ReadByte((EEPADDRESS + i));
    }
    
    
    obj->channelNumber = NVM_entry.channelNumber;
    obj->volume = NVM_entry.volume;
    obj->speakerOnOFF = NVM_entry.speakerOnOFF;
    for (i=0; i<=CHANNEL_MAX; i++)
    {
        obj->chList[i].RSlistIdx = NVM_entry.chList[i].RSlistIdx;
        obj->chList[i].freq = NVM_entry.chList[i].freq;
    }

    
    return (NVM_ENTRY*)&NVM_entry;
}






