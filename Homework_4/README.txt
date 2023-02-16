To run this program, I made use of a makefile. 
To compile the code enter: mingw32-make
To run the code enter: ./analysis.exe

This program takes in month data from the command line and a Costs.txt. It then iterates through the month data and inputs this data into a 2-D array called month_data. 

Function readCosts takes in a number of items and uses the Costs.txt to create a 1D array with all of the items costs. First malloc is used to allocate memory in the heap for the number of items. A while loop contains a fscanf statement which scans for an integer followed by two floats and this continues to loop until the three corresponding values are not found. Within the loop, the cost array is populated with cost values. This array is returned and passed into the previously defined functions from HW3. Function readPurch uses the same exact logic except it populates its array with purchase price values instead of cost values. The readPurch function also returns a 1D array.

The previously made functions (get_totals, get_profits, and top_earner) are relatively the same. Their arguments are different as get_profits and top_earner both take in two 1D arrays in the place of the 2D money array that was previously defined. So, there were a few minor changes made in syntax, but the core logic remained the same as HW3. 

I did not use any outside resources for this assignment other than going to one office hours session. I attended Professor Mortensen’s office hours and she was able to help me fix some major bugs in my code. The biggest issue I was having was getting the for loop indexing correct. There was a tricky indexing error in readCost and readPurch functions (the count needed to start at 1 and not 0). However, after careful inspection we were able to figure it out.
