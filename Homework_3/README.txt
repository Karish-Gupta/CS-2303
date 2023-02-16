This program is made up of analysis.c, analysis_functions.c, analysis.h, and a makefile.

To run this program, one can use the makefile commands enter: mingw32-make to compile analysis.c and analysis_functions.c
This will create an executable file: analysis.exe
The executable can be run by entering: ./analysis.exe

This program contains a main function which creates two arrays: month_data[][7] and money[][2]. Then three functions are called, which are located in the analysis_function.c file. 

void get_totals(int month_data[][7]):
This function takes in the month_data array and uses two for loops. The first for loop iterates through the rows (1-50). The second loop iterates through each of the columns (skipping the first column of item codes) and adds the number of sales to the running sum. It then prints out the item code and sum to the Total_sales.txt file. It repeats this for each row. 

void get_profits(int month_data[][7], float money[][2]):
This function takes in the month_data array and the money array. It uses two for loops. The first for loop iterates from 1 to 50 (representing each row). The second column iterates through the columns and and sums the total sales for each item. Then it exits the column for loop and calculates the sales and costs by using the money array. We enter the row with the item number of the money array. Then we can find the cost and sales price in column 0 and 1. We then print out the item code, item sum, sales, costs, and revenue to Profits.txt.

void top_earner(int month_data[][7], float money[][2]):
This function takes in the month_data array and the money array. It uses two for loops to iterate through the month_data array and populate a separate 50 by 2 array with the item codes and their summed total sales. It then uses another for loop that populates a 50 by 1 array. This array is only populated with profit values for each item. The row number is the same as the item code. Finally another two nested for loops are used to iterate 10 times through the profit array. Each time a top earner is found, we set the value to 0, so it is not chosen again. Then the item code and profit is printed to the Top_earners.txt file. 

Outside Sources:
"Modern C for Absolute Beginners" by Slobodan Dmitrović
https://www.tutorialgateway.org/c-program-to-print-2d-array-elements/
https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm
https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm

I used some online sources to understand how to use two dimentional arrays. I also looked up how certain functions work such as fopen and calloc. I have went to multiple office hours sessions throughout the week as well. 