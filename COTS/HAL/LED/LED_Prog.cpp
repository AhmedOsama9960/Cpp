/*
 * LED_Prog.cpp
 *
 *  Created on: May 3, 2023
 *      Author: osama
 */

#include "LED_interface.hpp"



//when we want to prevent method, we delete it immediately from the class
//LED::LED() = delete;

LED::LED( void * const Direction,   void * const port , const uint8_t Pin_Number)
:D{ Direction} ,  P { port} , P_Num { Pin_Number }
// NOTE:-> must be in the same order declared because the compiler detects them that way
{
	//set the port value to low
	MCAL_DIO.DIO_PORT_Value(P , P_Num , MCAL_DIO.low);

	//set the direction output this pattern to avoid any spark during initialization
	MCAL_DIO.DIO_DirectionSet(D, P_Num , MCAL_DIO.output);

}

void LED::Toggle_Led() const {
	//Toggle The LED Via Direct Access Memory

	MCAL_DIO.DIO_Toggle_Value(P , P_Num);
}
