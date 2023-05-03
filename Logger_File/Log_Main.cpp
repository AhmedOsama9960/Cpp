///*
// * Log.cpp
// *
// *  Created on: Mar 5, 2023
// *      Author: osama
// */
//
//
//#include <thread>
//#include "Logger_Cpp-Hpp.h"
//
///* Declaration */
//Logger<2> log1;
//
//auto loggy1 = [] (std::string name, u8 count)
//{
//	while(count --> 0){
//	log1.SetLogLevel(name,Enum_Logging::LogLevel::Warn);
//	log1.CppLogger(name , Enum_Logging::LogLevel::Error , Enum_Logging::LogMode::mConsole , "Error");
//
//	log1.SetLogLevel(name,Enum_Logging::LogLevel::Warn);
//	log1.CppLogger(name , Enum_Logging::LogLevel::Warn , Enum_Logging::LogMode::mConsole , "NoWarning");
//
//	log1.SetLogLevel(name,Enum_Logging::LogLevel::Debug);
//	log1.CppLogger(name , Enum_Logging::LogLevel::Debug , Enum_Logging::LogMode::mConsole , "Debugging");
//
//	log1.SetLogLevel(name,Enum_Logging::LogLevel::Info);
//	log1.CppLogger(name , Enum_Logging::LogLevel::Info , Enum_Logging::LogMode::mConsole , "Var = 30");
//	}
//};
//
//
//
//int main(void)
//{
//	// First App
//	log1.SetApplication_Name("TaskA");
//	log1.SetApplication_Name("TaskB");
//	//log1.SetLogLevel("TestA",Enum_Logging::LogLevel::Info);
//
//	/* Multithreads for two Apps at the same time */
//	std::thread Task1(loggy1, "TaskA",10);
//	std::thread Task2(loggy1, "TaskB",7);
//
//	Task1.join();
//	Task2.join();
//
//	/* For Safety and ensuring thread is joined in main*/
//	if(Task1.joinable())
//	{
//		Task1.join();
//	}
//	else { /*Misra Rule*/ }
//
//	if(Task2.joinable())
//	{
//		Task2.join();
//	}
//	else { /*Misra Rule*/ }
//
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
