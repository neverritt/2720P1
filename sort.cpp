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
	for(int i = 0; i < (argc-2); i++){
		array[i] = atoi(argv[i+2]); // atoi converts argv[i] to int
	}	
	int length = (sizeof(array)/sizeof(*array));
	sort *sorter = new sort();
	long comparisons;	
	
	// sort -i, -m, or -q
	if(strcmp(argv[1],"-i") == 0){ // i-sort
		comparisons = sorter->iSort(array, length);
		cout << "Insertion sort: ";
	} else if (strcmp(argv[1],"-m") == 0){ // m-sort
		comparisons = sorter->mSort(array, 0, length-1);	
		cout << "Merge sort: ";
	} else if (strcmp(argv[1],"-q") == 0){ // q-sort
		comparisons = sorter->qSort(array, 0, length-1);
		cout << "Quick sort: ";
	}

	// print new array, it's length, # comparisons
	for (int i = 0; i < length; i++){
		cout << array[i] << " ";		
	}	
	cout << endl;
	cout << "Input size: " << length << endl; // print length
	cout << "Total # comparisons: " << comparisons << endl;
	return 0;
}
