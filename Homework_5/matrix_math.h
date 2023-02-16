#include <stdio.h>
#include <stdlib.h>

// matrix struct
struct matrix
{
int size;
float* data;
};
typedef struct matrix Matrix;

// function prototypes
struct matrix* readMatrix(char* filename);

int deleteMatrix(struct matrix *A);

float addition(struct matrix *A, struct matrix *B);

float subtraction(struct matrix *A, struct matrix *B);


