///*
// * Threads_Mutex.cpp
// *
// *  Created on: Mar 29, 2023
// *      Author: osama
// */
//
//
//
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//
///*----- Declaration ----*/
//std::mutex G_mutex_obj;
//
//void foo(int x)
//{
//	// Locking the function to prevent the condition race
//	std::lock_guard<std::mutex> lock(G_mutex_obj);
//    std::cout << "Thread (x) = " << x << std::endl;
//
//    // g_i_mutex is automatically released when lock goes out of scope
//}
//
//class Bar
//{
//public:
//    void operator()(int y)
//    {
//    	// Locking the function to prevent the condition race
//    	std::lock_guard<std::mutex> lock(G_mutex_obj);
//        std::cout << "Thread (y) = " << y << std::endl;
//
//        // g_i_mutex is automatically released when lock goes out of scope
//    }
//};
//
//class FooBar
//{
//    int a; // data member
//public:
//    // constructor
//    FooBar(int a) : a(a) {}
//
//    // operator() function
//    void operator()()
//    {
//        std::cout << "Thread (a) = " << a << std::endl;
//    }
//};
//
//int main()
//{
//    // Launch a thread using a function pointer
//    std::thread t1(foo, 10);
//
//    // Launch a thread using a function object
//    std::thread t2(Bar(), 20);
//    FooBar fooBar(30);
//    std::thread t3(fooBar);
//
//    // Launch a thread using a lambda expression
//    std::thread t4([](int z)
//                   {
//    	// Locking the function to prevent the condition race
//    	std::lock_guard<std::mutex> lock(G_mutex_obj);
//    	std::cout << "Thread (z) = " << z << std::endl; },
//                   40);
//
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();
//
//    return 0;
//}
