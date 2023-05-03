/*
 * ConstructorandRAII.cpp
 *
 *  Created on: Mar 26, 2023
 *      Author: osama
 */




#include <iostream>
#include <memory>
#include <mutex>
#include <bitset>
using namespace std;

class Foo
{
private:
    double x;
    double y;
    int* z;

    unique_ptr<int> a;
    mutex b;

public:
    // Default constructor
    Foo()
    {
        x = 5.5;
        y = 4.5;
        z = new int(10);
        a = nullptr;
        cout << "Inside Default constructor - x = " << x << " y = " << y << endl;
    }

    // Parameterized constructor
    Foo(double _x, double _y)
    {
        x = _x;
        y = _y;
        z = new int(10);
        a.reset(new int(3));
        //cout<<this->a;
        cout << "Inside Parameterized constructor - x = " << x << " y = " << y << endl;
    }

    // Copy constructor
    Foo(const Foo &other)
    {
        x = other.x;
        y = other.y;
        z = new int(*other.z);

        cout << "Inside Copy constructor - x = " << x << " y = " << y << endl;
    }

    // Copy assignment
    Foo& operator=(const Foo &other)
    {
        if (this != &other)
        {
            x = other.y;
            y = other.x;
            // Int temp = *other.z
            //z = new int(temp);
            z = new int(*other.z);
            //why did I make new int(*other.z)
            // because I don't want my pointer to point to the same address of z
            // so I created my own pointer with a new address in memory returned by operator new
            //assigned by the value of z


            //this->a.reset(new int(*other.a));

            //momken keda aw keda
            // auto *ptr = other.a.get();
            a = make_unique<int>(*other.a.get());
            unique_ptr<int>(new int(*other.a));
            //this->a = new int(*other.a);


            cout << "Inside Copy assignment - x = " << x << " y = " << y << endl;
        }
        else
        {
            cout << "Copy assignment to self .. ignored" << endl;
        }

        return *this;
    }

    // Move assignment
    Foo& operator=(Foo&& other)
    {
        if (this != &other)
        {
            // Copy other
            x = other.x;
            y = other.y;
            z = new int(*other.z);
            //this->a.reset(new int(*other.a));
            this->a = move(other.a);

            // Clear other
            other.x = 0;
            other.y = 0;
            delete other.z;

            //other.a.release();

            cout << "Inside Move assignment - x = " << x << " y = " << y << endl;
        }
        else
        {
            cout << "Move assignment to self .. ignored" << endl;
        }

        return *this;
    }
};

/*
int main()
{

    cout << "foo_0: ";
    Foo foo_0;

    cout << "foo_1: ";
    Foo foo_1(10,20);

    cout << "foo_2: ";
    Foo foo_2(foo_0);

    cout << "foo_3: ";
    Foo foo_3 = foo_1;

    cout << "foo_3 x2: ";
    foo_3 = foo_0;

    cout << "foo_3 x3: ";
    //foo_3 = foo_3;		//Error

    cout << "foo_4: ";
    Foo foo_4 = {1,2};

    cout << "foo_5: ";
    Foo foo_5;

    cout << "foo_5 x2: ";
    foo_5 = {1,2};

    cout << "foo_5 x3: ";
    foo_5 = move(foo_0);

    bitset<4> a = 5;
    cout<<endl<<a;
    return 0;
}

*/
