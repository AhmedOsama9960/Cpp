/*
 * SmartPTR.cpp
 *
 *  Created on: Mar 8, 2023
 *      Author: osama
 */


#include <iostream>
#include <memory>
#include <thread>
#include <functional>


//shared_ptr the syntax is a template class---> share_ptr<T/DataType> nameofit(const lvalue&)
//make_shared syntax is template function---> make_shared<datatype/userdefined>(variadic template but should be &&rvalue)
/*
int main(void)
{
		******************************************** Weak_Ptr**************/
/*
		auto SHP1 = std::make_shared<int>(100);
		std::weak_ptr<int> wp;
		std::weak_ptr<int> wp2;

		std::cout << "WEAK_PTR1 = " << wp.use_count() << std::endl;
		std::cout << "WEAK_PTR2 = " << wp2.use_count() << std::endl;
		std::cout << "Shared_PTR = " << SHP1.use_count() << std::endl;
		std::cout << "WEAK_PTR_EXCIP = " << wp.expired() << std::endl;			// expired is to check the share ptr is deallocated or not
			wp = SHP1;																// wp.reset() is deallocating weakptr from the pointer it reference to it
		std::cout<< "WP1 " << wp.use_count() << "WP2 " <<wp2.use_count()<<std::endl;
		if(std::shared_ptr<int> SHP2 = wp.lock() ){
		std::cout << "Shared_PTR = " << *SHP1 << std::endl;
		std::cout<< "WP after deduction" << wp.use_count() << std::endl;
		// WP has become two because the stored pointer of weak has deducted more than one sharedptr uses the obj of the weak
		std::cout << "Shared_PTR = " << SHP2.use_count() << std::endl;
		}
		else
		{
		std::cout<<"it is expired ";
		}
*/


	/********************************* Cyclic Dependencies and its solution by weakptr to break the cycle****************************/
	/*
	struct son;			// forward declaration
	struct daughter;	// forward declaration

		struct Mother
		{
			~Mother() { std::cout<<"Mother Gone" << std::endl ; }

			void set_son(const std::weak_ptr<son> s)
			{
				// by lock_method we convert the weakptr to sharedptr to be able to assign it to another shared_ptr
				//creates a shared_ptr that manages the referenced object
				MYson = s.lock();
			}
			void set_daughter(const std::shared_ptr<daughter> d)
			{
				MyDaughter = d;
			}

			std::shared_ptr<son> MYson;
			std::shared_ptr<daughter> MyDaughter;


		};
		struct son
		{
			son(std::shared_ptr<Mother> m) : Mymother(m) {}
			~son() { std::cout<< "Son Gone" << std::endl ;}
				std::shared_ptr<const Mother> Mymother;
		};

		struct daughter
		{
				daughter(std::shared_ptr<Mother> m) : mymother(m) {}
				~daughter() { std::cout<< "Dau Gone" << std::endl ;}

				std::shared_ptr<const Mother> mymother;
		};

		*/
	/*
	 {
	std::shared_ptr<Mother> mother = std::shared_ptr<Mother> ( new Mother);
	std::shared_ptr<son> Son = std::shared_ptr<son> (new son(mother));
	std::shared_ptr<daughter> Daughter = std::shared_ptr<daughter> (new daughter(mother));
	std::cout << Son.use_count() << std::endl;
	mother->set_son(Son);
	mother->set_daughter(Daughter);
	}


	return 0;
}
*/

/* test
 * std::unique_ptr<int> p();
 p.get_deleter();

 std::function<void(int *)>;

*/

/************************************ Shared PTR *********************************************/

/*
 *
 * class foo
{
	int x;
public:
	foo(int x) : x(x) {}
	int getX(void){
		return x;
	}
	~foo() { std::cout<<"~Foo" ; }
};

//template<typename... args>
void foo_(std::shared_ptr<foo> sp0)
{
	// everytime it enters the method a local_shared_ptr is created as it is in the argument
	std::cout<< " Fun" << sp0.use_count() << std::endl;
}
*/


	/* The old way to create a ptr */
	//foo * f = new foo(3);
	//std::cout << f->getX();
	// delete f;

	//std::shared_ptr<foo> &sp1 = sp;					// Can manage the object life time and share the object
	//std::cout<< sp.use_count() << std::endl;			// unlike the unique ptr which doesn't share the ownership of the object
	// OR 	std::cout<< sp1.use_count() << std::endl;

	/* With Share Ptr */
	//std::shared_ptr<foo> sp(new foo(30));
	//std::cout<< sp.use_count() << std::endl;

	/* Make a pool of threads of shared_ptr */
	/*std::thread t1(foo_, sp) , t2(foo_,sp), t3(foo_,sp);
	t1.join();	t2.join(); t3.join();
	std::cout<< sp.use_count() << std::endl;
	std::cout<< sp->getX() <<std::endl ;
	 */

/*--------------How all shareptrs share the same address to the managed obj by the stored pointer inside each one-----------
std::shared_ptr<int> p = std::make_shared<int>(10);
std::shared_ptr<int> q,s;
q = p;
s = q;
std::cout<< p.get() << std::endl<< q.get() <<  std::endl<< s.get();	// same address and same share
 */
