/*
 * Register.hpp
 *
 *  Created on: Mar 14, 2023
 *      Author: osama
 */

#ifndef GPIO_DRIVER_REGISTER_HPP_
#define GPIO_DRIVER_REGISTER_HPP_

#include <iostream>
#include <unordered_map>

// For Throwing an exception
class Exception
{
public:
	std::string Error_message;
	Exception(const std::string& mes) : Error_message(mes) {};
};

class Register
{
public:
	Register() noexcept {}
	Register(uint32_t * baseaddress , uint32_t offset) noexcept : reg(baseaddress + offset)
	{
		std::cout << std::hex << "base_address: " << baseaddress << " offset:" << offset << " Mapped register at " << reg << std::dec << std::endl;
	}

	void write(uint32_t value)
	{
		if(reg != nullptr)
			*reg = value;
		else
			throw Exception("Can't Assign value of NullPtr");
	}
	uint32_t read()
	{
		if(reg != nullptr)
		{
		}
		else
		{
			throw Exception("Can't Return value of NullPtr");
		}
		return *reg;
	}

private:

	uint32_t * reg = nullptr;
};


#endif /* GPIO_DRIVER_REGISTER_HPP_ */
