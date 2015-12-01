#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

using namespace std;

int main (int argc, char *argv[])
{

	ofstream insertOutput;
	insertOutput.open( "insertOutput.txt" );
	
	
	ofstream mergeOutput;
	mergeOutput.open( "mergeOutput.txt" );

	
	ofstream quickOutput;
	quickOutput.open( "quickOutput.txt" );

	srand (time(NULL));
	
	// this for loop iterates through each different size of the data set
	for( int setSize = 100; setSize <= 1000; setSize += 100 )
	{
		sort *sorter = new sort();	// sorts using different algorithms and returns number of comparisons done
		long comparisons[ 50 ];		// holds number of comparisons for a set of 50 tests
		int average;	// average num comparisons across 50 tests of algorithm on one set size
		int *dataSet;

		// loops through all 50 tests to be run per algorithm per set size
		for( int i = 0; i < 50; i++ ) {
			// creates and populates array of size setSize
			dataSet = new int[ setSize ];
			for( int j = 0; j < setSize; j++ )
			{
				dataSet[ i ] = rand() % 1000 + 1;
			}
			
			// sorting and storing number of comparisons done in array
			int length = ( sizeof( dataSet ) / sizeof( *dataSet ) );
			comparisons[ i ] = sorter->iSort( dataSet, length );
		}
		delete [] dataSet;

		// calculates average comparisons across 50 tests
		average = 0;
		for( int i = 0; i < 50; i++ ) {
			average = average + comparisons[ i ];
		}
		average = average / 50;

		// prints average comparisons to file
		insertOutput << setSize << " size set: " << average << endl;
	}

}
