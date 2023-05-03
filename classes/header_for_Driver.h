/*
 * header_for_Driver.h
 *
 *  Created on: Feb 11, 2023
 *      Author: osama
 */

#ifndef CLASSES_HEADER_FOR_DRIVER_H_
#define CLASSES_HEADER_FOR_DRIVER_H_

	/* its only for declaration of class and forward declaration for methods or behaviors */
class test
{
	public :
	test();					//Forward Declaration
	test(int,const char *);	// Forward Declaration
	~test();				// Forward Declaration

	private :
	int size;					// Data
	char * literal;				// Data

	// helper methods like
	void Namecpy(char * destination, const char * source);		// Private Methods
	int strlen(const char * original);							// Private Methods
	void printstring(const char * name);						// Private Methods
	void printsize(int sz);										// Private Methods
};



#endif /* CLASSES_HEADER_FOR_DRIVER_H_ */
