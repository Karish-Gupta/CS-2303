#include <stdio.h>
#include "analysis_functions.h"
#include <stdlib.h>


#define ITEMS 51

int main(void){

    // allocate arrays to store 6 months of data
    int month_data[ITEMS][7];
    float money[ITEMS][2];

    // initialize money and month_data to zeros
    for (int i = 0; i < 7; i ++){
        for (int j = 0; j < ITEMS; j++){
            month_data[j][i] = 0;
        }
    }
    for (int i = 0; i < ITEMS; i++){
        money[i][0] = 0;
        money[i][1] = 0;
    }

    int new_item;
    float cost;

    //loop over all months
    for (int i = 0; i < 6; i++){
        FILE* f1;
        // open sales file
        switch (i) {
            case 0:
                f1 = fopen("Jan_data.txt", "r");
                break;
            case 1:
                f1 = fopen("Feb_data.txt", "r");
                break;
            case 2:
                f1 = fopen("Mar_data.txt", "r");
                break;
            case 3:
                f1 = fopen("Apr_data.txt", "r");
                break;
            case 4:
                f1 = fopen("May_data.txt", "r");
                break;
            case 5:
                f1 = fopen("Jun_data.txt", "r");
                break;
        } // end switch

        // load sales data


        while(fscanf(f1, "%d %f", &new_item, &cost) > 0){
            month_data[new_item][i+1] = month_data[new_item][i+1] + 1;
            month_data[new_item][0] = new_item;
        }
        fclose(f1);

    } // end loop over months


    // load sales data
    FILE* f2 = fopen("Costs.txt", "r");
    float purchase;

    while(fscanf(f2, "%i %f %f", &new_item, &purchase, &cost) > 0){
        money[new_item][0] = purchase;
        money[new_item][1] = cost;
    }
    fclose(f2);



/*
    // printing out the array for months_data
    for(int rows = 0; rows < 51; rows++)
  	{
  		for(int columns = 0; columns < 1; columns++)
  		{
  			printf("%f  ", profit[rows]);
		}
   		printf("\n");
  	}  	
*/



    // call all 3 functions here

    // call get_totals
    get_totals(month_data);
    
    // call get_profits
    get_profits(month_data, money);

    // call top_earner
    top_earner(month_data, money);


}





   



