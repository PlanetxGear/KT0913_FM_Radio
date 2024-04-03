    /***************************************************************************//**
 * @file vKT0913.c
 * @brief	KT0913 radio ic control
 * @author hiroshi murakami
 * @date	20231122
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#define _vKT0913_C

#include "mcc_generated_files/mcc.h"
#include "vKT0913.h"
#include "vNVM.h"

//******************************************************************************
// DEFINES
//******************************************************************************

//******************************************************************************
// VARIABLES
//******************************************************************************
//vKT0913_MEMORY_CHANNEL_OBJECT vKT0913obj.chList[CHANNEL_MAX + 1]; 
vKT0913_MEMORY_CHANNEL_OBJECT vKT0913objSwqp;
    
const vKT0913_RADIO_STATION_LIST_OBJECT vKT0913_RS_list[RSLIST_MAX +1] = 
    {
        // Traditional FM   *Maximum is 128 lines.
        {(uint16_t)(76.1 * 20) , "UnknownStation"},   // 0
        {(uint16_t)(76.1 * 20) , "Inter FM      "},   // 1
        {(uint16_t)(76.5 * 20) , "Inter FM 897  "},   // 2
        {(uint16_t)(78.9 * 20) , "Shounan Beach "},   // 3
        {(uint16_t)(79.5 * 20) , "NACK5         "},   // 4
        {(uint16_t)(81.3 * 20) , "J-WAVE FM     "},   // 5
        {(uint16_t)(81.9 * 20) , "NHK FM Kanagaw"},   // 6
        {(uint16_t)(82.5 * 20) , "NHK FM Tokyo  "},   // 7
        {(uint16_t)(84.7 * 20) , "FM Yokohama   "},   // 8
        {(uint16_t)(85.9 * 20) , "FM Fuji       "},   // 9
        {(uint16_t)(86.6 * 20) , "FM TOKYO      "},   // 10
        
        // Wide FM
        {(uint16_t)(90.5 * 20) , "TBS Radio     "},   // 11
        {(uint16_t)(91.6 * 20) , "Bunka Housou  "},   // 12
        {(uint16_t)(92.4 * 20) , "Radio Nippon  "},   // 13
        {(uint16_t)(93.0 * 20) , "Nippon Housou "},   // 14

        {(uint16_t)(76.4 * 20) , "RADIO BERRY   "},
        {(uint16_t)(76.5 * 20) , "FM COCOLO     "},
        {(uint16_t)(76.8 * 20) , "FM Okayama    "},
        {(uint16_t)(77.0 * 20) , "e-radio       "},
        {(uint16_t)(77.1 * 20) , "Date FM       "},
        {(uint16_t)(77.4 * 20) , "V-air FM      "},
        {(uint16_t)(77.5 * 20) , "FM Niigata    "},
        {(uint16_t)(77.8 * 20) , "ZIP-FM        "},
        {(uint16_t)(77.9 * 20) , "FM Saga       "},
        {(uint16_t)(78.0 * 20) , "Bay FM        "},
        {(uint16_t)(78.2 * 20) , "HFM           "},
        {(uint16_t)(78.5 * 20) , "AIR-G         "},
        {(uint16_t)(78.6 * 20) , "FM Kagawa     "},
        {(uint16_t)(78.7 * 20) , "CROSS FM      "},
        {(uint16_t)(78.8 * 20) , "HousoDaigaku  "},
        {(uint16_t)(79.0 * 20) , "FM PORT       "},
        {(uint16_t)(79.2 * 20) , "K-MIX         "},
        {(uint16_t)(79.4 * 20) , "NORTH WAVE    "},
        {(uint16_t)(79.7 * 20) , "FM Nagano     "},
        {(uint16_t)(79.8 * 20) , "NORTH WAVE    "},
        {(uint16_t)(80.0 * 20) , "TOKYO FM      "},
        {(uint16_t)(80.1 * 20) , "ROK Radio Okin"},
        {(uint16_t)(80.2 * 20) , "FM802         "},
        {(uint16_t)(80.3 * 20) , "NHK FM        "},
        {(uint16_t)(80.4 * 20) , "FM Yamagata   "},
        {(uint16_t)(80.5 * 20) , "FM Ishikawa   "},
        {(uint16_t)(80.7 * 20) , "NHK FM        "},
        {(uint16_t)(81.5 * 20) , "NHK FM        "},
        {(uint16_t)(81.6 * 20) , "NHK FM        "},
        {(uint16_t)(81.8 * 20) , "Fukushima FM  "},
        {(uint16_t)(82.1 * 20) , "NORTH WAVE    "},
        {(uint16_t)(82.2 * 20) , "NHK FM        "},
        {(uint16_t)(82.3 * 20) , "NHK FM        "},
        {(uint16_t)(82.6 * 20) , "RBCi radio    "},
        {(uint16_t)(82.7 * 20) , "FM Toyama     "},
        {(uint16_t)(82.8 * 20) , "FM Akita      "},
        {(uint16_t)(83.0 * 20) , "FM FUJI       "},
        {(uint16_t)(83.1 * 20) , "AIR-G         "},
        {(uint16_t)(83.2 * 20) , "NHK FM        "},
        {(uint16_t)(83.4 * 20) , "NHK FM        "},
        {(uint16_t)(83.5 * 20) , "NHK Dai 1     "},
        {(uint16_t)(83.6 * 20) , "NHK FM        "},
        {(uint16_t)(84.0 * 20) , "NHK FM        "},
        {(uint16_t)(84.5 * 20) , "NHK FM        "},
        {(uint16_t)(84.8 * 20) , "NHK FM        "},
        {(uint16_t)(85.1 * 20) , "NHK FM        "},
        {(uint16_t)(85.2 * 20) , "NHK FM        "},
        {(uint16_t)(85.3 * 20) , "NHK FM        "},
        {(uint16_t)(85.4 * 20) , "NHK FM        "},
        {(uint16_t)(85.6 * 20) , "NHK FM        "},
        {(uint16_t)(85.7 * 20) , "NHK FM        "},
        {(uint16_t)(85.8 * 20) , "NHK FM        "},
        {(uint16_t)(86.0 * 20) , "NHK FM        "},
        {(uint16_t)(86.2 * 20) , "NHK FM        "},
        {(uint16_t)(86.3 * 20) , "FM Gunma      "},
        {(uint16_t)(86.4 * 20) , "AIR-G         "},
        {(uint16_t)(86.5 * 20) , "NHK FM        "},
        {(uint16_t)(86.7 * 20) , "NHK FM        "},
        {(uint16_t)(87.0 * 20) , "NHK FM        "},
        {(uint16_t)(87.3 * 20) , "FM Okayama    "},
        {(uint16_t)(87.4 * 20) , "NHK FM        "},
        {(uint16_t)(87.5 * 20) , "NHK FM        "},
        {(uint16_t)(87.7 * 20) , "NHK FM        "},
        {(uint16_t)(88.0 * 20) , "NHK FM        "},
        {(uint16_t)(88.1 * 20) , "NHK FM        "},
        {(uint16_t)(88.3 * 20) , "NHK FM        "},
        {(uint16_t)(88.5 * 20) , "NHK FM        "},
        {(uint16_t)(88.7 * 20) , "NHK FM        "},
        {(uint16_t)(88.8 * 20) , "NHK FM        "},
        {(uint16_t)(88.9 * 20) , "NHK FM        "},
        {(uint16_t)(89.1 * 20) , "AFN           "},
        {(uint16_t)(89.4 * 20) , "AIR-G         "},
        {(uint16_t)(89.9 * 20) , "Kiss-FM KOBE  "}

};

    
//******************************************************************************
// PROTOTYPES
//******************************************************************************
void KT0913_initMemory(void);

//******************************************************************************
// initialize
//******************************************************************************
void KT0913_init(void)
{
    KT0913_initMemory();

//    vKT0913obj.channelNumber = 0;
//    vKT0913obj.volume = VOLUME_INIT;
    vKT0913obj.SetFreq = vKT0913obj.chList[vKT0913obj.channelNumber].freq;
    
    vKT0913objPre.channelNumber = vKT0913obj.channelNumber;
    vKT0913objPre.SetFreq = vKT0913obj.SetFreq;
    vKT0913objPre.volume = vKT0913obj.volume;

    KT0913_setReg(0x16, 0x0002);            // Clock 32.768KHz
    KT0913_setReg(0x03, vKT0913obj.SetFreq | 0x8000); // FM Tune Trigger 81.3MHz
    KT0913_setReg(0x04, 0xE180);            // Mute Disable, Bass Low
    KT0913_setReg(0x0A, 0x0100);            // AFC disEnable
    KT0913_setReg(0x05, 0x9820);            // Mono 50us
    KT0913_setReg(0x22, 0xAF0C);            // Left channel inverse control
    KT0913_setReg(0x0F, vKT0913obj.volume | 0x8800);           // Volume 
 
//    vKT0913obj.speakerOnOFF = 1;            // speaker ON
    
}

//******************************************************************************
// KT0913 2byte output control
//******************************************************************************
void KT0913_setReg(
	uint8_t reg, 
	uint16_t data
)
{
    uint8_t tbuf[3];
    tbuf[0] = reg;
    tbuf[1] = (data >> 8) & 0xFF;
    tbuf[2] = data & 0xFF;
    
    while(!I2C1_Open(KT0913_ADDRESS)); // sit here until we get the bus..
    I2C1_SetBuffer(tbuf,3);
//    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
//    __delay_us(30);

}

static i2c1_operations_t rd2RegCompleteHandler(void *ptr)
{
    I2C1_SetBuffer(ptr,2);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_RESTART_READ;
}

//******************************************************************************
// KT0913 2byte read control
//******************************************************************************
uint16_t KT0913_readReg(
uint8_t reg
)
{
    uint16_t returnValue =0x00; // returnValue is little endian

    while(!I2C1_Open(KT0913_ADDRESS)); // sit here until we get the bus..
    I2C1_SetDataCompleteCallback(rd2RegCompleteHandler,&returnValue);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
  
    return (returnValue << 8 | returnValue >> 8);
}

//******************************************************************************
// KT0913 get now Freq & RSSI from register
//******************************************************************************
void KT0913_nowFreq(void)
{
    int16_t fmchan;

    fmchan = KT0913_readReg(KT0913_REG_STATUSB_RDCHAN);
    vKT0913obj.nowFreq = (fmchan & 0x0FFF) * 5;  // Value is 100x
    
}

void KT0913_nowRssi(void)
{
    uint16_t statusa;
    int16_t st, stc, fmrssi, fmsnr;

    statusa = KT0913_readReg(KT0913_REG_STATUSA_RSSI);
    st     = (statusa & 0x0300) >> 8;   // stereo indicator
    stc    = (statusa & 0x4000)>> 14;   // seek/tune complete flag. 1=complete 
    fmrssi = (statusa & 0x00F8) >> 3;
    fmrssi = fmrssi * 3 -100;
    

    statusa = KT0913_readReg(KT0913_REG_STATUSC_FMSNR);
    fmsnr = (statusa & 0x1FC0) >> 6;
    
    if (stc == 1)
    {
        vKT0913obj.nowRSSI = (vKT0913obj.nowRSSI + fmrssi) / 2;
        vKT0913obj.nowFMSNR = (vKT0913obj.nowFMSNR + fmsnr) / 2;
    }

}

//******************************************************************************
// mute ON OFF
//******************************************************************************
void KT0913_muteON(void)
{
    KT0913_setReg(KT0913_REG_VOLUME, 0x4280);   // Mute Disable, Bass Med    
}
void KT0913_muteOFF(void)
{
    KT0913_setReg(KT0913_REG_VOLUME, 0xE280);   // Mute Disable, Bass Med    
}

//******************************************************************************
// memory operation
//******************************************************************************

void KT0913_initMemory(void)
{
    int8_t i,j;
    
    vNVM_read(&vKT0913obj);
    if(
       (vKT0913obj.channelNumber <= CHANNEL_MAX) &&
       (vKT0913obj.channelNumber >= 0)
       )
    {
        return;
    }

    vKT0913obj.chList[0].freq = 82.5 * 20;  // NHK FM Tokyo
    vKT0913obj.chList[1].freq = 82.5 * 20;  // NHK FM Tokyo 
    vKT0913obj.chList[2].freq = 79.5 * 20;  // "NACK5 
    vKT0913obj.chList[3].freq = 81.3 * 20;  // "J-WAVE FM   
    vKT0913obj.chList[4].freq = 86.6 * 20;  // "FM TOKYO  
    vKT0913obj.chList[5].freq = 90.5 * 20;  // "TBS Radio  
    vKT0913obj.chList[6].freq = 91.6 * 20;  // "Bunka Housou  
    vKT0913obj.chList[7].freq = 92.4 * 20;  // "Radio Nippon  
    vKT0913obj.chList[8].freq = 93.0 * 20;  // "Nippon Housou  
    vKT0913obj.chList[9].freq = 80.0 * 20;  // "Tokyo FM  

    for (i=0; i <= CHANNEL_MAX ; i++)
    {
        vKT0913obj.chList[i].RSlistIdx = 0;
        for (j=RSLIST_MAX; j>=0 ; j--)
        {
            if (vKT0913obj.chList[i].freq == vKT0913_RS_list[j].stationFreq) 
            {
                vKT0913obj.chList[i].RSlistIdx = j;
            }
        }
    }

    vKT0913obj.channelNumber = 0;
    vKT0913obj.volume = VOLUME_INIT;
    vKT0913obj.speakerOnOFF = 1;            // speaker ON

}

void vKT0913_memorySwap(int8_t ch1,int8_t ch2)
{
    vKT0913objSwqp.RSlistIdx = vKT0913obj.chList[ch1].RSlistIdx;;
    vKT0913objSwqp.freq      = vKT0913obj.chList[ch1].freq;
    
    vKT0913obj.chList[ch1].RSlistIdx = vKT0913obj.chList[ch2].RSlistIdx;;
    vKT0913obj.chList[ch1].freq = vKT0913obj.chList[ch2].freq;

    vKT0913obj.chList[ch2].RSlistIdx = vKT0913objSwqp.RSlistIdx;;
    vKT0913obj.chList[ch2].freq = vKT0913objSwqp.freq;
}


//******************************************************************************
// channel operation
//******************************************************************************

uint16_t vKT0913_getChannelFreq(int8_t channelNumber)
{
   return vKT0913obj.chList[channelNumber].freq;   
}

uint8_t* vKT0913_getChannelName(int8_t channelNumber)
{
   return vKT0913_RS_list[vKT0913obj.chList[channelNumber].RSlistIdx].stationName;   
}

void vKT0913_set_ch_0(uint16_t freq)
{
    uint8_t i;
    vKT0913obj.chList[0].freq = freq;
    vKT0913obj.chList[0].RSlistIdx = 0;
    
    // search RADIO_STATION_LIST & get index
    for (i=0; i<=RSLIST_MAX ; i++)
    {
        if (vKT0913_RS_list[i].stationFreq == freq) 
        {
            vKT0913obj.chList[0].RSlistIdx = i; 
            return;
        }
    }
    
}

