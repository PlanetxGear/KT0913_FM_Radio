/***************************************************************************//**
 * @file vSWITCH_MENU.c
 * @brief	switchs menu
 * @author hiroshi murakami
 * @date	20231209
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#define _vSWITCH_MENU_C

#include "mcc_generated_files/mcc.h"
#include "vTMR1.h"
#include "vSWITCH.h"
#include "vSWITCH_MENU.h"
#include "vKT0913.h"
#include "vLCD.h"
#include "vPOWER.h"
#include "vNVM.h"

//******************************************************************************
// DEFINES
//******************************************************************************

//******************************************************************************
// VARIABLES
//******************************************************************************

//******************************************************************************
// PROTOTYPES
//******************************************************************************


//******************************************************************************
/**	
 * @brief	vSWITCH_MENU_init.
 * @param[in]   -
 * @param[out]  -
 * @details
 *  menu initialize.
 *   	
 */
void vSWITCH_MENU_init(void)
{
	SW_MENUobj.status = eSWITCH_MENU_channelSet;
}



//******************************************************************************
/**
 * @brief   vSWITCH_MENU_TaskControl.
 * @param[in]   SW_MENUobj
 * @param[out]  SW_MENUobj
 * @details
 *
 */
void vSWITCH_MENU_TaskControl(void)
{
    SW_STATUS sw2up, sw3down;
    
    
	switch (SW_MENUobj.status) 
    {

        // *** channel select ************************
        case 	eSWITCH_MENU_channelSet:
            KT0913_setReg(KT0913_REG_TUNE, vKT0913_getChannelFreq(vKT0913obj.channelNumber) | 0x8000); // FM Tune 
            KT0913_nowFreq();

            SW_MENUobj.status++;        
            break;

        case 	eSWITCH_MENU_channelDisplay1:
            sprintf(LCD_Line1, "%s%s%1d", vKT0913_getChannelName(vKT0913obj.channelNumber),"M",vKT0913obj.channelNumber);
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
            LCD_send_String(LCD_Line1);
            
            SW_MENUobj.status++;        
            break;

        case 	eSWITCH_MENU_channelDisplay2:
            KT0913_nowRssi();
            
            sprintf(LCD_Line2, "%2d.%02dMHz  %3ddBm",vKT0913obj.nowFreq/100, vKT0913obj.nowFreq%100, vKT0913obj.nowRSSI);
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE2_POSITION);
            LCD_send_String(LCD_Line2);

            SW_MENUobj.status++;
            break;

        case 	eSWITCH_MENU_channelSelect:
            vKT0913obj.channelNumber = iAddNumber(vKT0913obj.channelNumber, getSW2upStatus(), CHANNEL_MIN, CHANNEL_MAX);
            vKT0913obj.channelNumber = iSubNumber(vKT0913obj.channelNumber, getSW3downStatus(), CHANNEL_MIN, CHANNEL_MAX);

            if(getSW1menuStatus())
            {
                SW_MENUobj.status++;
            }
            else if (vKT0913objPre.channelNumber != vKT0913obj.channelNumber)
            {
                SW_MENUobj.status = eSWITCH_MENU_channelSet;
                vKT0913objPre.channelNumber = vKT0913obj.channelNumber;
            }
            else if(vTMR1_isFinished(eTMR_ChannelDisplay))
            {
                SW_MENUobj.status = eSWITCH_MENU_channelDisplay2;
            }

            break;
        // *** channel select ************************



        // *** volume ************************
        case	eSWITCH_MENU_volumeDisplay:

            KT0913_setReg(KT0913_REG_RXCFG_VOL, vKT0913obj.volume | 0x8800); // FM Tune 
            vKT0913objPre.volume = vKT0913obj.volume;

            sprintf(LCD_Line1, "VOLUME (0-31max)" );
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
            LCD_send_String(LCD_Line1);

            sprintf(LCD_Line2, "VOLUME = %3d     ", vKT0913obj.volume);
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE2_POSITION);
            LCD_send_String(LCD_Line2);

            SW_MENUobj.status++;
            break;

        case	eSWITCH_MENU_volume:
            vKT0913obj.volume = vKT0913obj.volume + getSW2upStatus();
            if (vKT0913obj.volume > VOLUME_MAX)
            {
                vKT0913obj.volume = VOLUME_MAX;
            }

            vKT0913obj.volume = vKT0913obj.volume - getSW3downStatus();
            if (vKT0913obj.volume < VOLUME_MIN)
            {
                vKT0913obj.volume = VOLUME_MIN;
            }

            if (vKT0913objPre.volume != vKT0913obj.volume)
            {
                SW_MENUobj.status = eSWITCH_MENU_volumeDisplay;
            }

            if(getSW1menuStatus())
            {
                SW_MENUobj.status++;
            }
            break;
        // *** volume ************************



        // *** power Off ************************
        case	eSWITCH_MENU_powerOffSet1:
            vTMR1_setTime(eTMR_PowerOff, 1000); // Set the interval to 1s.
            vPOWERobj.countDown = 3;

            SW_MENUobj.status++;
            break;

        case	eSWITCH_MENU_powerOffCountDown:
            vTMR1_setWaitTime_for_NoOperation();
            
            sprintf(LCD_Line1, "== POWER OFF ===");
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
            LCD_send_String(LCD_Line1);

            sprintf(LCD_Line2, "=====  %3d  =====", vPOWERobj.countDown);
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE2_POSITION);
            LCD_send_String(LCD_Line2);

            if(vTMR1_isFinished(eTMR_PowerOff))
            {
                vPOWERobj.countDown--;
                
            }

            if(vPOWERobj.countDown <= 0)
            {
                SW_MENUobj.status = eSWITCH_MENU_powerOff;
            }
            else if(getSW1menuStatus()) 
            {
                SW_MENUobj.status = eSWITCH_MENU_powerOff +1;   // Next Menu
            }
            else
            {
                vPOWERobj.countDown = vPOWERobj.countDown + getSW2upStatus();
                if (vPOWERobj.countDown > COUNTDOWN_MAX)
                {
                    vPOWERobj.countDown = COUNTDOWN_MAX;
                }

                vPOWERobj.countDown = vPOWERobj.countDown - getSW3downStatus();
                if (vPOWERobj.countDown < COUNTDOWN_MIN)
                {
                    vPOWERobj.countDown = COUNTDOWN_MIN;
                }
            }

            break;

        case	eSWITCH_MENU_powerOff:
            vNVM_save(&vKT0913obj);
            
            vPOWER_Off();
            vSWs_Check();
            
            LCD_init();
            KT0913_init();
            
            SW_MENUobj.status = eSWITCH_MENU_channelSet;
            break;
        // *** power Off ************************



        // *** speaker ON/OFF ************************
        case	eSWITCH_MENU_speakerOnOffStart:
            sprintf(LCD_Line1, "=SPEAKER ON/OFF=");
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
            LCD_send_String(LCD_Line1);
            
        case	eSWITCH_MENU_speakerOnOffDisplay:
            if (vKT0913obj.speakerOnOFF == 1 )
            {
                sprintf(LCD_Line2, "====== ON ======");
            }
            else
            {
                sprintf(LCD_Line2, "====== OFF =====");
            }
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE2_POSITION);
            LCD_send_String(LCD_Line2);

            SW_MENUobj.status++;
            break;

        case	eSWITCH_MENU_speakerOnOff:
            if(getSW1menuStatus())
            {
                SW_MENUobj.status++;
            }
            else
            {
                vKT0913obj.speakerOnOFF = iAddNumber(vKT0913obj.speakerOnOFF, getSW2upStatus(), 0, 1);
                vKT0913obj.speakerOnOFF = iSubNumber(vKT0913obj.speakerOnOFF, getSW3downStatus(), 0, 1);

                if (vKT0913obj.speakerOnOFF == 1 )
                {
                    POWER_AMP_ON();
                }
                else
                {
                    POWER_AMP_OFF();
                }
                
                if (vKT0913objPre.speakerOnOFF != vKT0913obj.speakerOnOFF )
                {
                    vKT0913objPre.speakerOnOFF = vKT0913obj.speakerOnOFF;
                    SW_MENUobj.status = eSWITCH_MENU_speakerOnOffDisplay;
                    
                }

            }
            
            break;
        // *** speaker ON/OFF ************************



        // *** seek1 ************************
        case 	eSWITCH_MENU_seek1Set1:
            vKT0913obj.seekFreq = vKT0913_getChannelFreq(vKT0913obj.channelNumber);
            vKT0913objPre.seekFreq = vKT0913obj.seekFreq;
            vKT0913obj.seekADD = 0;
            vKT0913obj.seekSUB = 0;
            vKT0913obj.seekStart = 0;

            SW_MENUobj.status++;
            break;
            
        case 	eSWITCH_MENU_seek1SetFreq:
            
            // ***** check check check !!! *****
            // ***** check check check !!! *****
            vTMR1_setWaitTime_for_NoOperation();
            // ***** check check check !!! *****
            // ***** check check check !!! *****
            
            vKT0913obj.seekFreq = iAddNumber(vKT0913obj.seekFreq, vKT0913obj.seekADD, SEEK_MIN, SEEK_MAX);
            vKT0913obj.seekFreq = iSubNumber(vKT0913obj.seekFreq, vKT0913obj.seekSUB, SEEK_MIN, SEEK_MAX);
            if(vKT0913objPre.seekFreq != vKT0913obj.seekFreq)
            {
                KT0913_setReg(KT0913_REG_TUNE, vKT0913obj.seekFreq | 0x8000); // FM Tune 
                vKT0913objPre.seekFreq = vKT0913obj.seekFreq;
                KT0913_nowFreq();
                
                vKT0913obj.channelNumber = 0;           // set ch 0
                vKT0913_set_ch_0(vKT0913obj.seekFreq);  // set ch 0

            }

            SW_MENUobj.status++;
            break;

        case 	eSWITCH_MENU_seek1Display:

            sprintf(LCD_Line1, "==Seek== SN%2ddBm", vKT0913obj.nowFMSNR);
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
            LCD_send_String(LCD_Line1);

            sprintf(LCD_Line2, "%2d.%02dMHz  %3ddBm",vKT0913obj.nowFreq/100, vKT0913obj.nowFreq%100, vKT0913obj.nowRSSI);
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE2_POSITION);
            LCD_send_String(LCD_Line2);

            vTMR1_setTime(eTMR_ChannelDisplay, 100); // Set the interval to 100ms.
                        
            SW_MENUobj.status++;
            break;

        case 	eSWITCH_MENU_seek1Check:
            if(getSW1menuStatus() == eSW_on)
            {
                SW_MENUobj.status ++;
            }
            else
            {
                KT0913_nowRssi();

                if(vKT0913obj.seekStart == 0)
                {
                    vKT0913obj.seekADD = 0;
                    vKT0913obj.seekSUB = 0;
                }
                else if(
//                        (vKT0913obj.nowRSSI >  -80) &&
//                        (vKT0913obj.nowFMSNR >  40) 
                        (vKT0913obj.nowFMSNR >  37) 
                       )
                {
                    vKT0913obj.seekStart = 0;
                    vKT0913obj.seekSUB = 0;
                    vKT0913obj.seekADD = 0;
                    KT0913_muteOFF();
                }
            
            
                sw2up = getSW2upStatus();
                sw3down = getSW3downStatus();

                if (sw2up == eSW_on)
                {
                    vKT0913obj.seekADD = 2;
                    vKT0913obj.seekSUB = 0;
                    vKT0913obj.seekStart = 0;
                } 
                else if(sw3down == eSW_on)
                {
                    vKT0913obj.seekADD = 0;
                    vKT0913obj.seekSUB = 2;
                    vKT0913obj.seekStart = 0;
                }
                else if(sw2up == eSW_pressedLong)
                {
                    vKT0913obj.seekADD = 2;
                    vKT0913obj.seekSUB = 0;
                    vKT0913obj.seekStart = 1;
                    KT0913_muteON();
                }
                else if(sw3down == eSW_pressedLong)
                {
                    vKT0913obj.seekADD = 0;
                    vKT0913obj.seekSUB = 2;
                    vKT0913obj.seekStart = 1;
                    KT0913_muteON();
                }

                if(vKT0913obj.seekStart == 1)
                {
                    if(vTMR1_isFinished(eTMR_ChannelDisplay))
                    {
                        SW_MENUobj.status = eSWITCH_MENU_seek1SetFreq;
                    }
                }
                else if(vKT0913obj.seekADD != vKT0913obj.seekSUB)
                {
                        SW_MENUobj.status = eSWITCH_MENU_seek1SetFreq;
                }
                else if(vTMR1_isFinished(eTMR_ChannelDisplay))
                {
                    SW_MENUobj.status = eSWITCH_MENU_seek1Display;
                }
                            
            }


            break;
        // *** seek1 ************************




        // *** memory Swap ************************
        case 	eSWITCH_MENU_memorySwap1Title:
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
            sprintf(LCD_Line1, "==MEMORY SWAP===");
            LCD_send_String(LCD_Line1);
            
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE2_POSITION);
            sprintf(LCD_Line2, "%s%s%1d", vKT0913_getChannelName(vKT0913obj.channelNumber),"M",vKT0913obj.channelNumber);
            LCD_send_String(LCD_Line2);
            
            vKT0913obj.swapChNumber = vKT0913obj.channelNumber;
            vTMR1_setTime(eTMR_ChannelDisplay, (vTMR1_NoOperation_INTERVAL - 300)); // This is the time it takes for the SWAP to be finalized. See *Ref-1
            
            SW_MENUobj.status = eSWITCH_MENU_memorySwapSelect;        
            break;

        case 	eSWITCH_MENU_memorySwap2:
            LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
            sprintf(LCD_Line1, "%s%s%1d", vKT0913_getChannelName(vKT0913obj.swapChNumber),"M",vKT0913obj.swapChNumber);
            LCD_send_String(LCD_Line1);
            
            vTMR1_setTime(eTMR_ChannelDisplay, (vTMR1_NoOperation_INTERVAL - 300)); // This is the time it takes for the SWAP to be finalized. See *Ref-1
            SW_MENUobj.status++;        
            break;

        case 	eSWITCH_MENU_memorySwapSelect:
            vKT0913obj.swapChNumber = iAddNumber(vKT0913obj.swapChNumber, getSW2upStatus(), CHANNEL_MIN, CHANNEL_MAX);
            vKT0913obj.swapChNumber = iSubNumber(vKT0913obj.swapChNumber, getSW3downStatus(), CHANNEL_MIN, CHANNEL_MAX);

            if(getSW1menuStatus())                                              // SWAP finalizing.
            {
                vKT0913_memorySwap(vKT0913obj.channelNumber,vKT0913obj.swapChNumber);
                vKT0913obj.channelNumber = vKT0913obj.swapChNumber;
                SW_MENUobj.status++;                                            // go to Nest Menu.
            }
            else if (vKT0913objPre.swapChNumber != vKT0913obj.swapChNumber)
            {
                SW_MENUobj.status = eSWITCH_MENU_memorySwap2;
                vKT0913objPre.swapChNumber = vKT0913obj.swapChNumber;
            }

            else if(vTMR1_isFinished(eTMR_ChannelDisplay))                      // SWAP finalizing. *Ref-1
            {
                vKT0913_memorySwap(vKT0913obj.channelNumber,vKT0913obj.swapChNumber);
                vKT0913obj.channelNumber = vKT0913obj.swapChNumber;
                SW_MENUobj.status = eSWITCH_MENU_channelDisplay1;               // go to Nest Menu.
            }


            
            break;
        // *** memory Swap ************************

            
            

        case	eSWITCH_MENU_end:
            SW_MENUobj.status = eSWITCH_MENU_channelSet;
            break;

        case 	eSWITCH_MENU_error:
            break;

        default:
            SW_MENUobj.status = eSWITCH_MENU_end;
            break;
	}

}

