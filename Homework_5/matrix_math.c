#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"

/*
struct matrix* readMatrix(char* filename) 
*       Creates a pointer to a matrix with data values from the given filename.
*   Input:
*       char* filename: name of the input file from which the matrix data values will be scanned.
*   Returns:
*       struct matrix*: a pointer to the matrix allocated in memory.
*/
struct matrix* readMatrix(char* filename) 
{
    //initialize variables
    FILE* fp1 = fopen(filename, "r");

    // allocate memory for Matrix A
    Matrix* A = malloc(sizeof(Matrix));

    // setting size of matrix in input file to count 
    int count = 0;
    fscanf(fp1, "%d", &count);

    // allocating memory for data values 
    float* data_value = malloc(count * sizeof(float));

    // loops through float values in input file and adds them to data values array
    for(int i = 0; i < count; i++)
    {
        fscanf(fp1, "%f", &data_value[i]);
    }

    // set matrix size to count and data to the data values array 
    A->size = count;
    A->data = data_value;

    fclose(fp1);

    // return pointer to matrix
    return A;
}


/*
int deleteMatrix(struct matrix *A)
*       Frees allocated memory from heap.
*   Input: 
*       struct matrix* A: a pointer to a matrix struct allocated on the heap.
*   Returns:
*       int: retruns int if function is successful.
*/
int deleteMatrix(struct matrix *A)
{
    // free data array from within struct
    free(A->data);

    // free struct itself from heap
    free(A);

    // return 0 if successful
    return 0;
}


/*
void addition(struct matrix *A, struct matrix *B)
*       Adds each value of two given matrixes of the same size.
*   Input: 
*       struct matrix* A: a pointer to a matrix struct allocated on the heap.
*       struct matrix* B: a second pointer to a matrix struct allocated on the heap.
*   Returns:
*       void
*       Prints addition to the screen.
*/
void addition(struct matrix *A, struct matrix *B)
{
    // allocate mamory for new matrix and initialize variables
    Matrix* D = malloc(sizeof(Matrix));
    // matrix A and B should be the same size so we may set the size equal to matrix A
    int size = A->size;
    D->size = size;

    // memory for matrix D data values is allocated
    float* data_value = malloc(D->size * sizeof(float));

    // add matrix A and B values 
    for (int i = 0; i < size; i++)
    {
        // add each A matrix value and B matrix value
        data_value[i] = A->data[i] + B->data[i];
    }

    // set matrix D data pointer equal to data value array
    D->data = data_value;

    // print header and matrix values
    printf("A + B = \n");
    for (int i = 0; i < size; i++)
    {
        printf("   %0.2f", D->data[i]);
    }

}


/*
void subtraction(struct matrix *A, struct matrix *B)
*       Subtracts each value of two given matrixes of the same size.
*   Input: 
*       struct matrix* A: a pointer to a matrix struct allocated on the heap.
*       struct matrix* B: a second pointer to a matrix struct allocated on the heap.
*   Returns:
*       void
*       Prints subtraction of the two matrixes to the screen.
*/
void subtraction(struct matrix *A, struct matrix *B)
{
    // allocate mamory for new matrix and initialize variables
    Matrix* D = malloc(sizeof(Matrix));
    // matrix A and B should be the same size so we may set the size equal to matrix A
    int size = A->size;
    D->size = size;

    // memory for matrix D data values is allocated
    float* data_value = malloc(D->size * sizeof(float));

    // subtract matrix A and B values 
    for (int i = 0; i < size; i++)
    {
        // subtract each A matrix value and B matrix value
        data_value[i] = A->data[i] - B->data[i];
    }

    // set matrix D data pointer equal to data value array
    D->data = data_value;

    // print header and matrix values
    printf("A - B = \n");
    for (int i = 0; i < size; i++)
    {
        printf("   %0.2f", D->data[i]);
    }

}