///*
// * RegisterMgr.hpp
// *
// *  Created on: Mar 14, 2023
// *      Author: osama
// */
//
//#include "Register.hpp"
//#include <unistd.h>
//#include <memory>
//#include <fcntl.h>
//#include <sys/mman.h>
//
//
//class RegisterManager
//{
//public:
//	RegisterManager() noexcept
//	{
//		//Open Dev/mem
//        int mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
//        if (mem_fd < 0)
//        {
//            throw Exception("Couldn't Open the file Dev/Mem");
//        }
//
//        // Map the register into memory
//        reg_map = mmap(nullptr, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, GPIO_BASE);
//        if (reg_map == MAP_FAILED)
//        {
//        	std::cout<< "mmap failed" << std::endl;
//        	std::cout<< std::hex << GPIO_BASE << std::dec << std::endl;
//        	close(mem_fd);
//            throw Exception("Failed to map register: ");
//        }
//
//        // Close it
//        close(mem_fd);
//
//        std::cout << "Mapped GPIO base register at " <<  std::hex << reg_map << std::dec << std::endl;
//        gpio_reg_map = reinterpret_cast<uint32_t*>(reg_map);
//
//        // Create and add the GPFSEL0 register
//        registers["GPFSEL0"] = std::unique_ptr<Register>    (new Register(gpio_reg_map, GPFSEL0_OFFSET));
//
//        // Create and add the GPFSEL1 register
//        registers["GPFSEL1"] = std::unique_ptr<Register>    (new Register(gpio_reg_map, GPFSEL1_OFFSET));
//
//        // Create and add the GPSET0 register
//        registers["GPSET0"] = std::unique_ptr<Register>     (new Register(gpio_reg_map, GPSET0_OFFSET));
//
//        // Create and add the GPSET1 register
//        registers["GPSET1"] = std::unique_ptr<Register>     (new Register(gpio_reg_map, GPSET1_OFFSET));
//
//        // Create and add the GPCLR0 register
//        registers["GPCLR0"] = std::unique_ptr<Register>     (new Register(gpio_reg_map, GPCLR0_OFFSET));
//
//        // Create and add the GPCLR1 register
//        registers["GPCLR1"] = std::unique_ptr<Register>     (new Register(gpio_reg_map, GPCLR1_OFFSET));
//	}
//	~RegisterManager()
//	{
//		//destroy the map
//		registers.clear();
//	    // Unmap the register from memory
//	    munmap(reg_map, BLOCK_SIZE);
//	}
//	// Read a register value by name
//	uint32_t read(std::string name)
//	{
//		if constexpr (registers.find(name) != registers.end())
//		{
//
//		}
//		else
//		{
//			throw Exception("Can't Find the register Name");
//		}
//		return registers[name]->read();
//	}
//	// Write a register value by name
//	void write(std::string name, uint32_t value)
//	{
//        // Check if the register name exists in the map
//	if constexpr (registers.find(name) != registers.end())
//	{
//        std::cout << "Writing register " << name << std::endl;
//        // Write the register value by calling the write function of the Register class
//        registers[name]->write(value);
//	}
//	else
//	{
//		throw Exception("Can't Find The Register Name");
//	}
//	}
//
//
//private:
//
//    static constexpr uint32_t GPIO_BASE = 0x3F200000;
//    static constexpr uint32_t GPFSEL0_OFFSET = 0x00;
//    static constexpr uint32_t GPFSEL1_OFFSET = 0x01;
//    static constexpr uint32_t GPSET0_OFFSET = 0x7;
//    static constexpr uint32_t GPSET1_OFFSET = 0x8;
//    static constexpr uint32_t GPCLR0_OFFSET = 0xA;
//    static constexpr uint32_t GPCLR1_OFFSET = 0xB;
//
//	void* reg_map;
//	uint32_t* gpio_reg_map;
//
//	// Define the register size
//	static constexpr unsigned long long BLOCK_SIZE = (4*1024);
//
//	// A map of register names and pointers
//	std::unordered_map<std::string , std::unique_ptr<Register>> registers;
//
//};
