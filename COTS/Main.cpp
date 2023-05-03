/*
 * Main.cpp
 *
 *  Created on: May 3, 2023
 *      Author: osama
 */

#include "HAL/LED/LED_interface.hpp"



//unamed namespace initialize the interal members as global static ones
namespace
{
	const LED led_Pin5 {
		reinterpret_cast<void *>(MCAL::DIO_Regs::DIR_A),
		reinterpret_cast<void *>(MCAL::DIO_Regs::PORTA),
		MCAL::DIO_Regs::PinA5
	};
} // Global unnamed namespace


int main(void)
{
	//Toggle the led in pin 5 forever
	for(;;){
	led_Pin5.Toggle_Led();		//Elhamdullah a5eern
	}
	return 0;
}


