/*
 * Implementation_definitions.cpp
 *
 *  Created on: Feb 11, 2023
 *      Author: osama
 */


/*************************************** #includes *********************************/
#include <iostream>
#include "header_for_Driver.h"

/* -------------------------------- Namespaces --------------------------------------*/
using namespace std;

/* ----------------------------------- Define ----------------------------------------*/


/* -------------------------------Implementations ----------------------------------*/

/* Public Section */
test::test()							/* default Constructor */
{
	literal = NULL;
	size = 0;
}

test::test(int sz , const char * name)	/* Parameterized Constructor */
{
	size = sz;
	literal = new char(sz);
	Namecpy(literal,name);
}

test::~test()							/* Destructor */
{
	cout<<"Test is done";
}

/* ----------------------------- Private Methods -------------------------------*/

/* Private Section */
void test::Namecpy(char * destination, const char * source)
{
	while(*source != '\0')
	{
		*destination++ = *source++;
	}
	*destination++ = *source++;
}

int test::strlen(const char * name)
{
	int counter = 0;
	while(*name != '\0')
	{
		counter++;
	}
	return counter;
}

void test::printstring(const char * name)
{
	cout<<"the name is :" <<name;
}
void test::printsize(int sz)
{
	cout<<"size = " << sz;
}
