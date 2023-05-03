

#include "Matrix.hpp"
#include <iostream>


typedef unsigned char u8;
Matrix::Matrix(int i , int j): numOfRows(i) , numOfCols(j){

	matrix = new int*[numOfRows];

	    for (u8 iter_1 = 0; iter_1 < numOfRows; iter_1++)
	    {
	        matrix[iter_1] = new int[numOfCols];
	    }
}

Matrix::Matrix(const Matrix& other) : Matrix(other.numOfRows , other.numOfCols){
	/* copping the elements */
	for(u8 iter_1 = 0 ; iter_1 < numOfRows ; iter_1++)
		{
			for(u8 iter_2 = 0; iter_2 < numOfCols; iter_2++)
			{
				this->matrix[iter_1][iter_2] = other.matrix[iter_1][iter_2];
			}
		}
}

void Matrix::setElement(int i , int j , int value){
    matrix[i][j] = value ;
}

int Matrix::getElement(int i ,int j)const{
	return matrix[i][j];
}

void Matrix::print()const{
	std::cout<<"first Col"<<" "<<"Second Col"<<std::endl;
	for(u8 iter_1 = 0 ; iter_1 < numOfRows ; iter_1++)
	{
		for(u8 iter_2 = 0; iter_2 < numOfCols; iter_2++)
		{
			std::cout<<"     " << matrix[iter_1][iter_2]<<" ";
		}
		std::cout<<std::endl;
	}
	/* Can be for range loop but const was a problem, please wanna discuss it */
	/* for (auto &row : matrix)
	{
		for (auto &col : row)
		{
			std::cout<<"     " << col<<" ";
		}
		std::cout<<std::endl;
	}
	*/
}

Matrix::~Matrix(){
	/* as its array of pointers we have to free each pointer of the array individually */
	for(u8 iter_1 = 0; iter_1 < numOfRows; iter_1++)
	{
	delete [] matrix[iter_1];
	}
	/* free it as a whole to ensure no existance any longer*/
	delete [] matrix;

	/* ensuring no values included */
	//std::cout<<matrix[1][1]<<std::endl;
}
    