//******************************************************************************
/**
 * @brief   iAddNumber.
 * @param[in]   iNowNumber, Original value.
 *               iAddNumber, Addition value.
 *               iMinNumber, Minimum value for range specification.
 *               iMaxNumber  Maximum value for range specification.
 * @param[out]  -
 * @return      iNowNumber + iAddNumber
 * @details
 *  Used for setting the time and date.
 *  Receive the time / number, add it within the specified range, and reply.
 *  If the result of adding the time and number exceeds the specified range, 
 *  the minimum value is returned.
 */
int16_t iAddNumber(
    int16_t iNowNumber, 
    int16_t iAddNumber, 
    int16_t iMinNumber, 
    int16_t iMaxNumber
)
{
	iNowNumber = iNowNumber + iAddNumber;
	if(iNowNumber > iMaxNumber)
    {
		return iMinNumber;
	}
    else
    {
		return iNowNumber;
	}

}

//******************************************************************************
/**
 * @brief   iSubNumber.
 * @param[in]   iNowNumber, Original value.
 *               iSubNumber, Subtraction value.
 *               iMinNumber, Minimum value for range specification.
 *               iMaxNumber  Maximum v\alue for range specification.
 * @param[out]  -
 * @return      iNowNumber - iSubNumber
 * @details
 *  For setting the time and date.
 *  Receive the time / number, subtract within the specified range and reply.
 *  If the result of subtracting the time / number exceeds the specified range, 
 *  the maximum value is returned.
 */
int16_t iSubNumber(
    int16_t iNowNumber, 
    int16_t iSubNumber, 
    int16_t iMinNumber, 
    int16_t iMaxNumber
)
{
	iNowNumber = iNowNumber - iSubNumber;
	if(iNowNumber < iMinNumber)
    {
		return iMaxNumber;
	}
    else
    {
		return iNowNumber;
	}
}

