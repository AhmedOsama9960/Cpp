/*
 * DIO_MCAL_Interfaces.hpp
 *
 *  Created on: May 2, 2023
 *      Author: osama
 */


/*---------------------------------------------Include --------------------------------*/
#include <cstdint>
/*---------------------------------------------Configurations --------------------------------*/

typedef uint8_t	Machine_Arch;		// depends on the Machine Arch if 8bits or 16, etc.
/*---------------------------------------------Namespaces --------------------------------*/

namespace MCAL
{
	namespace DIO_Regs
	{
	// The address of portb
		constexpr Machine_Arch DIR_A = 0x1A;
		constexpr Machine_Arch PORTA = 0x1B;

		// The values of bit0 through bit7.
		constexpr uint8_t PinA0 = 0x01U;
		constexpr uint8_t PinA1 = 0x02U;
		constexpr uint8_t PinA2 = 0x04U;
		constexpr uint8_t PinA3 = 0x08U;
		constexpr uint8_t PinA4 = 0x10U;
		constexpr uint8_t PinA5 = 0x20U;
		constexpr uint8_t PinA6 = 0x40U;
		constexpr uint8_t PinA7 = 0x80U;

	} // DIO_Regs

} //MCAL

/*---------------------------------------------APIs --------------------------------*/

class DIO_APIs{

public:
void DIO_DirectionSet( void * const Dir, const uint8_t PinNumber , uint8_t status);

void DIO_PORT_Value( void * const port, const uint8_t PinNumber , uint8_t Value);

void DIO_Toggle_Value( void * const port, const uint8_t PinNumber) const;

public:

static constexpr uint8_t input = 0;
static constexpr uint8_t output = 1;

static constexpr uint8_t low = 0;
static constexpr uint8_t High = 1;
};
/*---------------------------------------------End --------------------------------*/

