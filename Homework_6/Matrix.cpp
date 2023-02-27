#include <iostream>
#include <string>
#include <iomanip>

#include "Matrix.h"

// constructors for matrices
Matrix::Matrix(int l1){
    length = l1;
    data = new float[length];
    
}


Matrix::Matrix(){
    length = 0;
    data = NULL;
    
}


// reads in input data for matrices
void Matrix::readMatrix(string fileName) {
    ifstream input;
    input.open(fileName);
    
    for (int i = 0; i < length; i++){
        input >> data[i];
    }
    input.close();
}


/*******************************************************************************
* void print(Matrix& A){
*
* Output:
*   Prints A to the screen
********************************************************************************/

void Matrix::print(){

   // print values to screen
    for (int i = 0; i < length; i++){
       cout << std::setw(8) << data[i];
    }
    printf("\n");

}

/*******************************************************************************
* Matrix::~Matrix()
*
* Deconstructor for Matrix object
********************************************************************************/
Matrix::~Matrix(){
    delete data;
}

/*******************************************************************************
* int Matrix::getLength()
*
* Output:
*   Returns length of matrix
********************************************************************************/
int Matrix::getLength(){
    return length;
 }

/*******************************************************************************
* float* Matrix::getData()
*
* Output:
*   Returns pointer to data array
********************************************************************************/
float* Matrix::getData(){
    return data;
}

/**************************************************
* Matrix Matrix::operator+(Matrix &B)
*
* Overrides + operator to add two matrices together.
*
* Input:
*   Matrix &B: a matrix passed by reference
* Output:
*   Returns matrix C, the sum of the two matrices
***************************************************/
Matrix Matrix::operator+(Matrix &B)
{
    Matrix C(length);
    for (int i = 0; i < length; i ++){
        C.data[i] = data[i] + B.data[i];
    }
    return C;
}

/**************************************************
* Matrix Matrix::operator+(float value)
*
* Overrides + operator to add a matrix and a float value.
*
* Input:
*   float value: a float value to be added
* Output:
*   Returns matrix result
***************************************************/
// Allows A + 2.2
Matrix Matrix::operator+(float value)
{
    Matrix result(length);
    for (int i = 0; i < length; i++) 
    {
        result.data[i] = data[i] + value;
    }

    return result;
}

/**************************************************
* Matrix operator+(float value, const Matrix& A)
*
* Overrides + operator to add a float value with a matrix.
*
* Input:
*   float value: a float value to be added
*   const Matrix& A: a constant matrix passed by reference
* Output:
*   Returns matrix result
***************************************************/
// Allows 2.2 + A
Matrix operator+(float value, const Matrix& A)
{
    Matrix result(A.length);

    for (int i = 0; i < A.length; i++)
    {
        result.data[i] = A.data[i] + value;
    }

    return result;
}

/**************************************************
* ostream& operator<<(ostream& os, const Matrix& A)
*
* Overrides << operator to print matrix values to output stream.
*
* Input:
*   ostream& os: an output stream (cout)
*   const Matrix& A: a constant matrix passed by reference
* Output:
*   Returns an output stream conataining printed values of a matrix
***************************************************/
// Allows cout << A
ostream& operator<<(ostream& os, const Matrix& A)
{
    for (int i = 0; i < A.length; i++)
    {
       os << std::setw(8) << A.data[i];
    }
    printf("\n");

    return os;
}