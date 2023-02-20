#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"


int main(int argc, char *argv[])
{
    // readmatrix function creates pointer to matrix A
    Matrix *matrix_A = readMatrix(argv[1]);
    // readmatrix function creates pointer to matrix B
    Matrix *matrix_B = readMatrix(argv[2]);

    // return 0;
    //assigns a variable to the third input that represents the operation to be executed on the matrices
    char *operation = argv[3]; 

    //switch statement to call each function based on the inputted operation
    switch (*operation)
    {
        case 'a':
        addition(matrix_A, matrix_B);
        break;
        
        case 's':
        subtraction(matrix_A, matrix_B);
        break;
        
        default:
        break;
    }

    //clears the memory allocated for the two matrices 
    deleteMatrix(matrix_A);
    deleteMatrix(matrix_B);

}