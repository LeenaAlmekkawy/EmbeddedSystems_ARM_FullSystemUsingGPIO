/*********************************************/
/*********************************************/
/*********  Author: Leena Almekkawy  *********/
/*********  Layer: MCAL              *********/
/*********  SWC: Timer                ********/
/*********  Version: 1.00            *********/ 
/*********************************************/
/*********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

void _delay_ms (u32 delay_value)
{
	for(u32 i = 0 ; i<1000*delay_value ; i++ ) asm("NOP");
}


