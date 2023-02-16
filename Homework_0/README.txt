Summary and Explanation of Code:

The program prime_number.c takes in a number as input from the user using scanf. Then it iterates through all numbers from 2 to the number before 
the input value and checks if the remainder is 0. If the remainder is 0, that means we have found a number that the input number is divisible by. Thus, the number is not prime.
If the program runs through all the values and the remainder is not 0 for any of the numbers, then the input value is said to be prime.

To run prime_number.c first compile the code by entering "gcc prime_number.c -o out.exe" or "gcc -Wall prime_number.c -o out.exe" into the terminal.
Then you may run the code by entering "./out.exe" into the terminal. 

I went to Jatin Kohli's help session to figure out how to compile and run my code. Other than that I did not reference any other people. 
For outside resources I used the book: "Modern C for Absolute Beginners" by Slobodan Dmitrović. I used this to better understand the data structures and how to incorporate them 
in print statements.

This code makes use of a for loop that iterates from 2 to the number just before the input value. I start at 2 because I cannot divide integers by 0. I also do not want to divide
integers by 1 as that will always return a remainder of one and will result in the algorithm always stating that the input is not a prime number. 
I also make use of an if statement to check if the remainder is 0. If it is 0, then I break out of the for loop. Then I check if the remainder is 0 once again and depending on whether
it is 0, I state that it is prime or not prime (remainder of 0 is not prime and remainder of any other value is prime).
