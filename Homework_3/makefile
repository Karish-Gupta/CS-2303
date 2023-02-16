analysis: analysis_functions.o analysis.o 
	gcc -Wall analysis.o analysis_functions.o -lm -o analysis.exe

analysis_functions.o: analysis_functions.h analysis_functions.c
	gcc -Wall -c analysis_functions.c

analysis.o: analysis_functions.h analysis.c
	gcc -Wall -c analysis.c

clean:
	del -f analysis.o analysis_functions.o analysis

all: analysis

