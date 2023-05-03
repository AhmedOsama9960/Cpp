/*
 * LED_interface.hpp
 *
 *  Created on: May 3, 2023
 *      Author: osama
 */

#ifndef COTS_HAL_LED_LED_INTERFACE_HPP_
#define COTS_HAL_LED_LED_INTERFACE_HPP_


/*---------------------------------------------Include --------------------------------*/
#include "../../MCAL/DIO/DIO_MCAL_Interfaces.hpp"
/*---------------------------------------------Configs --------------------------------*/

/*---------------------------------------------APIs --------------------------------*/
class LED
{
public:
	LED() = delete;
	LED( void * const Direction,   void * const port , const uint8_t Pin_Number);

	//we should require the low level of constant in the declaration as well
	void Toggle_Led() const;
private:
	DIO_APIs MCAL_DIO;
	// the info of the LED
	void * const D;
	void * const P;
	const uint8_t P_Num;
};
/*---------------------------------------------End --------------------------------*/

#endif /* COTS_HAL_LED_LED_INTERFACE_HPP_ */
