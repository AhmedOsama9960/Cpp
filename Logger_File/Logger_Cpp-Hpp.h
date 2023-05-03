/*
 * Logger.h
 *
 *  Created on: Mar 5, 2023
 *      Author: osama
 */

#ifndef LOGGER_FILE_LOGGER_CPP_HPP_H_
#define LOGGER_FILE_LOGGER_CPP_HPP_H_


/*----------------------------------------Include ------------------------------------------------*/
#include <string>
#include <mutex>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>

/*----------------------------------Type & Namespaces ------------------------------------------------*/
typedef unsigned char u8;

namespace Enum_Logging
{
enum class LogLevel : u8
{
	Error,
	Info,
	Warn,
	Debug,
	count,
};

enum class LogMode : u8
{
	mFile,
	mConsole,
};

}//Enum_Logging


/* --------------------------------Stand Alone Function/ Method ----------------------------*/

/* the only way to perform a variadic template pack in cout by using un-sized array*/
template < typename... Args>
void doPrint(std::ostream& out, Args&&... args)
{
    using expander = int[];
    (void) expander
    		{
    			0, (void(out << ',' << std::forward<Args>(args)), 0)...
    		};
}



/*---------------------------------------APIs ------------------------------------------------*/

template<short N>
class Logger
{
public:
	/* COTR */
	explicit Logger() = default;
	/* DTRC*/
	~Logger() {
		fclose(file);
		file = 0;
	}

	/* The Logger Output */
	template<typename... Args>
	void CppLogger(std::string appID, Enum_Logging::LogLevel logLevel, Enum_Logging::LogMode logMode, const char *mes, Args... args) noexcept
	{
		/* Way to get the TimeStamping */
		std::time_t	CurrentTime = std::time(nullptr);

		// Can have a race condition in a multi-threaded application
		std::lock_guard<std::mutex> lock(Mut);

		if(logMode == Enum_Logging::LogMode::mConsole)
		{
		std::cout<<" | "<<appID<<" | ";
		for(u8 iter = 0 ; iter < N ; iter++)
		{
			if(AppID[iter] == appID)
			{
				std::cout<<Log[iter].log_num[static_cast<u8> (logLevel)]<<" | ";

				if ( logLevel == Enum_Logging::LogLevel::Error)
				{
					Error(iter , mes,args...);
				}
				else if(logLevel == Enum_Logging::LogLevel::Info)
				{
					Info(iter , mes,args...);
				}
				else if (logLevel == Enum_Logging::LogLevel::Warn)
				{
					Warn(iter , mes,args...);
				}
				else
				{
					Debug(iter , mes,args...);
				}
			}
			else { /* Misra Rule */ }
		}
		std::cout<<" | " << std::asctime(std::localtime(&CurrentTime));
		}

		else if(logMode == Enum_Logging::LogMode::mFile)
		{
			EnableFileOutput();
			char * str = new char[10];
			strcpy(str, appID.c_str());
			fprintf(file, " |  %s",str);
			fprintf(file ," | ");
			for(u8 iter = 0 ; iter < N ; iter++)
			{
				if(AppID[iter] == appID)
				{
					fprintf(file ,"%d", Log[iter].log_num[static_cast<u8> (logLevel)]);
					fprintf(file ," | ");

					/* Indeed I couldn't edit those methods Sorry! */
					/*if ( logLevel == Enum_Logging::LogLevel::Error)
					{
						Error(iter , mes,args...);
					}
					else if(logLevel == Enum_Logging::LogLevel::Info)
					{
						Info(iter , mes,args...);
					}
					else if (logLevel == Enum_Logging::LogLevel::Warn)
					{
						Warn(iter , mes,args...);
					}
					else
					{
						Debug(iter , mes,args...);
					}*/
				}
				else { /* Misra Rule */}

			}
			fprintf(file ," |  %s" , std::asctime(std::localtime(&CurrentTime)));
		}
	}

	/* Setting name for each new App */
	void SetApplication_Name(const std::string appID) noexcept
	{
		std::lock_guard<std::mutex> lock(Mut);
		static u8 No = 0;
		AppID[No++] = appID;
	}

	/* Set the Apps' Loglevels */
	void SetLogLevel(std::string appID, Enum_Logging::LogLevel logLevel) noexcept
	{
		// Can have a race condition in a multi-threaded application
		//std::lock_guard<std::mutex> lock(Mut);
		for(u8 iter1 = 0; iter1 < N ; iter1++)
		{
			if(AppID[iter1] == appID)
			{
				Level = Enum_Logging::LogLevel::Info;
			}
			else
			{/*Misra Rule*/ }
		}
	}

	/* Set the Apps' ModeLevel*/
	template<typename... Args>
	void SetLogMode(std::string appID, Enum_Logging::LogMode logMode, const char * message, Args... args) noexcept
	{
		for(u8 iter1 = 0; iter1 < N ; iter1++)
				{
					if(AppID[iter1] == appID)
					{
						Mode = logMode;
					}
					else
					{/*Misra Rule*/ }
				}
	}

	/*-----------------------------File Handler -----------------------------*/
	void EnableFileOutput(void) noexcept
	{
		EnableFileOutput(File_Path);
	}
	void EnableFileOutput(const char * New_Path) noexcept
	{
		file = fopen(New_Path , "a");
		if(file == 0)
		{
			std::cout<<"Logger: Failed to open the file" << File_Path;
		}
	}

public:
	/*----------------------- All Logging Methods for handling the LogLevels------------------------------- */
	template<typename... Args>
	void Error(u8 ID_Num ,const char * message, Args... args) noexcept
	{
		Logging_Levels(ID_Num , "1Error | " , Enum_Logging::LogLevel::Error , message, args...);
	}

	template<typename... Args>
	void Info(u8 ID_Num, const char * message, Args... args) noexcept
	{
		Logging_Levels(ID_Num , "1Info  | " , Enum_Logging::LogLevel::Info , message, args...);
	}

	template<typename... Args>
	void Warn(u8 ID_Num, const char * message, Args... args) noexcept
	{
		Logging_Levels(ID_Num , "1Warn  | " , Enum_Logging::LogLevel::Warn , message, args...);
	}

	template<typename... Args>
	void Debug(u8 ID_Num, const char * message, Args... args) noexcept
	{
		Logging_Levels(ID_Num , "1Debug | " , Enum_Logging::LogLevel::Debug , message, args...);
	}

/************************ Private Section *****************************/
private:
	std::mutex Mut;
	std::string 	  		  AppID[N];
	Enum_Logging::LogLevel    Level = Enum_Logging::LogLevel::Info;
	Enum_Logging::LogMode     Mode  = Enum_Logging::LogMode::mConsole;
	const char * File_Path         	= "log.txt";
	bool file_output 				= false;
	FILE* file 						= 0 ;
	struct LogNum
	{
	unsigned short log_num[static_cast<u8>(Enum_Logging::LogLevel::count)] = {};
	}Log[N];

private:
	template<typename... Args>
	void Logging_Levels(u8 Id_Num , std::string Level_Name , Enum_Logging::LogLevel logLevel , const char * message, Args... args) noexcept
	{
		Log[Id_Num].log_num[static_cast<u8> (logLevel)]++;
		std::cout<<Level_Name;
		doPrint(std::cout<<message, args...);
	}
};

/*--------------------------------------------END ------------------------------------------------*/




#endif /* LOGGER_FILE_LOGGER_CPP_HPP_H_ */
