matrixCalc: matrix_calc.o matrix_math.o 
	gcc -Wall matrix_math.o matrix_calc.o matrix_math.h -lm -o matrixCalc

matrix_calc.o: matrix_math.h matrix_calc.c
	gcc -Wall -c matrix_calc.c

matrix_math.o: matrix_math.h matrix_math.c
	gcc -Wall -c matrix_math.c 

clean:
	del -f matrix_math.o matrix_calc.o matrixCalc.exe

