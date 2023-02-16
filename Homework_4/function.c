#include <stdio.h>
#include <stdlib.h>
#include "function.h"


/**************************************************
* void get_totals(int rows, int col, int array[][col])
*
* Calculates the total sales of each item over the given months
* stored in array.
*
* Input:
*   array[][col]: an array that contains 51 rows and argc number of columns
*   rows: number of rows in array
*   col: number of columns in data
* Output:
*   Returns void, but overwrites totals to Total_sales.txt 
***************************************************/
void get_totals(int rows, int col, int array[][col]) {
    
    // Open output file
    FILE* f1 = fopen("Total_sales.txt", "w");

    // loop over all rows
    for (int i = 1; i < rows; i ++){
        int total = 0;

        // add together the columns
        for (int j = 1; j < col; j++){
            total = total + array[i][j];
        }
        // Print to file
        fprintf(f1, "%5d %5d\n", i, total);
    }

    // close file
    fclose(f1);

}


/**************************************************
* void get_profits(int rows, int col, int array[][col], float costs[], float purch[])
*
* Calculates the profit for each item over the given number of months of data,
* then saves data to separate text file.
*
* Input:
*   array[][col]: an array that contains 51 rows and argc number of columns
*   rows: number of rows in array
*   col: number of columns in data
*   cost[]: a one-D array containing the cost for each item
*   purch[]: a one-D array containing the purchase price of each item
* Output:
*   Returns void, but overwrites sales, cost and revenue data to Profits.txt 
***************************************************/
void get_profits(int rows, int col, int array[][col], float costs[], float purch[]){
    
    //  Open file and print header
    FILE* f2 = fopen("Profits.txt", "w");
    fprintf(f2, "    Item       #   Sales    Cost Revenue\n");
    
    // loop over all items
    for (int i = 1; i < rows; i ++){
        int total = 0;

        // get total
        for (int j = 1; j < col; j++){
            total = total + array[i][j];
        }

        // Calculate the total sales and total purchase cost
        float Tsales = total * purch[i];
        float Tcost = total * costs[i];

        // print to file
        fprintf(f2, "%8d%8d", i, total);
        fprintf(f2, "%8.2f%8.2f%8.2f\n", Tsales, Tcost, Tsales-Tcost);
    }
    fclose(f2);

}

/**************************************************
* void top_earner(int rows, int col, int array[][col], float costs[], float purch[])
*
* Calculates the top earners across the data,
* then saves the values to a separate text file.
*
* Input:
*    array[][col]: an array that contains 51 rows and argc number of columns
*   rows: number of rows in array
*   col: number of columns in data
*   cost[]: a one-D array containing the cost for each item
*   purch[]: a one-D array containing the purchase price of each item
* Output:
*   Returns void, but overwrites the top 10 earners to Top_earners.txt file
***************************************************/
void top_earner(int rows, int col, int array[][col], float costs[], float purch[]){
    
    // get revenue data and store in array
    float rev[rows];
    float tots[rows];
    for (int i = 0; i < rows; i ++){
        int total = 0;
        for (int j = 1; j < col; j++){
            total = total + array[i][j];
        }
        tots[i] = total;
        float Tsales = total * purch[i];
        float Tcost = total * costs[i];
        rev[i] = Tsales - Tcost;
    }
    
    
    // Open output file
    FILE* f2 = fopen("Top_earners.txt", "w");
    fprintf(f2, "Item   #  Revenue\n");

    // get top item 10 times by looping over the
    // data 10 times, finding the highest value each time
    for (int j = 0; j < 10; j++){
        float top_val = 0;
        int top_it = 0;
        int top_num = 0;
        // loop over all rows, see if larger than current largest value
        for (int i = 0; i < rows; i++){
            if (rev[i] > top_val){
                top_val = rev[i];
                top_it = i;
                top_num = tots[i];
            }
        }
        // print top item to file and change its data to 0
        fprintf(f2, "%4d %3d %8.2f\n", top_it, top_num, top_val);
        rev[top_it] = 0;
    }

}
