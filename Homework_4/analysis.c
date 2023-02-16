#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define ITEMS 51

// function prototypes
float* readCosts(int);
float* readPurch(int);


int main(int argc, char* argv[]){

    // allocate 51 rows by number of months (plus 1) columns array
    // argc will include the file name itself plus the number of months so we have an extra column for the item code
    int month_data[51][argc];

    // initialize array values to 0
    for (int i = 0; i < 51; i++){ 
        for (int j = 0; j < argc; j++){
            month_data[i][j] = 0;
        }
    }

    // loop over given months
    for (int i = 0; i < argc - 1; i++){
        // initialize variables
        int new_item;
        float cost;
        FILE* f1;
        // open sales files
        f1 = fopen(argv[i + 1], "r");

        // load month data
        // loop will continue as long as it finds an integer followed by a float value
        // fscanf returns a number greater than 0 if true
        while(fscanf(f1, "%d %f", &new_item, &cost) > 0){
            // add data values for all months columns
            month_data[new_item][i+1] = month_data[new_item][i+1] + 1;
            // add item codes to first column
            month_data[new_item][0] = new_item;
            // if 50 item codes are inputted, print integer value to end the loop
            if(new_item > 50){
                printf("%d\n", new_item);
            }
        } 
        // end reading file
        fclose(f1);
    }
 

    //  money function has been split into two separate one-D arrays
    float* purch = readPurch(51);
    float* cost = readCosts(51);

    // call analysis functions
    get_totals(51, argc, month_data);
    get_profits(51, argc, month_data, cost, purch);
    top_earner(51, argc, month_data, cost, purch);

    free(purch);
    free(cost);
    }


/**************************************************
* float* readCosts(int numItems)
*
* Reads the Costs of item column of the the Costs.txt file
* then allocates memory and inputs those values into a one-D array.
*
* Input:
*   numItems: the number of item codes or number of rows in Costs.txt
* Output:
*   Returns a pointer to a one-D array called money_costs
*   containing cost of each item.
***************************************************/
float* readCosts(int numItems){
    FILE* f2 = fopen("Costs.txt", "r");

    float* money_costs = malloc(numItems * sizeof(float));

    float purchase_price;
    int new_item;
    float cost;
    
    int count = 1;

     while(fscanf(f2, "%i %f %f", &new_item, &purchase_price, &cost) > 0){
        money_costs[count] = cost;
        count++;
    }
    fclose(f2);

    return money_costs;

}

/**************************************************
* float* readPurch(int numItems)
*
* Reads the purchase price column of the the Costs.txt file
* then allocates memory and inputs those values into a one-D array.
*
* Input:
*   numItems: the number of item codes or number of rows in Costs.txt
* Output:
*   Returns a pointer to a one-D array called money_purch
*   containing purchase price of each item.
***************************************************/
float* readPurch(int numItems){ 
    FILE* f2 = fopen("Costs.txt", "r");

    float* money_purchase = malloc(numItems * sizeof(float));

    float purchase_price;
    int new_item;
    float cost;
    
    int count = 1;

     while(fscanf(f2, "%i %f %f", &new_item, &purchase_price, &cost) > 0){
        money_purchase[count] = purchase_price;
        count++;
    }
    fclose(f2);

    return money_purchase;
}
