#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"


struct matrix* readMatrix(char* filename) 
{
    FILE* fp1 = fopen(filename, "r");
    
    Matrix A;
    Matrix* matrix_A = malloc(sizeof(Matrix));
    
    float value;
    int count = 0;

    while(fscanf(fp1, "%f", value) > 0)
    {
        count++;
    }

    float* data_value = malloc(count * sizeof(float));

    for(int i = 0; i < count; i++)
    {
        float value;
        fscanf(fp1, "%f", value);
        data_value[i] = value;
    }

    A.size = count;
    A.data = data_value;

    return matrix_A;

}

int deleteMatrix(struct matrix *A)
{
    
}

