///*
// * main.cpp
// *
// *  Created on: Mar 14, 2023
// *      Author: osama
// */
//
//#include "GPIO_Handler.hpp"
//
//int main(void)
//{
//
//	try
//	{
//		//Initialization
//	auto GPIO_Hndlr = new(GPIO_Handler);
//
//	 // Set pin 14 to output mode -> GPIO14
//	GPIO_Hndlr->Write("GPFSEL1" , 14);
//
//	//Loop Forever
//	while(true)
//	{
//		//Set High
//		GPIO_Hndlr->Write("GPSET0" , 14);
//		std::cout << "LED is on\n";
//
//        // Wait for 1 second
//        sleep(1);
//
//        // Set pin 8 to low
//        GPIO_Hndlr->Write("GPCLR0", 14);
//        std::cout << "LED is off\n";
//
//        // Wait for 1 second
//        sleep(1);
//	}
//	}
//	catch(Exception &e)
//	{
//		std::cout<< e.Error_message << std::endl ;
//	}
//
//
//	return 0;
//}
