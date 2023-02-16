This program runs via the makefile. You may enter ming32-make to compile all the files and create coffee_shop.o, register.o, and sales.exe.
The file sales.exe is the executable file and can be run by entering ./sales.exe into the terminal. If you would like to remove the output files, 
you can enter mingw32-make clean. This will remove coffee_shop.o, register.o, and sales.exe. You can compile and get them again by using ming32-make.

This program works with two .c files, a .h file, and a makefile. The coffee_shop.c file contains main and makes calls to 3 functions located in register.c,
and the register.h file contains the function prototypes. The makefile contains the keywords to quickly compile all the files.

Functions:

The overall_revenue function takes in a file pointer and returns a float. It initializes variables: overall_revenue, item_code, and item_price. The function
then initiates a while loop that continues to loop if fscanf finds an integer value and a float value. The fscanf function returns the number of fields it 
converts, so it should return 2 if it finds an int value and a float value. Since the file we are reading contains a item code int that corresponds to a 
float price value, we can scan the ints and floats in pairs. So we will continue to loop if the fscanf function continues to return 2. The loop will end if 
an int followed by a float is not scanned. This type of while loop logic is used in all three functions in the register.c file. Then an if statement checks 
if item code represents the day starting balance. The day starting balance has an item code of 0, so if int 0 is scanned, we set the item price to 0 to negate 
adding the balance to the overall_revenue. Finally we return the overall_revenue.

The balance function takes in a file pointer and returns a float. It initializes variables: days_balance, item_code, and item_price. The function will then initiate
a while loop with the same logic as that of the overall_revenue function. If we find int and float pairs, we will continue to loop through the file. Otherwise,
we will end the loop. We add each item price to the days_balance variable. In this case there is no if statement checking for the starting day balance. This means 
that the starting day balance with item code 0, will be treated as a normal item. So the starting balance value will be added to the day's balance variable. Finally,
we return the total balance at the end of the day.

The tally function takes in a file pointer and returns an int. It initializes variables: count, item_code, and item_price. The function will then initiate a while loop 
with the same logic as the two previous functions. If we find int and float pairs, we will continue to loop through the file. Otherwise, we will end the loop. Then we have 
an if statement that checks if each item code is the same as the given item code we are looking for. If it matches, we increase the count by 1. Finally we return the count integer.


Main:

In the main function we ask the user to enter a number corresponding to the three main options. The main function also asks for a file to read. It then takes that string, and 
opens the file in read mode. Each option calls one of the above three functions and completes a task. An if statement is used to check the user input and executes the calls relevant 
to each option. If 1, 2, or 3 is not inputted, then the message, "This option is not valid." is printed to the terminal and the program exits. Option 1 calls the overall_revenue function 
and prints the revenue to the terminal. Option 2, calls the balance function and prints the balance to the terminal. Option 3 prompts the user to enter an item code to analyze a specific item. 
It then calls the tally function to get a count of the item. It then prompts them to enter an output file. Then it asks the user to enter "A" or "O" for whether they want to append or overwrite 
to the output file. Then we enter an if statement that checks whether we append (A) or overwrite (O) the output file. If the input is A, we append the item code and count to the file.
Otherwise, we overwrite the file. 


Resources:

I used some online resources to understand how the new FILE type works and how to work with file pointers. I also used resources to better understand what the return types are of certain
functions. For example I was not sure what the return type of fscanf was until I looked that up. I also made use of "Modern C for Absolute Beginners" by Slobodan Dmitrović.

I had a major issue with my makefile as the autograder was having trouble compiling with it. The makefile worked perfectly on my end, but would simply not run on the autograder.
So I went to office hours with Mehrnoush Alizade. After working with him and a group of people around me we were able to figure out the makefile command that passed the autograder.

Works Cited:
"Modern C for Absolute Beginners" by Slobodan Dmitrović
https://www.geeksforgeeks.org/data-type-file-c/
https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm


