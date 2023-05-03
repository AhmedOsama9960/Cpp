/*
 * DIO_MCAL_Prog.cpp
 *
 *  Created on: May 2, 2023
 *      Author: osama
 */


/*---------------------------------------------Include --------------------------------*/
#include "DIO_MCAL_Interfaces.hpp"
#include <stdexcept>
//#include <exception>
/*---------------------------------------------Implementation --------------------------------*/
void DIO_APIs::DIO_DirectionSet(void * const Dir, const uint8_t PinNumber , uint8_t status)
{
	if(status == input)
	{
		* reinterpret_cast<volatile Machine_Arch * const>(Dir) &= ~PinNumber;
	} else if(status == output)
	{
		* reinterpret_cast<volatile Machine_Arch * const>(Dir) |= PinNumber;
	} else {
		throw std::invalid_argument("Wrong Direction Entered");
	}
}

void DIO_APIs::DIO_PORT_Value(void * const port, const uint8_t PinNumber , uint8_t Value)
{
	if(Value == High)
	{
		* reinterpret_cast<volatile Machine_Arch * const>(port) &= ~PinNumber;
	} else if(Value == low) {

		* reinterpret_cast<volatile Machine_Arch * const>(port) |= PinNumber;
	} else {
		throw std::invalid_argument("Wrong PortValue Entered");
		//throw "Wrong PortValue Entered";
	}
}

void DIO_APIs::DIO_Toggle_Value( void * const port, const uint8_t PinNumber) const
{
	* reinterpret_cast<volatile Machine_Arch * const>(port) ^= PinNumber;
}


/*---------------------------------------------End --------------------------------*/
