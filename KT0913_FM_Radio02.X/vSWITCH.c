/***************************************************************************//**
 * @file vSWITCH.c
 * @brief	switch menu control.
 * @author hiroshi murakami
 * @date	20231206
 *
 * This software is released under the MIT License, see LICENSE.md
 ******************************************************************************/
#define _vSWITCH_C

#include "mcc_generated_files/mcc.h"
#include "vTMR1.h"
#include "vSWITCH.h"
//#include "vSWITCH_MENU.h"

//******************************************************************************
// DEFINES
//******************************************************************************

//******************************************************************************
// VARIABLES
//******************************************************************************

//******************************************************************************
// PROTOTYPES
//******************************************************************************
void vSW_Check(vSW_OBJECT *sw, uint8_t isSW_ON);

//******************************************************************************
/**	
 * @brief	Switchs check
 * @param[in]	
 * @param[out]	
 * @details Check the status of all switches.
 *   	
 */
void vSWs_Check(void)
{
    // SW0 turns ON when any of the switches is pressed.
  	vSW_Check(&vSWsobj.sw[eSW0], (isSW1ON || isSW2ON || isSW3ON)); 
    
  	vSW_Check(&vSWsobj.sw[eSW1], isSW1ON); 
  	vSW_Check(&vSWsobj.sw[eSW2], isSW2ON); 
  	vSW_Check(&vSWsobj.sw[eSW3], isSW3ON); 

}

//******************************************************************************
/**	
 * @brief	check a Switch then set status
 * @param[in]	vSW_OBJECT, Switch No.
 * @param[out]	
 * @details 0:OFF/ 1:ON/ 2:PressedLong  
 *      Settles the SW state when the SW changes from ON to OFF.
 *      1.When SW turns ON, start counting.
 *      2.Counting while SW is ON.
 *      3.When SW turns OFF, settle the SW status.
 *    	
 */
#define SW_ON_LONGTIME		50

void vSW_Check(vSW_OBJECT *sw, uint8_t isSW_ON)
{
	if(isSW_ON) 
    {
        sw->onTime++;
        if(sw->onTime > SW_ON_LONGTIME)
        {
            sw->onTime = SW_ON_LONGTIME + 1;
//            sw->onTime = SW_ON_LONGTIME - 2;
            sw->status = eSW_pressedLong; 
        }
    } 
    else 
    {
        if(sw->onTime == 0)
        {
            sw->status = eSW_off; 
        }
        else if(sw->onTime <= SW_ON_LONGTIME)
        {
            sw->status = eSW_on; 
        }
        else
        {
            sw->status = eSW_pressedLong; 
        }
        
        sw->onTime = 0;
        
    }
}


//******************************************************************************
/**	
 * @brief	return SW status.
 * @param[in]   SWs
 * @param[out]  
 * @return  0:OFF/ 1:ON/ 2:PressedLong  
 *   	
 */
SW_STATUS eSW_status(SWs eSW)
{
    SW_STATUS status;
    
	status = vSWsobj.sw[eSW].status;
    vSWsobj.sw[eSW].status = eSW_off; 
    return status;
            
}






