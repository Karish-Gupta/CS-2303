#include <stdio.h>
#include <stdlib.h>
#include "analysis_functions.h"

/*
get_totals(int month_data[][7])
*       Creates new text file, Total_sales.txt that contains each item code and the total sales of each item
*   Input:
*       int month_data[][7]: a 50 by 7 array containing all of sales for each item for the last 6 months  
*   Returns:
*       void
*   Side-effect:
*       creates text file called Total_sales
*/
void get_totals(int month_data[][7])
{
    // initialize Total_sales and open in write mode
    FILE *total_sales;
    total_sales = fopen("Total_sales.txt", "w");

    // double for loops will iterate through months_data array
    // loop iterates through 50 rows (not skipping first row of 0's)
    for (int row = 0; row < 51; row++)
    {
        // initialize running sum and set item code to first row
        int item_sum = 0;
        int item_code = month_data[row][0];

        // loop iterates through 6 columns after the first column (months columns skip item_number column)
        for (int column = 1; column < 7; column++)
        {
            // running sum adds item count for each month to item_sum by iterating through each column
            item_sum = item_sum + month_data[row][column];
        }

        // print item code and item sum to total_sales file
        fprintf(total_sales, "%2d%7d\n", item_code, item_sum);

    }
    // close file
    fclose(total_sales);

}


/*
void get_profits(int month_data[][7], float money[][2])
*       Creates new text file, Profits.txt that contains each item code, total sales, sales price, cost, and revenue (profit)
*   Input:
*       int month_data[][7]: a 50 by 7 array containing all of sales for each item for the last 6 months  
*       float money[][2]: a 50 by 2 array that contains the sales price and cost for each item
*   Returns:
*       void
*   Side-effect:
*       creates text file called Profits.txt
*/
void get_profits(int month_data[][7], float money[][2])
{
    // initialize and open money file Profits in write mode
    FILE *money_file;
    money_file = fopen("Profits.txt", "w");

    // initialize sales price and costs to 0
    float sales = 0.0;
    float costs = 0.0;

    // print headings to Profits file
    fprintf (money_file, "    Item       #   Sales    Cost Revenue\n");

    // replacing 0 with 26 (fixing error)
    month_data[26][0] = 26;

    // double for loops will iterate through months_data array
    // loop iterates through 50 rows (skipping first row of 0's)
    for (int row = 1; row < 51; row++)
    {
        // initializing item sum and item_code variables
        int item_sum = 0;
        int item_code = month_data[row][0];

        // loop iterates through 6 columns skipping the item_code column
        for (int column = 1; column < 7; column++)
        {
            // calculate total number of sales for each item
            item_sum = item_sum + month_data[row][column]; 
        }

        // find sales price and cost for each item
        // calculate revenue (profit)
        sales = money[item_code][0] * item_sum;
        costs = money[item_code][1] * item_sum;
        float revenue = sales - costs;

        // print values for each item to file
        fprintf(money_file, "%8d%8d%8.2f%8.2f%8.2f\n", item_code, item_sum, sales, costs, revenue);

    }
    // close file
    fclose(money_file);

}


/*
void top_earner(int month_data[][7], float money[][2])
*       Creates new text file, Top_earners.txt that contains the 10 items with the highest revenue
*   Input:
*       int month_data[][7]: a 50 by 7 array containing all of sales for each item for the last 6 months  
*       float money[][2]: a 50 by 2 array that contains the sales price and cost for each item
*   Returns:
*       void
*   Side-effect:
*       creates text file called Top_earner.txt
*/
void top_earner(int month_data[][7], float money[][2])
{
    // Initialize top_earners and open file in write mode
    FILE *top_earners_file;
    top_earners_file = fopen("Top_earners.txt", "w");

    // creating a 50 by 2  array that will store item codes and total number of items sold
    int item_sum_list[50][2];

    // loop iterates through all rows (skipping the first row of 0's)
    for (int row = 1; row < 51; row++)
    {
        // initialize item_sum and sets the first column value (item_code) equal to row (1 - 50)
        item_sum_list[row][0] = row;
        int item_sum = 0;

        for (int column = 1; column < 7; column++)
        {
            // running sum adds item count for each month to item_sum by iterating through each column
            item_sum = item_sum + month_data[row][column];
        }

        // place item_sum in the second column of item_sum_list
        item_sum_list[row][1] = item_sum;
    }

    // creating a 50 by 1 array containing the profit of each item
    float profit[50];
    for(int row = 0; row < 51; row++)
    { 
        // calculating profit of each item by suvrtacting cost from sales price using money[][2]
        float individual_profit = (money[row][0] - money[row][1]);

        // profit is equal to individual profit times the total number of that item sold, so we use the previously made list: item_sum_list 
        float profit_value = item_sum_list[row][1] * individual_profit;
        profit[row] = profit_value;
    }

    // finding the top earners
    // print headings to top_earners_file
    fprintf(top_earners_file, "Item   #  Revenue\n");
    
    // loop iterates through 10 teirs
    for (int teir = 1; teir < 11; teir++)
    {
        // initialize top_earner variable
        int top_earner = 0;

        // loop iterates through 50 rows of profit array
        for (int item = 1; item < 51; item++)
        {
            // checks if current item is greater than current top earner and if this is true then top_earner is replaced by current item
           if(profit[item] > profit[top_earner])
           {
                top_earner = item;
           }
          
        }

        // prints the top earner in this iteration to the top_earners_file
        fprintf(top_earners_file, "%4d%4d%9.2f\n", item_sum_list[top_earner][0], item_sum_list[top_earner][1], profit[top_earner]);

        // esnures that this value in the array will not be chosen again 
        profit[top_earner] = 0.0;
    }
    // close file
    fclose(top_earners_file);


}



