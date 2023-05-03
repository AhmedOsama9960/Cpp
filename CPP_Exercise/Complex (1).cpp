

#include "Complex.hpp"
#include <iostream>


Complex::Complex(int real):real(real){}

Complex::Complex(int real ,int img):real(real),img(img){}

// with operator overloading will be easier to add two classes, tho!
Complex Complex::sum(const Complex &c)const{

	Complex res;
	res.real = this->real + c.real;
	res.img  = this->img  + c.img;
	return res;

}

Complex Complex::difference(const Complex &c)const{
	Complex res;
		res.real = this->real - c.real;
		res.img  = this->img  - c.img;
		return res;
}

Complex Complex::product(const Complex &c)const{
	Complex res;
		res.real = (this->real) * (c.real);
		res.img  = (this->img)  * (c.img);
		return res;
}

void Complex::setReal(int real){
	this->real = real;
}

void Complex::setImg(int img){
	this->img = img;
}

int Complex::getReal()const{
	return this->real;
}

int Complex::getImg()const{
	return this->img;
}

void Complex::print()const{
    // printf("The result is :  %+-5i %+-5ii\n",real,img);
	if(img < 0 && img != 0)
		std::cout<<"result = "<<real<<img<<"j"<<std::endl;
	else if(img == 0)
	{
		std::cout<<"result = "<<real<<std::endl;
	}
	else if(real == 0)
	{
		std::cout<<"result ="<<img<<"j"<<std::endl;
	}
	else if (img > 0 && img != 0)
	{
		std::cout<<"result = "<<real<<"+"<<img<<"j"<<std::endl;
	}
	else
	{
		std::cout<<"No inserted values";
	}
}


Complex::~Complex(){
}

