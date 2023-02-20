To run this program I used a makefile.
To compile the code enter: mingw32-make matrixCalc
To run the code enter: ./matrixCalc.exe input1.txt input2.txt a

This program takes three arguments on the command line (4 including the file name. It takes in two file names containing the matrix data values and a character (a or s) for addition or subtraction. 

If the proper number of arguments are not present or if the matrices have different sizes, an error message will be prompted to the screen.

The readMatrix function takes in the filename and allocates memory for a matrix. Then allocates memory for the data values and scans through the file, populating the data values array. Then the matrix size is set to the count and the matrix data is set to the data values array pointer. A pointer to the matrix is returned.

The deleteMatrix function takes a pointer to a matrix and frees the data pointer and the matrix structure itself. 

The addition function allocates memory for the new matrix. The size is set to the size of matrix A as both matrix A and B should have the same size. Memory is then allocated for a new data values array pointer. A for loop is used to add each data array value of matrix A with matrix B, which is populated in the new data values array.Matrix D data is set equal to the data values array and the new matrix values are printed to the screen. The same logic is used for the function subtraction, however, the matrix b values are subtracted from matrix A. Both functions return void. 

The main function calls each of the functions. If  “a” is inputted in the command line, addition is called. If “s” is inputted then subtraction is called. If neither a nor s is found an error message is printed and the program ends. If the size of matrix A and B are not the same, then the error message is printed and  the program ends. At the end of the operation, delete matrix is called on both matrix A and B to free the allocated memory.

I did not use any outside resources except the notes from class. I went to one office hours session with Professor Mortensen, as I was having issues with my makefile. The autograder was not able to compile my code as the makefile had some minor bugs. She was able to help me fix the bugs and get my program to work with the autograder. 
