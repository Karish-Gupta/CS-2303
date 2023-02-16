#include <stdio.h>
#include "register.h"

/*
 float overall_revenue(FILE *f1);
*       Calculates the total revenue for the day
*   Input:
*       FILE *f1: the file containing the day's sales and starting balance
*   Returns:
*       The overall revenue of the day 
*/
float overall_revenue(FILE *f1)
{
    // intialize variables
    float overall_revenue = 0;
    // item code that represents the item ex. 3 for bananas
    int item_code;
    float item_price;    

    // continues to loop if fscanf finds an integer value and a float value
    // fscanf returns the number of fields it converts, so it should return 2 if it finds an int value and a float value
    // the loop will end if an int followed by a float is not scanned
    while(fscanf(f1, "%d %f", &item_code, &item_price)  == 2)
    {
        // if statement checks if item code represents day starting balance
        // sets the item price to 0 to negate adding the balance
        if( item_code == 0)
        {
            item_price = 0;
        }

        // adds the item price to a running sum
        overall_revenue = overall_revenue + item_price;

    }
    
    // returns the total revenue
    return overall_revenue;

}


/*
 float balance(FILE *f1);
*       Calculates the total balance in the cash regsister at the end of the day
*   Input:
*       FILE *f1: the file containing the day's sales and starting balance
*   Returns:
*       The balance at the end of the day
*/
float balance(FILE *f1)
{
    // initialize variables
    float days_balance;
    // item code that represents the item
    int item_code;
    float item_price;    

    // continues to loop if fscanf finds an integer value and a float value
    // fscanf returns the number of fields it converts, so it should return 2 if it finds an int value and a float value
    // the loop will end if an int followed by a float is not scanned 
    while(fscanf(f1, "%d %f", &item_code, &item_price)  == 2)
    {
        // the starting day balance will also be treated as an item
        // so it will be added to the total days_balance
        days_balance = days_balance + item_price;
    }
    
    // returns the total days_balance
    return days_balance;

}


/*
int tally(FILE *f1, int item);
*       Tallies the number of times a specific item was sold and the total and calculates the revenue from that item
*   Input:
*       FILE *f1: the file containing the day's sales and starting balance
*       int item: the item number that is associated with a specific item
*   Returns:
*       The number of times an item was sold
*/
int tally(FILE *f1, int item)
{
    // initialize variables
    float count;
    // item code that represents the item
    int item_code;
    float item_price;    

    // continues to loop if fscanf finds an integer value and a float value
    // fscanf returns the number of fields it converts, so it should return 2 if it finds an int value and a float value
    // the loop will end if an int followed by a float is not scanned. 
    while(fscanf(f1, "%d %f", &item_code, &item_price)  == 2)
    {
        // if the item code is equal to the item code of the item we are looking for
        // we will increase the count by 1
        if (item_code == item)
        {
            count++;
        }
    }
    
    // returns a count integer
    return count;
}

