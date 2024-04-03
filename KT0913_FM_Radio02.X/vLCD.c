/*******************************************************************************
 *	I2C LCD control <AQM1602Y-RN-GBW>
 *	I2C1 use
 *	author  :hiroshi murakami
 *	created :20231122
 *	modified:-
 ******************************************************************************/
#define _vLCD_C


#include "mcc_generated_files/mcc.h"

#include "vLCD.h"


void LCD_send_I2C(int8_t cmd, int8_t data)
{
    int8_t tbuf[2];
    tbuf[0] = cmd;
    tbuf[1] = data;
    
    while(!I2C1_Open(LCD_ADDRESS)); // sit here until we get the bus..
    I2C1_SetBuffer(tbuf,2);
//    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
//    __delay_us(30);

}

void LCD_send_String(int8_t *disp)
{
    while(*disp != 0)
        LCD_send_I2C(LCD_DATA, *disp++);
    
}

void LCD_init(void)
{
    __delay_ms(150);
    LCD_send_I2C(LCD_CMND, LCD_FUNCTION_SET_NORMAL);
    LCD_send_I2C(LCD_CMND, LCD_FUNCTION_SET_EXTEND);
    LCD_send_I2C(LCD_CMND, LCD_INTERNAL_OSC_FREQUENCY);
    LCD_send_I2C(LCD_CMND, LCD_CONTRAST_SET);
    LCD_send_I2C(LCD_CMND, LCD_POWER_ICON_CONTRAST);
    LCD_send_I2C(LCD_CMND, LCD_FOLLOWER_CONTROL);
    __delay_ms(300);
    LCD_send_I2C(LCD_CMND, LCD_FUNCTION_SET_NORMAL);
    LCD_send_I2C(LCD_CMND, LCD_DISPLAY_ON);
    LCD_send_I2C(LCD_CMND, LCD_CLEAR_DISPLAY);
    __delay_ms(2);
    
}
    
    
    
