/* 

travellingSalesmanImplementation.cpp - application file for the solution of the travelling saleman problem by exhaustive search using backtracking

04-630 Data Structures and Algorithms for Engineers Assignment No. 7

The backtracking code is based on the examples in S. Skiena, The Algorithm Design Manual, 2008.
Most of the functions were reused then edited to suit needs of the assingment

Lynet T Svotwa, Carnegie Mellon University Africa
27/04/2020 

Acknowledgements 
David Vernon
16 April 2018

*/

#include "travellingSalesman.h"



/* original backtracking code ... needs to be adapted for the assignment */
int perm[100][100];
int z;
int counter = 0;
int min_distance = 20000;
int perm_for_min_value[100];
int total_distance;

void backtrack(int a[], int k, int input, int distance[MAX_N][MAX_M], int perm_for_min_value[100],int &min_distance) //pass by reference
{

	int c[MAXCANDIDATES];     /* candidates for next position  */
	int ncandidates;          /* next position candidate count */
	int i;                    /* counter                       */

	if (is_a_solution(a,k,input)) {
		process_solution(a,k,input,distance,perm_for_min_value, min_distance);
	} 
	else {
		k = k+1;
		construct_candidates(a,k,input,c,&ncandidates); 
		for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			//make_move(a,k,input);
			prunning(a,k,distance);
			if(total_distance < min_distance)
			{
			backtrack(a,k,input,distance,perm_for_min_value, min_distance);
			}
			//unmake_move(a,k,input);
		}
	}
}



bool is_a_solution(int a[], int k, int n) {
	return (k == n);
}

//function basically does the same thing as I was in calculating total distance in the solution_process function
//however in this function the last total_distance for the root back to the pizza place is not calculated
void prunning(int a[],int k, int distance[MAX_N][MAX_M]) //attempting to prune
{
	counter = 0;
	int i;  
	 total_distance = 0;
		int cost_dist =0;
		for (i=1; i<=k; i++)
		{
			//printf(" %d",a[i]);
			perm[counter][i-1] = a[i]; //assigning keys for the permutations
			if(i==k)
			{
				
				total_distance = total_distance+ distance[ (a[i]-1)][k]; //calculating distance from the shop
				
			}
			else if(i==1)
			{
				//calculating distance for the delivery to customers
				total_distance =  total_distance + distance[k][ (a[i]-1)];
				total_distance =  total_distance + distance[ (a[i]-1)][((a[i+1])-1)];//next customer delivery
				
			}
		

			counter++; //incrementinng counter
		}
		//printf("%d", total_distance);
	
	
		printf("\n");

	}

void process_solution(int a[], int k, int input,int distance[MAX_N][MAX_M], int perm_for_min_value[100], int &min_distance)
{
	counter = 0;
	int i;                       /* counter */
	bool print_permuations;      /* flag ... set to true if you want the permutations listed to the terminal */

	print_permuations = true;    /* set to true if you want the permutations printed to the terminal; false otherwise */

	if (print_permuations) 
	{
		int total_distance = 0;
		int cost_dist =0;
		for (i=1; i<=k; i++)
		{
			//printf(" %d",a[i]);
			//main thing is calculating the distance for example when moving from 1 to 2 then saving it 
			//the variable total distance will be keeping the sum for each permutation
			//after calculating for that permutation there is eed to reset to reset the total distance to 0 for 
			//next permutations
			perm[counter][i-1] = a[i]; //assigning keys for the permutations
			if(i==k)
			{
				
				total_distance = total_distance+ distance[ (a[i]-1)][k]; //calculating distance from the shop
				
			}
			else if(i==1)
			{
				//calculating distance for the delivery to customers
				total_distance =  total_distance + distance[k][ (a[i]-1)];
				total_distance =  total_distance + distance[ (a[i]-1)][((a[i+1])-1)];
				
			}
			else

			{
				
				total_distance =  total_distance + distance[ (a[i]-1)][((a[i+1])-1)]; //calculation distance back to the shop
				
			}

			counter++; //incrementinng counter
		}
		printf("%d", total_distance);
		if(min_distance > total_distance) // if statement to calculate minimum distance
		{
			min_distance = total_distance; // assigning the new minimum total distance to the min_distance variable
			for (i=1; i<=k; i++) {

				perm_for_min_value[i] = a[i];// keeping track of the permutation for the min_distance
			}
			//printf("perm %d", perm_for_min_value[i]);
		
		}
	
		printf("\n");

	}

}


void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) 
{

	int i;                       /* counter */
	bool in_perm[NMAX];          /* who is in the permutation? */
	for (i=1; i<NMAX; i++)
	{     /* NB: NMAX must be the number of elements in the permutation + 1 to allow for counting from 1, rather than 0 */
		in_perm[i] = FALSE;
	}

	/* the original Skiena code is incorrect ... a[i(==0)] is not a valid element of the permutation since we start storing them at a[1]

	for (i=0; i<k; i++) in_perm[ a[i] ] = TRUE;

	*/

	for (i=1; i<k; i++) in_perm[ a[i] ] = TRUE; // we are finding candidates for a_k, a_k+1, ... a_n
	// when k == 1, all candidates are valid because we haven't selected any yet
	// when k == 2, all candidates except a_1 are valid
	// when k == n, all candidates except a_1 .. a_n-1 are valid
	*ncandidates = 0;
	for (i=1; i<=n; i++) 
	{
		if (in_perm[i] == FALSE) 
		{
			c[ *ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
}


void prompt_and_exit(int status) 
{
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void remove_new_line(char string[]) 
{
	int i;

	i=0;
	while(string[i] != '\0' && string[i] != '\n')
		i++;
	string[i] = '\0';
}

