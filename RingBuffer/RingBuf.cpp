/*
 * RingBuf.cpp
 *
 *  Created on: Feb 26, 2023
 *      Author: osama
 */

/************************************ Include *******************************/
#include <iostream>
#include <string>
#include "RingBuff.h"


/************************************ Implementations ***********************/
template<class T,u32 Buff_Size>
RingBuffer<T,Buff_Size>::RingBuffer() = default;

template<class T, u32 Buff_Size>
void RingBuffer<T,Buff_Size>::push(T element)
{
	head++;
	if(head == Buff_Size)
	{
		head=0;
	}
	if(isFull())
	{
		throw exception("Buffer is Full");
	}
	else
	{
		buffer[head] = element;
	}
}

template<class T, u32 Buff_Size>
T RingBuffer<T,Buff_Size>::pop(void)
{
	head--;
	if(isEmpty())
	{
		throw exception("Is Empty");
	}
	else
	{
		return buffer[head];
	}
}

template<class T, u32 Buff_Size>
T RingBuffer<T,Buff_Size>::get(void)
{
	if(isEmpty())
		{
			throw exception("Is Empty");
		}
	else
		{
			return buffer[head];
		}
}

template<class T, u32 Buff_Size>
bool RingBuffer<T,Buff_Size>::isFull(void)
{
	return ((Buff_Size != 0) && (head == tail));
}

template<class T, u32 Buff_Size>
bool RingBuffer<T,Buff_Size>::isEmpty(void)
{
	return (Buff_Size == 0 || head == tail);
}
