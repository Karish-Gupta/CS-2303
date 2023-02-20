#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"


int main(int argc, char *argv[])
{
    // checks that there are no more than 4 arguments entered into the command-line
    // print error message and exits if more than 4 arguments
    if (argc > 4) 
    {
        printf("This math cannot be performed.");
        exit(1);
    }

    // readmatrix function creates pointer to matrix A
    Matrix *matrix_A = readMatrix(argv[1]);

    // readmatrix function creates pointer to matrix B
    Matrix *matrix_B = readMatrix(argv[2]);

    // checks to ensure that both matix A and B have the same size
    if(matrix_A->size != matrix_B->size)
    {
        printf("This math cannot be performed.");
        exit(1);
    }

    // sets fourth value of command-line argument to operation pointer
    char *operation = argv[3]; 

    // calls addition or subtraction operation or prints error
    switch (*operation)
    {
        // checks if operation is equal to a for addition
        case 'a':
        addition(matrix_A, matrix_B);
        break;

        // checks if operation is equal to s for subtraction
        case 's':
        subtraction(matrix_A, matrix_B);
        break;
        
        // otherwise print error message
        default:
        printf("This math cannot be performed.");
        exit(1);
    }

    //clears the memory allocated for the two matrices 
    deleteMatrix(matrix_A);
    deleteMatrix(matrix_B);

    // return 0 if successful
    return 0;
}