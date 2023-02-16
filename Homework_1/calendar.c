#include <stdio.h>

// Function prototypes
// You may modify these

int get_year_start(int);            // takes year, returns day that year starts on
void printCalendar(int, int);       // takes year and start day, prints 12 months
int printMonth(int, int, int);      // takes year, month and start day of month, prints 1 month, returns start of next month
int printMonthName(int, int);       // takes year and month number, prints header for that month, returns number of days in month

/*
main()
Executes program: prints prompt to screen, takes in year integer input, 
and then calls get_year_start to obtain day value and printCalendar function to print calendar to screen.
Input: 
    void
Returns: 
    Integer 0 if program runs successfully
Calls: 
    get_year_start
    printCalendar
*/
int main(void)
{
    // initialize year and day variables
    int year;
    int day;

    // print prompt for year to screen
    printf("Please enter year for this calendar:\n");
    // take in year integer
    scanf("%d", &year);

    // store year integer in starting day variable for the given year
    day = get_year_start(year);

    // print out calendar for month text
    printf("***   CALENDAR for %d   ***\n\n", year);

    // call print calendar function to print out calendar to screen
    printCalendar(year, day);

    // return 0 if program runs successfully
    return 0;
}

/********************************************************
*   get_year_start()
*   Determines the day of the week that the specified
*   year starts on. Uses current calendar rules (ignores calendar changes)
*   Input:
*       year: the year being studied
*   Returns:
*       The day of the week the year starts on
*       0: Sunday, 1: Monday, etc
*   Source:
*       https://stackoverflow.com/questions/478694/what-is-the-easiest-algorithm-to-find-the-day-of-week-of-day-zero-of-a-given-year
*********************************************************/
int get_year_start(int year)
{
    int year_start =  (((year-1) * 365) + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400) + 1) % 7;
    return year_start;
}

/********************************************************
*   printCalendar(int year, int day)
*   Prints 1 year of a calendar
*   Input:
*       year: the year being studied
*       day: the day of the week that the year starts on
*   Returns:
*       void or nothing
*   Calls: 
*       printMonth
*********************************************************/
void printCalendar(int year, int day)
{
    // initialize start_day variable and set equal to return value of get_year_start function
    int start_day = get_year_start(year);

    // loop iterates for all 12 months (0-11) and prints calendar for each month as a side-effect
    // the start_day is redefinded as the return value of printMonth
    // the return value of printMonth is the starting day of the next month
    // this ensures that each month starts on the correct day of the week
    for (int i = 0; i < 12; i++)
    {
        start_day = printMonth(year, i, start_day);

        // add spacing 
        printf("\n\n");
    }
}

/********************************************************
*   printMonth(int year, int month, int start_day)
*   Prints 1 month of a calendar, returns the start of the next month
*   Input:
*       year: the year being studied
*       month: the month to be printed
*       start_day: the day of the week that the month starts on
*   Returns:
*       The start day of the next month
*   Calls: 
*       printMonthName
*********************************************************/
int printMonth(int year, int month, int start_day)
{
    // print out month name and year by calling printMonthName function
    // function returns the number of days in the month so it is stored in num_days
    int num_days = printMonthName(year, month);

    // print space 
    printf("\n");

    // print out days of the week
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 
 
    // for loop iterates from day 0 to the start day of the week
    // i = number of empty spaces until the start of the month
    for (int i = 0; i < start_day; i++)
    {
        // prints 5 spaces between days
        printf("     "); 
    }
    // for loop iterates from day 1 to number of days in the given month
    // n = number of days in the month
    for (int n = 1; n <= num_days; n++) 
    { 
        // if we reach the end of the week we reset the week loop and enter a new line
        if (start_day > 6) 
        { 
            //reset loop and enter new line
            start_day = 0; 
            printf("\n"); 
        }

        // print the day number of the month
        printf("%5d", n); 
        // increments the day of the week
        start_day++;
    }
    

    // return the start of the next month
    // if the day is on sunday, the number will be incremented to 7
    // so we must reset the start_day to 0 (monday)
    if (start_day == 7)
    {
        start_day = 0;
        return start_day;
    }
    
    // return the start day of the next month
    return start_day;

}

/********************************************************
*   printMonthName(int year, int month)
*   prints header for the month, returns number of days in month
*   Input:
*       year: the year being studied
*       month: the month to be printed
*   Returns:
*       The number of days in the month
*********************************************************/
int printMonthName(int year, int month)
{
    // variable tracks the number of days for a given month
    int num_days;

    // switch statement separates the 12 months by cases marked 0 - 11
    // each case prints the corresponding month name and the given year
    // the corrsponding number of days is placed in num_days variable
    switch(month)
    {
        case 0: 
            printf("January %d\n", year);
            num_days = 31;
            break;

        case 1: 
            // if the year is a leap year then the number of days should be 29 in Feb 
            // otherwise number of days should be 28
            if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
            {
                printf("February %d\n", year);
                num_days = 29;
            }
            else 
            { 
                printf("February %d\n", year);
                num_days = 28;
            }
            
            break;
        
        case 2: 
            printf("March %d\n", year);
            num_days = 31;
            break;

        case 3: 
            printf("April %d\n", year);
            num_days = 30;
            break;

        case 4: 
            printf("May %d\n", year);
            num_days = 31;
            break;

        case 5: 
            printf("June %d\n", year);
            num_days = 30;
            break;

        case 6: 
            printf("July %d\n", year);
            num_days = 31;
            break;

        case 7: 
            printf("August %d\n", year);
            num_days = 31;
            break;

        case 8: 
            printf("September %d\n", year);
            num_days = 30;
            break;
        
        case 9: 
            printf("October %d\n", year);
            num_days = 31;
            break;
        
        case 10: 
            printf("November %d\n", year);
            num_days = 30;
            break;
        
        case 11: 
            printf("December %d\n", year);
            num_days = 31;
            break;
    }

    // returning the number of days corresponding to the given month
    return num_days;
}