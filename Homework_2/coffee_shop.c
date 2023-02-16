#include <stdio.h>
#include <stdlib.h>
#include "register.h"

int main(void)
{
    // initialize variables
    // option 1, 2, or 3 will be stored here
    int operation; 
    FILE *f1;
    // file name of up to 100 characters will be stored here
    char file_name[100];

    // prompt user for option 1, 2, or 3 and take in value from terminal
    printf("Which program would you like to run: (1) Calculate overall revenue, (2) Calculate register balance, or (3) Calculate sales for an item.\n");
    scanf("%d", &operation);

    // prompt for input file and take in string from terminal 
    printf("Please enter an input file:\n");
    scanf("%s", file_name);

    // open file in read mode and set equal to pointer f1
    f1 = fopen(file_name, "r");

    // if statement for each option: 1, 2, 3
    // if valid number is not entered then prints error message and exits program
    if (operation == 1)
    {
        // call overall_revenue function 
        float revenue = overall_revenue(f1);

        // print revenue and close file
        printf("%0.2f\n", revenue);
        fclose(f1);

    }
    else if (operation == 2)
    {
        // call balance function 
        float register_balance = balance(f1);

        // print revenue and close file
        printf("%0.2f\n", register_balance);
        fclose(f1);

    }
    else if (operation == 3)
    {
        // initialize variables
        int item;
        char output_file_name[100];
        char append_overwrite;
        FILE *f2;

        // prompt user for which item to check for and take int from terminal
        printf("Which item to analyze?\n");
        scanf("%d", &item);

        // call tally and place returned count in count variable
        int count = tally(f1, item);

        // prompt user for output file and take in string from terminal
        printf("What is the output file?\n");
        scanf("%s", output_file_name);

        // prompt user for append or overwrite option and take char (A or O) from terminal
        printf("Enter A for Append or O for over-write.\n");
        scanf(" %c", &append_overwrite);

        // if user entered A, then append item code and count to file 
        // otherwise (user enters O) overwrite the file
        // if the given output file does not exist, a new file of that name will be created
        if (append_overwrite == 'A')
        {
            // open output file in append mode
            f2 = fopen(output_file_name, "a");
            // print to file then close file
            fprintf(f2, "  %d   %d\n", item, count);
            fclose(f2);
        }
        else
        {
            // open output file in write mode
            f2 = fopen(output_file_name, "w");
            // print to file then close file 
            fprintf(f2, "  %d   %d\n", item, count);
            fclose(f2);
        }
        
    }
    else
    {
        printf("This option is not valid.");
        exit(1);
    }

    // return 0 if program ran successfully
    return 0;
}

