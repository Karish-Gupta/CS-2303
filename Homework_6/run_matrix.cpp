#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Matrix.h"

using std::string;
void add(Matrix &A, Matrix &B);
void subtract(Matrix &A, Matrix &B);

int main(void){

    Matrix A(5);
    Matrix B(5);
    A.readMatrix("data1.txt"); //read first matrix from file by calling function
    B.readMatrix("data2.txt"); //read second matrix from file with readMatrix

    if (A.getLength() != B.getLength()) { // must be same dimensions for any of these operations
        printf("This math cannot be performed."); // print error message
    }
    else {
        
        // Write an overloaded + function that adds 2 matrix objects and returns a new object
        // Then uncomment the following lines
        Matrix C = A + B;
        cout << "A + B with overload" << endl;
        C.print();

        // Write an overloaded << function that allows you to use << to print a matrix
        cout << C << endl;

        // Write an overloaded + function that adds a float to a matrix object
        // Then uncomment the following lines
        Matrix D = A + 2.1;
        cout << "A + 2.1:" << endl;
        cout << D << endl;

        // Write an overloaded + function that adds a float to a matrix object
        // Then uncomment the following lines
        Matrix E = 2.1 + A;
        cout << "2.1 + A:" << endl;
        cout << E << endl;
        
    }

    return 0;
} // end main 


