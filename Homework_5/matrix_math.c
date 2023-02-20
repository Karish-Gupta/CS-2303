#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"


struct matrix* readMatrix(char* filename) 
{
    FILE* fp1 = fopen(filename, "r");
    
    Matrix* A = malloc(sizeof(Matrix));

    int count = 0;

    fscanf(fp1, "%d", &count);


    float* data_value = malloc(count * sizeof(float));

    for(int i = 0; i < count; i++)
    {
        fscanf(fp1, "%f", &data_value[i]);
    }

    
    A->size = count;
    A->data = data_value;

    fclose(fp1);

    return A;
}


int deleteMatrix(struct matrix *A)
{
    free(A->data);
    free(A);

    return 0;
}

void addition(struct matrix *A, struct matrix *B)
{
    Matrix* D = malloc(sizeof(Matrix));
    int lesser_size;
    int greater_size;

    if (A->size < B->size)
    {
        lesser_size = A->size;
        greater_size = B->size;
    }
    if (A->size > B->size)
    {
        lesser_size = B->size;
        greater_size = A->size;
    }
    else
    {
        lesser_size = A->size;
        greater_size = A->size;
    }

    D->size = greater_size;
    float* data_value = malloc(D->size * sizeof(float));


    for (int i = 0; i < lesser_size; i++)
    {
        data_value[i] = A->data[i] + B->data[i];
        printf("%f %f \n", A->data[i], B->data[i]);
    }


    if (greater_size != lesser_size)
    {
        for (int i = lesser_size; i < greater_size; i++)
        {
            if (A->size < B->size)
            {
                data_value[i] = B->data[i];
            }
            if (A->size > B->size)
            {
                data_value[i] = A->data[i];
            }
            
        }
    }
    D->data = data_value;

    printf("A + B = \n");
    for (int i = 0; i < greater_size; i++)
    {
        printf("   %0.2f", D->data[i]);
    }

}

void subtraction(struct matrix *A, struct matrix *B)
{
    Matrix* D = malloc(sizeof(Matrix));
    int lesser_size;
    int greater_size;

    if (A->size < B->size)
    {
        lesser_size = A->size;
        greater_size = B->size;
    }
    if (A->size > B->size)
    {
        lesser_size = B->size;
        greater_size = A->size;
    }
    else
    {
        lesser_size = A->size;
        greater_size = A->size;
    }

    D->size = greater_size;
    float* data_value = malloc(D->size * sizeof(float));

    for (int i = 0; i < lesser_size; i++)
    {
        data_value[i] = A->data[i] - B->data[i];
        printf("%f %f \n", A->data[i], B->data[i]);
    }


    if (greater_size != lesser_size)
    {
        for (int i = lesser_size; i < greater_size; i++)
        {
            if (A->size < B->size)
            {
                data_value[i] = -B->data[i];
            }
            if (A->size > B->size)
            {
                data_value[i] = A->data[i];
            }
            
        }
    }
    D->data = data_value;

    printf("A - B = \n");
    for (int i = 0; i < greater_size; i++)
    {
        printf("   %0.2f", D->data[i]);
    }

}