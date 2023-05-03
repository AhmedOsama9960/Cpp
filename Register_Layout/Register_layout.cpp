///*
// * Register_layout.cpp
// *
// *  Created on: Mar 10, 2023
// *      Author: osama
// */
//
//#include "Register_layout.h"
//#include<iostream>
//#include<map>
//#include<string>
//#include <vector>
//
//int main(void)
//{
//	// Declaration of the RegisterBanks
//	Register_Bank R[4] = {{55,33,22,44,55,88,77,66}
//	                     ,{66,44,99,88,77,55,6,54}
//	                     ,{66,22,44,88,77,99,99,55}
//	                     ,{33,22,00,11,00,55,78,99}};
//
//	// Creating a ordered Map
//	std::map<std::string , Register_Bank> Ordered_Map;
//	/* Creating the key and value for each */
//	Ordered_Map["Map1"] = R[0];
//	Ordered_Map["Map2"] = R[1];
//	Ordered_Map["Map3"] = R[2];
//	Ordered_Map["Map4"] = R[3];
//
//	// Helper lambda to print key & value
//	auto print_key_value = [](const std::string Key ,const auto Value)
//	{
//		std::cout << "This register in " <<"[" <<  Key  << "] " << " = " << Value << std::endl;
//	};
//
//	 for (auto e : Ordered_Map)
//	 {
//		 print_key_value(e.first , e.second.CommandA_0);
//	 }
//	return 0;
//}
