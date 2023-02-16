#include <stdio.h>

int main(void) 
{ 

// Initialize integer variables
int value;
int remainder;

// Puts up prompt to enter a value
printf("Please enter a value:\n");

// Takes user input from terminal and stores the integer in the value variable
scanf("%d", &value);

// Iterate from 2 to the integer just below value
for (int i = 2; i < value; i++)
{ 
    // Divides the input value by all numbers less than input value except 0 and 1
    // We cannot divide by 0 and the input number will always be divisible by 1
    remainder = value % i; 

    // Breaks out of loop if divisible number is found
    // We know this is not a prime number
    if (remainder == 0)
    {
        break;
    }
     
}

// Determines if number is prime based on remainder
// If remainder is 0, number is not prime
// If remainder is not  0, the number is prime 
if (remainder == 0)
    {
        printf("This value is not a prime number.");

    }
else
    {
        printf("This value is a prime number");

    }

    return 0;
}