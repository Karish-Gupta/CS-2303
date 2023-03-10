To compile the code enter: g++ Matrix.cpp run_matrix.cpp -o runM.exe
To run the code enter: ./runM.exe

This program uses a matrix class that has properties: int length and float* data. Matrices take in values from data1 and data2 text files using the readMatrix method. The getLength and getData methods return a length integer and a pointer to the data array respectively. 

Matrix operator+(Matrix &B) overloads the + operator to add two matrices together. The Matrix operator+(float) overloads the + operator to add a float value to each value in a matrix. The friend Matrix operator+(float, const Matrix& A) function overloads the plus operator to add a float value with a matrix . However, this computation is done on a float class instead of the matrix class. So, we use the friend keyword to allow access to the matrix class properties. The friend ostream& operator<<(ostream& os, const Matrix& A) function overrides the << operator to print out a matrix. It takes in an output stream and a Matrix. It then prints out all of the values in a matrix to the screen and returns the output stream.
