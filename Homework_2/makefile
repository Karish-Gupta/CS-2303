sales.exe: coffee_shop.o register.o
	gcc -Wall coffee_shop.o register.o -lm -o sales.exe

register.o: register.h register.c
	gcc -Wall -c register.c

coffee_shop.o: register.h coffee_shop.c
	gcc -Wall -c coffee_shop.c

clean:
	del -f coffee_shop.o register.o sales.exe

all: 
	sales.exe

