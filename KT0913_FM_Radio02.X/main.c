/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18326
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "vLCD.h"
#include "vKT0913.h"
#include "vTMR1.h"
#include "vSWITCH.h"
#include "vSWITCH_MENU.h"
#include "vPOWER.h"

/*
                         Main application
 */


void main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();

    TMR1_SetInterruptHandler(vTMR1_CallBack);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    
    
    LCD_init();

    LCD_send_I2C(LCD_CMND, LCD_SET_LINE1_POSITION);
    sprintf(LCD_Line1, "Start LCD TEST!!");
    LCD_send_String(LCD_Line1);
    
    LCD_send_I2C(LCD_CMND, LCD_SET_LINE2_POSITION);
    sprintf(LCD_Line2, "Counter = ooooo1");
    LCD_send_String(LCD_Line2);
    
    KT0913_init();
    
    vTMR1_init();
    vTMR1_setTime(eTMR_ChannelDisplay, 100); // Set the interval to 100ms.
    vTMR1_setTime(eTMR_SW_checkInterval, 10); // Set the interval to 10ms.
    vTMR1_setWaitTime_for_NoOperation();

    vSWITCH_MENU_init();
            
    while (1)
    {
        // Add your application code
        
        vPOWER_Idle();

        if(vTMR1_isFinished(eTMR_SW_checkInterval))
        {
            vSWs_Check();    
            vSWITCH_MENU_TaskControl();
        }

        if(getSW0summaryStatus() > 0)
        {
            POWER_BACKLIGHT_ON();
            vTMR1_setTime(eTMR_BackLight, (vTMR1_NoOperation_INTERVAL-1000)); // Set the interval to 4s.
            vTMR1_setWaitTime_for_NoOperation();
        }
        
        if(vTMR1_isFinished(eTMR_BackLight))
        {
            POWER_BACKLIGHT_OFF();
        }

        if(vTMR1_isFinished(eTMR_SW_NoOperation))
        {
            SW_MENUobj.status = eSWITCH_MENU_channelDisplay1;
        }
        
        
    }
}
/**
 End of File
*/