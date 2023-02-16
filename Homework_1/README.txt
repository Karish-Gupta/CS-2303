This program makes use of 5 functions: get_year_start(int), printCalendar(int, int), printMonth(int, int, int), printMonthName(int, int), and main(void).


The printMonthName function takes in a year integer and a month integer. It returns number of days in the given month and prints the month and year as a heading text to the screen. 
This function uses a switch statement which separates the 12 months by cases marked 0 - 11. 0 corresponds to January and 1 for Febuary and so on. Each case prints 
the corresponding month name and the given year. The corresponding number of days is placed in num_days variable. The case for Febuary has an if statement in the case of 
a leap year. I state that if (the year is divisible by 4 and not 100) or (the year is divisible by 100 and 400), then the year is a leap year and thus the number of days
in Febuary is 29. Otherwise, the number of days is 28. The program then breaks out of the switch statement and returns the number of days.

The printMonth function takes in a year integer and a starting day of the year integer. It prints 1 month of a calendar and returns the start of the next month.
It starts by calling the printMonthName function which prints out month name and year. The printMonthName function returns the number of days in the month so we
store this intger in num_days. Then the days of the week are printed. A for loop is used to iterate from 0 to the starting day of the week to add the proper number 
of spaces before the numbered days begin in the calendar. Another for loop is used to iterate from day 1 to number of days in the given month. The corresponding day 
number is printed for each day and and then the start_day number (corresponding to the current day of the week) is incremented by 1. If we reach the end of the week 
we reset the week loop and enter a new line. We check if the week has ended if the start_day number is greater than 6 and then we set it equal to 0. Finally, once the 
loop has ended, we must return the starting day of the next month. If the day is on sunday, the number will be incremented to 7, so we must reset the start_day to 
0 (monday). Otherwise, the start_day has already been incremented to the next day in the loop and we may return it as the starting day for the next month.

The printCalendar function takes in a year integer and the starting day of the year integer. It first initializes the start_day variable and sets it equal 
to the return value of get_year_start function. This sets the start_day variable to the starting day of January for the given year. Then a for loop iterates 
through all 12 months (0-11) and prints the calendar for each month as a side-effect of calling the printMonth function. The start_day is redefined as the 
return value of printMonth function. This is because the return value of printMonth is the starting day of the next month, so each subsequent month will be 
passed the updated start_day. This ensures that each month starts on the correct day of the week.

The get_year_start function takes in a year integer and returns the starting day of the month. The number returned is between 0 (sunday) and 6 (saturday).
This function was given in the assignement. 

The main function takes in no parameters and returns the integer 0 if run successfully. It prompts the user for a year integer and then calls get_year_start 
to obtain the starting day value of January. It also calls the printCalendar function to print the calendar to screen.



To run calendar.c first compile the code by entering "gcc calendar.c -o calendar.exe" or "gcc -Wall calendar.c -o calendar.exe" into the terminal.
Then you may run the code by entering "./calendar.exe" into the terminal. 

When writing my code, I had many issues with the formatting of the correct starting day of each month. There were many times when some months would have the corrext 
starting day and others would not. However, I got some help from TA Jatin Kohli. He was a major help in figuring out exactly where I should look for errors. He pointed me
in the right direction and I found that my main issue was in how only January had a different start day value and the rest used the same one instead of an updated one. So,
I made sure to return an updated start day value for each month.