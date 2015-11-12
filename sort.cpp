/** Names: Patrick Stroud and Nathan Everritt
 *  Project 3 : Sorting
 *
 *  Purpose: The executable file. sort.cpp processes cmd line arguments containing
 *  one flag indicating the sorting method, followed by a set of
 *  integers to pass as input.
 */
#include "sort.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cstdlib> // for atoi

using namespace std;

int main(int argc, const char * argv[]){
	if( argc < 3 ) {
		cout << "usage: ./sort -sortflag [set of integers] (no brackets)" << endl;
		exit(EXIT_FAILURE);
	}

	// initialize array of size argc - 2 (program and flag)
	int array[argc-2];
	for(int i = 2; i < (argc); i++){
		array[i] = atoi(argv[i]); // atoi converts argv[i] to int
	}	
	
	sort *sorter = new sort();
	// flag can be -i, -m, or -q
	if(strcmp(argv[1],"-i") == 0){ // i-sort
		sorter->iSort(array);
	} else if (strcmp(argv[1],"-m") == 0){ // m-sort
		sorter->mSort(array);		
	} else if (strcmp(argv[1],"-q") == 0){ // q-sort
		sorter->qSort(array);
	}

	return 0;
}
