

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>

class Matrix{
private:
    int numOfRows{}; //0
    int numOfCols{}; //0
    int **matrix {}; //nullptr
    
public:
    //Parameterized Constructor
    Matrix(int i , int j);
    //Copy Constructor
    Matrix(const Matrix& other);
    //Setter
    void setElement(int i , int j , int val);
    //Getter
    int getElement(int i ,int j )const;
    //Helper
    void print()const;
    //Destructor
    ~Matrix();
    
};



#endif /* Matrix_hpp */
