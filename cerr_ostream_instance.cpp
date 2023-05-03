/////*
//// * cerr_ostream_instance.cpp
//// *
//// *  Created on: Mar 14, 2023
//// *      Author: osama
//// */
////
////
////
////#include <errno.h>
////#include<iostream>
////
////int main(void)
////{
////	std::cout<<"hi";
////	std::cerr <<" Hi";
////}
//
//
//// Online C++ compiler to run C++ program online
//#include <iostream>
//#include <chrono>
////template<int Value>
//class Data{
//public:
//
//  Data() noexcept : m_DataBase(10) { std::cout<<"COTR" << std::endl; } //Default Constructor
//  Data(int const_value) : m_DataBase(const_value) {} 					// Parameterized COTR
//
//  void display_class_Number() const
//  {
//      std::cout<<m_DataValue << std::endl;
//  }
//
//  Data& operator+(const Data& temp)
//  {
//      m_DataValue = m_DataValue + temp.m_DataValue;
//      return *this;
//  }
//
//  Data& operator=(Data& temp)
//  {
//	  return temp;
//  }
//
//  ~Data() { std::cout<<"Dstructor" << std::endl;}		// Destructor
//
//private:
//  const int m_DataBase ;
//  unsigned int m_DataValue = 6;
//};
//
//int main()
//{
//	auto start = std::chrono::high_resolution_clock::now();
//    Data d = Data();
//    Data d2 = Data();
//    Data d3 = Data();
//    Data d4 = Data();
//    Data D(5);
//    d = d + D;
//    d.display_class_Number();
//    auto end = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
//    std::cout<< "TimeTaken    "<<duration.count() <<"    ns" << std::endl;
//}
