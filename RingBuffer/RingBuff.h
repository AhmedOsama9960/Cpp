/*
 * RingBuff.h
 *
 *  Created on: Feb 26, 2023
 *      Author: osama
 */

#ifndef RINGBUFFER_RINGBUFF_H_
#define RINGBUFFER_RINGBUFF_H_

#include<iostream>
#include<string>

/*******************************Types ************************************/
typedef unsigned int u32;
/************************************ Exception ******************************/

class exception
{
public:
	std::string mes;
	exception(std::string name) : mes(name) {};
};
/****************************Templates *********************************/
template<class T, u32 Buff_Size>
/*************************** APIS *************************************/
class RingBuffer
{
public:
	// Default Constructor
	RingBuffer();
	// push element
	void push(T element);
	// pop
	T pop(void);
	// get element
	T get(void);
	// full
	bool isFull(void);
	//empty
	bool isEmpty(void);

private:
	T buffer[Buff_Size] = {0};
	u32 tail = 0, head = 0;
};



#endif /* RINGBUFFER_RINGBUFF_H_ */
