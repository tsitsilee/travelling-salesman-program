/* 

assingment7Application.cpp - Application file for a program named assingment7
============================================================================

application file for the solution of the travelling saleman problem by exhaustive search using backtracking
This program is for Assignment No. 7, Course 04-630 Data Structures and Algorithms for Engineers. 


Pseudocode
----------
Create assingment 7 and copy the travellingSalesman code to the assingment7Application.cpp 
read and understand the given code  
the solution strategy was as follows 
		The solution uses combinatorial search with backtracking 
		Hence we seek the permutation of the locations that provides the minimum length tour.
		Instead of enumerating permutations of the location names and addresses 
		we associate an integer key with each location and form permutations of these keys.

From understanding the code it was perfforming the permutations and backtracking 
this meant verifying if 
	the solution for reading the input file and verify that it is working correctly
	the backtrack code from the lectures generates the permutations of the keys for each test case
upon successful verification Inside the travellingSalesmanImplemention file
I modified the process_solution function to ensure that
	when passed a given permutation and the distance matrix, computes the
	total distance for that route (including the distance travelled from the restaurant to the first
	drop-off location and the distance from the last drop-off location to the restaurant).
	to do this I needed to
	calculate the distance for example when moving from 1 to 2 immediately then saving it in the
	the variable total distance will be keeping the sum for each permutation
	after calculating for that permutation there is eed to reset to reset the total distance to 0 for next permutations

Upon success
I then inserted an if statemnt to calculate the minimum distance and the associated permutation but to achieve this
	I declared the variable  min_distance with a very high value such that I passed it inside the if statement by value, ensuring that it will be
	assinged the minimum value during the process.
however to achieve all this I had to modify the paramaeters of process_solution  and back track as follows by adding more parameters 

I declare the min_distance array in the application file then passed it as arguments in the backtracking
 in my .h my min_distance was be passed as reference meaning Int &min_distance
 in the implementation file I Added that new array in backtracking  function as parameter as well as in the process_solution function
 however before passing it as argument, I assigned it a max int value so that it start on that max int on each scenario

 In the main function 
	After calling backtracking file
	I printed the new array that hold the permutations to the terminal to check if it was working
	however I started this array index at 0
	for it to work I made a for loop  to print that new array you have created

The values of permutation are provided by the array called a[] so after calculating total distance I added an
if statement and inside the if statement I added a for loop that iterate through a then store those values

to print to output file
	So rather than printing the array that hold permutation for min_distance I just printed record by 
	making use of .string like this record[permutation_min[i]-1].string
	Remembering that always the restaurant is on the start position and end position
		I print the restaurant before that loop and after that loop since it was at the position n of my array I could simply 
		make os the record array like this  Record[n].string



Assumptions made
----------------
that therr wont be less than 1 delivery 
that the max delivery wont be more than 10 customers

Attempted pruning
------------------
Having that I could calculate the total distance
I created a function that would calculate the total distance between the pizza place to the last customer but not back the pizza place
I then called this function inside the backtrack function inside the for loop 
just after calling the pruning_function I then put an IF condition that check if the current total_distance is < than min_distance
inside that if condition is where I put the backtrack function  to ensure that when the permutations are being generated 
it will "prune the backtrack tree when a partial solution (i.e. a partiallyconstructed permutation) is encountered that yields a distance
greater than the distance associated with the best complete permutation so far." lab13

I emphasis I wrote attempted pruning



Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
01/02/2020
revision date 12/04/2020
version 7 revision date 28/04/2020

acknowledgements
David Vernon Lab 13, graphImplemention code 
TA's for guidance
Gaston Karamba



testing
---------

Test to see if it will print my andrewID to the output file
test to see if it prints the test_case number to the output file
test to see if it prints the correct minimum_distance after the test_case_number
test to see if it prints the first test case as expected from the assingment
test to see if it prints for 1 customer delivery
test to see if it prints for more than 4 customer delivery
test to see if it will scale up
test to see if the pruning function if functioning properly by printing to terminal checking if it prints less 


*/
// main program for where the program is first executed
/* 


****************************************************************************************************************
*** This program only provides functionality for reading the test input and calling the generic backtrack    ***
*** function to print the permutations.                                                                      ***
***                                                                                                          ***
*** It must be extended to complete the assignment.                                                          ***
***                                                                                                          ***
*** The program prints the input to the terminal to verify that it has been read correctly.                  ***
***                                                                                                          ***
*** Since there are n! permutations for n destinations, printing the permutations can be distracting,        ***
*** although worth doing at least once to verify that permutations are being computed correctly.             ***
*** If you do want the n! permutations printed to the terminal, set the print_permuations flag to true       ***
*** in the process_solution() function. This function is located in the implementation file.                 ***
****************************************************************************************************************

OptiPizza – a new pizza restaurant – wants to minimize its delivery costs while not compromising on delivery times 
by delivering pizzas in batches to a small number of customers. To do this, they need to know the best route linking 
their pizza restaurant and the customers for each delivery run.  Given the distance between each customer drop-off point 
and the distance from the restaurant to each customer drop-off point, this application produces an optimal route for OptiPizza, 
i.e. the sequence in which a delivery moto should call to the customers after leaving the restaurant, returning to the restaurant 
once all pizzas have been delivered. The delivery moto calls to each customer location only once.

Input data for several test cases is provided in an input file: input.txt
Output for each test case is written to an output file: output.txt


Input
-----

- The first line of the input file consists of an integer number k specifying the number of test cases in the file.  
- This is followed by the data specifying each test case, beginning on the next line.  
- There are no blank lines in the input file.
- Each test case begins with a line containing an integer number n giving the number of pizza drop-offs locations. 
- This is followed by n+1 lines containing 

-- the n locations (i.e. the names and addresses) of each customer 
-- followed by the location of the restaurant. 
-- It is assumed that n < 10 and that each address is on a separate line.  

- This is followed by n+1 lines each containing n+1 integers specifying the distances between each location (including itself).  
- The jth number on line i gives the distance from location i to location j. 
- The j+1st number on line i gives the distance from customer i to the restaurant.  
- Note that the distance from location i to location j may not be the same as the distance from location j to location i 
since you may not be able to take the same path (we assume the delivery drivers obey the law and don’t drive the wrong way 
on a one-way street).  
- Line n+1 gives the distance of the restaurant to each customer location.


Output
------

- The first line of the output file contain the author's Andrew Id.

- For each test case in the input

-- The test case number is printed on a separate line
-- The total distance that needs to be travelled is printed on the next line
-- This is followed the sequence of customers that the delivery moto should use to minimize distance, 
starting at the restaurant and returning to the restaurant.

Each customer name and address is printed on a separate line

- If there is more than one tour (i.e. route from the restaurant to all delivery locations and back to the shop) 
that gives the same minimum distance, it prints the first one found.


Sample Input
------------
10
4
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
Ms. Altname, #3 Alt Street.
Ms. Ctrlaltname, #4 Del ete Street.
OptiPizza, #1 Mozzarella Road.
0 3 10 5 12
3 0 10 8 6
10 11 0 3 6
5 8 4 0 6
12 6 9 7 0
2
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
OptiPizza, #1 Mozzarella Road.
0   7  20
4   0  15
10  5  0
4
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
Ms. Altname, #3 Alt Street.
Ms. Ctrlaltname, #4 Del ete Street.
OptiPizza, #1 Mozzarella Road.
0   3  10  5 12
3   0  10  8  6
10 11   0  3  6
5   8   4  0  6
12  6   9  7  0
1
Mr. Somename, #1 Some Street.
OptiPizza, #1 Mozzarella Road.
0   4
5   0
5
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
Ms. Altname, #3 Alt Street.
Ms. Ctrlaltname, #4 Del ete Street.
Mr. Nextone, #5 Esc Street
OptiPizza, #1 Mozzarella Road.
0   4  9  6  11   5
5   0 11  7   5  10
10 20  0  2   5   7
5   9  4  0   7   2
12  8  8  8   0  12
5   9  4  3   6   0
6
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
Ms. Altname, #3 Alt Street.
Ms. Ctrlaltname, #4 Del ete Street.
Mr. Nextone, #5 Esc Street
Mr. Nextone, #6 Escgh Street
OptiPizza, #1 Mozzarella Road.
0   4  9  6  11   5 5
5   0 11  7   5  10 5
10 20  0  2   5   7 5
5   9  4  0   7   2 5
12  8  8  8   0  12 5
5   9  4  3   6   3 5
5   9  4  3   6   3 0
7
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
Ms. Altname, #3 Alt Street.
Ms. Ctrlaltname, #4 Del ete Street.
Mr. Nextone, #5 Esc Street
Mr. Nextone, #6 Escgh Street
Mr. Nextone, #7 Ecgh Street
OptiPizza, #1 Mozzarella Road.
0   4  9  6  11   5 5 4
5   0 11  7   5  10 3 8
10 20  0  2   5   7 1 8
5   9  4  0   7   2 5 7
12  8  8  8   0  12 5 0
5   9  4  3   6   3 5 9
5   9  4  3   6   3 0 0
10 20  0  2   5   7 1 0
5
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someother Street.
Ms. Altnazzme, #3 Alzt Street.
Ms. Ctrlazzltname, #4 Dezdl ete Street.
Mr. Nextone, #5 Esc Street
OptiPizza, #1 Mozzarella Road.
0   4  9  6  11   5
5   0 11  7   5  8
10 20  0  2   5   7
5   2  4  0   7   2
12  8  1  8   0  12
5   9  4  3   6   0
5
Mr. Somename, #1 Some Street.
Mr. Someothername, #2 Someothfer Street.
Ms. Altname, #3 Alt Street.
Ms. Ctrlaltname, #4 Dedl ete Street.
Mr. Nextone, #5 Esfc Street
OptiPizza, #1 Mozzarella Road.
0   4  9  6  25   5
5   0 11  7   5  10
10 20  0  2   5   7
5   9  4  0   7   2
12  8  30  3   0  12
5   9  4  3   6   0
2
Mr. Somename, #1 Some Street.
Ms. Altname, #2 Alt Street.
OptiPizza, #1 Mozzarella Road.
0   9  20
4   6  15
10  5  0


Sample Output
-------------
lsvotwa  (attempted_pruning)
1
24
OptiPizza, #1 Mozzarella Road. 
Mr. Someothername, #2 Someother Street. 
Mr. Somename, #1 Some Street. 
Ms. Ctrlaltname, #4 Del ete Street. 
Ms. Altname, #3 Alt Street. 
OptiPizza, #1 Mozzarella Road. 

2
29
OptiPizza, #1 Mozzarella Road. 
Mr. Someothername, #2 Someother Street. 
Mr. Somename, #1 Some Street. 
OptiPizza, #1 Mozzarella Road. 

3
24
OptiPizza, #1 Mozzarella Road. 
Mr. Someothername, #2 Someother Street. 
Mr. Somename, #1 Some Street. 
Ms. Ctrlaltname, #4 Del ete Street. 
Ms. Altname, #3 Alt Street. 
OptiPizza, #1 Mozzarella Road. 

4
4
OptiPizza, #1 Mozzarella Road. 
Mr. Somename, #1 Some Street. 
OptiPizza, #1 Mozzarella Road. 

5
26
OptiPizza, #1 Mozzarella Road. 
Mr. Somename, #1 Some Street. 
Mr. Someothername, #2 Someother Street. 
Mr. Nextone, #5 Esc Street 
Ms. Altname, #3 Alt Street. 
Ms. Ctrlaltname, #4 Del ete Street. 
OptiPizza, #1 Mozzarella Road. 

6
27
OptiPizza, #1 Mozzarella Road. 
Ms. Altname, #3 Alt Street. 
Ms. Ctrlaltname, #4 Del ete Street. 
Mr. Nextone, #6 Escgh Street 
Mr. Somename, #1 Some Street. 
Mr. Someothername, #2 Someother Street. 
Mr. Nextone, #5 Esc Street 
OptiPizza, #1 Mozzarella Road. 

7
20
OptiPizza, #1 Mozzarella Road. 
Ms. Altname, #3 Alt Street. 
Mr. Nextone, #7 Ecgh Street 
Ms. Ctrlaltname, #4 Del ete Street. 
Mr. Nextone, #6 Escgh Street 
Mr. Somename, #1 Some Street. 
Mr. Someothername, #2 Someother Street. 
Mr. Nextone, #5 Esc Street 
OptiPizza, #1 Mozzarella Road. 

8
19
OptiPizza, #1 Mozzarella Road. 
Mr. Somename, #1 Some Street. 
Mr. Someothername, #2 Someother Street. 
Mr. Nextone, #5 Esc Street 
Ms. Altnazzme, #3 Alzt Street. 
Ms. Ctrlazzltname, #4 Dezdl ete Street. 
OptiPizza, #1 Mozzarella Road. 

9
28
OptiPizza, #1 Mozzarella Road. 
Mr. Somename, #1 Some Street. 
Mr. Someothername, #2 Someothfer Street. 
Mr. Nextone, #5 Esfc Street 
Ms. Ctrlaltname, #4 Dedl ete Street. 
Ms. Altname, #3 Alt Street. 
OptiPizza, #1 Mozzarella Road. 

10
29
OptiPizza, #1 Mozzarella Road. 
Ms. Altname, #2 Alt Street. 
Mr. Somename, #1 Some Street. 
OptiPizza, #1 Mozzarella Road. 




David Vernon
15 April 2020
*/

