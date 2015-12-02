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
	for( int setSize = 1000; setSize <= 100000; setSize += 1000 )
	{
		sort *sorter = new sort();	// sorts using different algorithms and returns number of comparisons done
		long average;	// average num comparisons across 50 tests of algorithm on one set size
		int *dataSet;	// holds set of random numbers to be sorted

		/*------------------------ MERGE SORT TESTING -----------------------------*/
		
		average = 0;
		// loops through all 50 tests to be run per algorithm per set size
		for( int i = 0; i < 50; i++ ) {
			// creates and populates array of size setSize
			dataSet = new int[ setSize ];
			for( int j = 0; j < setSize; j++ )
			{
				dataSet[ i ] = rand()%1000;
			}
			
			// sorting and storing number of comparisons done in array
			average +=  sorter->mSort( dataSet, 0, setSize - 1 );
		}
		delete [] dataSet;

		// calculates average comparisons across 50 tests
		average = average / 50;

		// prints average comparisons to file
		mergeOutput << setSize << " size set: " << average << endl;

		/*------------------------ MERGE TESTING FINISHED -------------------------*/


		/*-------------------------- INSERT SORT TESTING --------------------------*/

		average = 0;
		// loops through all 50 tests to be run per algorithm per set size
		for( int i = 0; i < 50; i++ ) {
			// creates and populates array of size setSize
			dataSet = new int[ setSize ];
			for( int j = 0; j < setSize; j++ )
			{
				dataSet[ i ] = rand()%1000;
			}
			
			// sorting and adding num comparisons done to overall average
			average += sorter->iSort( dataSet, setSize );
		}
		delete [] dataSet;

		// calculates average comparisons across 50 tests
		average = average / 50;

		// prints average comparisons to file
		insertOutput << setSize << " size set: " << average << endl;
		
		/*------------------------ INSERT TESTING FINISHED ------------------------*/
		

		/*--------------------------- QUICK SORT TESTING --------------------------*/

		average = 0;
		// loops through all 50 tests to be run per algorithm per set size
		for( int i = 0; i < 50; i++ ) {
			// creates and populates array of size setSize
			dataSet = new int[ setSize ];
			for( int j = 0; j < setSize; j++ )
			{
				dataSet[ i ] = rand()%1000;
			}
			
			// sorting and adding num comparisons done to overall avg
			average +=  sorter->mSort( dataSet, 0, setSize - 1 );
		}
		delete [] dataSet;

		// calculates average comparisons across 50 tests
		average = average / 50;

		// prints average comparisons to file
		quickOutput << setSize << " size set: " << average << endl;
	
		/*------------------------- QUICK TESTING FINISHED ------------------------*/


		delete sorter;
	}
}
