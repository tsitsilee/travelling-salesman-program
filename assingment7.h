/* 

assingment6.h - interface file for a program named assignment6
======================================================

This program is for Assignment No. 6, Course 04-630 Data Structures and Algorithms for Engineers. 

Please refer to the application file - assingment6pplication.cpp - for details of the functionality of this program

I included graph.h as as some of the declarations for the signatures are in there to avoid double declarations


File organization
-----------------

assingment6h  :interface file:      
contains the declarations required to use the functions that implement the solution to this problem
typically, these will include the definitions of the abstract data types used in the implementation

assingment6mplementation.cpp  implementation file: 
contains the definitions of the functions that implement the algorithm used in the implementation

assingment6pplication.cpp     application file:    
contains the code that instantiates the abstract data types and calls the associated functions
in order to effect the required functionality for this application

Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
31/03/2020


Acknowledgements
David Vernon Lab 11
TAs;

version 5.0 this code is an update from waveapplication

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
//#include "graph.h"

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define MAX_NUMBER_OF_POINTS 27000 // limit given was 27000 
#define KEY_LENGTH 10
#define STRING_LENGTH 50
#define NUMBER_OF_KEYS 7
#define MAX_STRING_LENGTH 100
#define MAX_N 100
#define MAX_M 100
//#define MAXV 100


/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);


void print_map(FILE *fp_in,   int map[][3], int N, int R); 


int mapping_function(int i,int j,int map_dimension_y);
void get_start_and_destination_coordinates(int map[][3], int map_dimension_x, int map_dimension_y, int *robot_x,int *robot_y,int *goal_x, int *goal_y);


void put_start_and_destination_coordinates(int map[][3], int N, int R, int robot_x, int robot_y,int goal_x, int goal_y);

