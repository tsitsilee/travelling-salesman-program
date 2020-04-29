/* 

assingment7Implementation.cpp - implementation file for a program named assingment7
============================================================================

This program is for Assignment No. 7, Course 04-630 Data Structures and Algorithms for Engineers. 
Please refer to travellingSalesmanImplementation.cpp file for the functions




Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
28/04/2020




*/

#include "assingment7.h"
//#include "graph.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>


//function to be called when prompting users to close termiaal
//void prompt_and_exit(int status) {
//	printf("Press any key to continue and close terminal\n"); // printing to the screen
//	getchar();
//	exit(status);
//}

void print_message_to_file(FILE *fp, char message[]) 
{ 
	fprintf(fp,"The message is: %s\n", message);
}





//function to read from the input file
//reusing the read_map function form previous assingment 
//void read_map(FILE *fp_in, graph *g, bool directed,int N, int R) 
//{
//	int city1, city2, passengers;
//	int i, j; //initialize variables to be used in the for loops
//	initialize_graph(g, directed); 
//	g ->nvertices = N;
//	for (i=0; i<R; i++) 
//	{
//		
//			fscanf(fp_in, "%d %d %d", &city1, &city2, &passengers); // pass a pointer to the array element to be changed, i.e. the address of the element
//			insert_edge(g,city1,city2,directed,passengers);//inserting the edge with passengers as the weight
//		
//	}
//}












