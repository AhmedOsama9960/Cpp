///*
// * ObjectPool.cpp
// *
// *  Created on: Mar 8, 2023
// *      Author: osama
// */
//#include <iostream>
//#include <vector>
//#include <memory>
//
//struct pool_object
//{
//public:
//    pool_object() = default;
//    pool_object(int d) : data(d) {}
//    int getter(void) const
//    {
//    	return data;
//    }
//
//private:
//    int data = 0;                 // some data
//};
//
//
//// A structure for object pool
//template<typename T, size_t N>
//class object_pool
//{
//	private:
//		std::vector<T> vec;
//
//	public:
//
//	void acquire_object(pool_object pool)
//	{
//		if(vec.empty())
//		{
//			vec.push_back(pool.getter());
//			std::cout<<"pushed from front" << std::endl;
//		}
//		else if (static_cast<T>(vec.size()) < max_size)
//		{
//			vec.push_back(pool.getter());
//			std::cout<<"pushed from back" << std::endl;
//		}
//		else
//		{
//			std::cout<<"exceeded max_size" << std::endl;
//		}
//	}
//
//	void release_object(pool_object pool)
//	{
//		if(vec.empty())
//		{
//			std::cout<<"Empty Vect";
//			return;
//		}
//		vec.pop_back();
//		std::cout<< "Poped in the back" << std::endl;
//	}
//
//
//private:
//    T size;                		 // current size of the pool
//    T max_size = N;             // maximum size of the pool
//};
//
//
//int main()
//{
//	using obj = object_pool<int, 10>;
//	std::unique_ptr<obj> SP = std::make_unique<obj>();
//
//	SP->acquire_object(10);
//	SP->acquire_object(100);
//
//	SP->release_object(20);
//	SP->release_object(20);
//
//	return 0;
//}
//
