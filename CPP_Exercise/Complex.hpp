

#ifndef COMPLEX_H_
#define COMPLEX_H_


class Complex{
    private:
        int real{};
        int img{};
    public:
        //Default Constructor
        Complex() = default;
        //Parameterized Constructors
        Complex(int);
        Complex(int,int);
        //Setters
        void setReal(int);
        void setImg(int);
        //Getters
        int getReal()const;
        int getImg()const;
        //Operations
        Complex sum(const Complex&)const;
        Complex difference(const Complex&)const;
        Complex product(const Complex&)const;
        //Helpers
        void print()const;
        //Destructor
        ~Complex();
};


#endif /* COMPLEX_H_ */
