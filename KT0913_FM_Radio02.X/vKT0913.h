/***************************************************************************//**
 * @file vKT0913.h
 * @brief	KT0913 radio ic control
 * @author hiroshi murakami
 * @date	20231122
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/

#ifndef _vKT0913_H
#define _vKT0913_H

//#include <stdint.h>

//******************************************************************************
// DEFINES
//******************************************************************************
#define KT0913_ADDRESS 0x35
#define KT0913_REG_TUNE 0x03
#define KT0913_REG_VOLUME 0x04
#define KT0913_REG_RXCFG_VOL 0x0F
#define KT0913_REG_STATUSA_RSSI 0x12
#define KT0913_REG_STATUSB_RDCHAN 0x13
#define KT0913_REG_STATUSC_FMSNR 0x14
#define KT0913_REG_TUNE 0x03
#define CHANNEL_MIN		0
#define CHANNEL_MAX		9
#define RSLIST_MAX		87
#define VOLUME_MIN		0
#define VOLUME_MAX		0x1F    // = 31(DEC)
#define VOLUME_INIT		0x14
#define SEEK_MIN		1520    //=76.0 * 20
#define SEEK_MAX		2160    //=108.0 * 20

typedef struct {
	uint16_t freq;
	int8_t   RSlistIdx;
} vKT0913_MEMORY_CHANNEL_OBJECT;

typedef struct {
	int8_t  channelNumber;
	int8_t  swapChNumber;
	uint16_t SetFreq;
	int16_t volume;
    
	uint16_t seekFreq;
    int16_t seekADD;
    int16_t seekSUB;
	int8_t  seekStart;
    
	int8_t  speakerOnOFF;   // 1:ON 0:OFF
    
    int16_t nowFreq;        // Value is 20x
    int16_t nowRSSI;
    int16_t nowFMSNR;

    vKT0913_MEMORY_CHANNEL_OBJECT chList[CHANNEL_MAX + 1]; 
	
} vKT0913_OBJECT;

typedef struct {
	uint16_t stationFreq;
	uint8_t  stationName[15];
} vKT0913_RADIO_STATION_LIST_OBJECT;

//******************************************************************************
// VARIABLES
//******************************************************************************

#if defined _vKT0913_C
    vKT0913_OBJECT vKT0913obj;
    vKT0913_OBJECT vKT0913objPre;
    
#else
    extern vKT0913_OBJECT vKT0913obj;
    extern vKT0913_OBJECT vKT0913objPre;

#endif


//******************************************************************************
// PROTOTYPES
//******************************************************************************
void KT0913_init(void);
void KT0913_setReg(
	uint8_t reg, 
	uint16_t data
);
uint16_t KT0913_readReg(
uint8_t reg
);

void KT0913_nowFreq(void);
void KT0913_nowRssi(void);

void KT0913_muteON(void);
void KT0913_muteOFF(void);


uint16_t vKT0913_getChannelFreq(int8_t channelNumber);
uint8_t* vKT0913_getChannelName(int8_t channelNumber);
void vKT0913_set_ch_0(uint16_t freq);

void vKT0913_memorySwap(int8_t ch1,int8_t ch2);


#endif