#include "travellingSalesman.h"

int main() {

	struct record_type record[NUMBER_OF_STOPS];

	int i, j, k;                                      // general purpose counters
	int n,o,p;                                            // number of customer drop-off locations
	int number_of_test_cases = 0;                         //
	char stop_name[STRING_SIZE];                      // general purpose string
	int distances[NUMBER_OF_STOPS][NUMBER_OF_STOPS];  // distances between shop i (row) and shop j (column)
	int a[NMAX+1];   
	int min_dist;                             // permutation of locations
	int dist;
	int permutation_for_min_value[100];
	int minimum_distance =2000;

	int debug = TRUE;                                 // flag: if TRUE print information to assist with debugging

	FILE *fp_in, *fp_out;                             // input and output file pointers


	/* open input and output files */

	if ((fp_in = fopen("../data/input.txt","r")) == 0) {
		printf("Error can't open input input.txt\n");
		exit(0);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");
		exit(0);
	}
	
	/* read the number of test cases */

	fscanf(fp_in, "%d", &number_of_test_cases);
	fgetc(fp_in); // move past end of line for subsequent fgets; fgets fails unless we do this

	if (debug) printf ("%d\n", number_of_test_cases);
	//disclaimer I wrote attemted prunning
	fprintf(fp_out, "lsvotwa  (attempted_pruning)\n");//printing andrewid to output file
	//fprintf (fp_out,"%d\n", number_of_test_cases);

	/* main processing loop, one iteration for each test case */

	for (k=1; k<=number_of_test_cases; k++) 
	{
		fprintf (fp_out,"%d\n", k);

		/* read the data for each test case  */
		/* --------------------------------  */

		/* number of customer drop-off locations */

		fscanf(fp_in, "%d", &n);
		fgetc(fp_in);  // move past end of line for subsequent fgets

		if (debug) printf ("%d\n",n);
		

		/* get the location names and the restaurant name */

		for (i = 0; i < n+1; i++) 
		{

			fgets(stop_name, STRING_SIZE, fp_in);
			remove_new_line(stop_name);

			record[i].key = i+1;
			strcpy(record[i].string,stop_name);

			if (debug) printf ("%s\n",record[i].string);
		}

		/* get the matrix of distances */

		for (i = 0; i < n+1; i++) {
			for (j = 0; j < n+1; j++) {
				fscanf(fp_in, "%d", &(distances[i][j]));
			}
		}

		if (debug) {
			for (i = 0; i < n+1; i++) {
				for (j = 0; j < n+1; j++) {
					printf("%3d ", distances[i][j]);
					//dist=dist + distances[i][j];


				}
				printf("\n");
			}
		}


		/* main processing begins here */
		/* --------------------------- */

		/* use backtracking to generate all permutations and store the permutation giving the highest value */

		backtrack(a,0,n,distances, permutation_for_min_value, minimum_distance);    // this is the original call and will just print the permutations to the terminal
		// it must be modified to pass the distances array as an argument
		// so that the permutation giving the minimum distance can be identified
		// it may also be useful to have it return the permutation yielding the minimum distance
		// Remember: these permutations are for numbers 1 to n, not 0 to n-1
		// this matters when you use the permutation elements to access the distance array
		printf("%s \n ", record[n].string);
		//printing to output file
		fprintf (fp_out,"%d\n",minimum_distance);
		fprintf(fp_out,"%s \n", record[n].string);
		for (o=1; o<=n; o++) 
		{
			//permutation_for_min_value[o] = a[o];
			printf("\n");
			//fprintf(fp_out,"\n");
			//printf("minimum dist %d perm %d", minimum_distance, permutation_for_min_value[o]);
			printf("%s \n ", record[permutation_for_min_value[o]-1].string);
			fprintf(fp_out,"%s \n", record[permutation_for_min_value[o]-1].string);
		}
		// printf("minimum dist %d perm %d", minimum_distance, permutation_for_min_value);
		printf("%s \n ", record[n].string);
		//fprintf(fp_out,"\n");
		fprintf(fp_out,"%s \n", record[n].string);
		fprintf(fp_out,"\n");
		printf("\n");

		/* now process the result here ... */

		//k++;
		
		minimum_distance = 2000;
		//int distances[][];
	}

	//minimum_distance = 2000;

	fclose(fp_in);
	fclose(fp_out);     

	
	//if (debug) prompt_and_exit(1);
}