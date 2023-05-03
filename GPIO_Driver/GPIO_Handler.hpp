///*
// * GPIO_Handler.hpp
// *
// *  Created on: Mar 14, 2023
// *      Author: osama
// */
//
//#ifndef GPIO_DRIVER_GPIO_HANDLER_HPP_
//#define GPIO_DRIVER_GPIO_HANDLER_HPP_
//
//
//#include "RegisterMgr.hpp"
//#include <type_traits>
//
//
//class GPIO_Handler
//{
//public:
//	GPIO_Handler() noexcept = default;		//Default COTR
//
//	// Write a register value by PinNumber
//	void Write(const std::string& RegName, uint32_t Pin_Number)
//	{
//		if constexpr (Pin_Number < Max_Pin_Number)
//		{
//			uint32_t Shifter;
//
//		if constexpr (RegName == "GPFSEL0" || RegName == "GPFSEL1")
//		{
//			Shifter = (Pin_Number * Function_Select_Size) & Register_Pins_Each;
//		}
//		else
//		{
//			Shifter = Pin_Number & Register_Pins_Each;
//		}
//
//		//Use Register to write and set
//		Registers->write( RegName , (Bit_Select << Shifter));
//		}
//		else
//		{
//			throw Exception("Wrong Pin Number");
//		}
//	}
//
//	// Read a register value by PinNumber
//	uint32_t Read(std::string RegName) const
//	{
//			//Use Register to write and set
//			return Registers->read(RegName);
//	}
//
//	~GPIO_Handler() noexcept(false)
//	{
//		delete Registers;
//	}
//
//private:
//	static constexpr uint32_t Register_Pins_Each	  = 0x1f;
//	static constexpr uint32_t Function_Select_Size    = 3;
//	static constexpr uint32_t Max_Pin_Number 	  	  = 54;
//	static constexpr uint32_t Bit_Select 		  	  = 1;
//
//	//initialize the register manager
//	RegisterManager * Registers = new(RegisterManager());
//
//};
//
//
//#endif /* GPIO_DRIVER_GPIO_HANDLER_HPP_ */
