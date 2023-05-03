/*
 * Register_layout.h
 *
 *  Created on: Mar 10, 2023
 *      Author: osama
 */

#ifndef REGISTER_LAYOUT_REGISTER_LAYOUT_H_
#define REGISTER_LAYOUT_REGISTER_LAYOUT_H_


typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int    uint32;

struct Register_Bank
{
	/***** A********/       	/***** B********/          /***** C********/          	/***** D********/
	uint32 CommandA_0;      	uint32 CommandB_0;         	uint32 CommandC_0;        	uint32 CommandD_0;
	uint32 CommandA_1;      	uint32 CommandB_1;         	uint32 CommandC_1;        	uint32 CommandD_1;
	uint32 CommandA_2;      	uint32 CommandB_2;         	uint32 CommandC_2;        	uint32 CommandD_2;
	uint32 CommandA_3;      	uint32 CommandB_3;         	uint32 CommandC_3;        	uint32 CommandD_3;

	uint8  ControlA_0;       	uint8  ControlB_0;          uint8  ControlC_0;         	uint8  ControlD_0;

	uint8  Status0A_0;       	uint8  Status0B_0;          uint8  Status0C_0;         	uint8  Status0D_0;

	uint16 OptionsA_0;      	uint16 OptionsB_0;         	uint16 OptionsC_0;        	uint16 OptionsD_0;
	uint16 OptionsA_1;      	uint16 OptionsB_1;         	uint16 OptionsC_1;        	uint16 OptionsD_1;

};


#endif /* REGISTER_LAYOUT_REGISTER_LAYOUT_H_ */
