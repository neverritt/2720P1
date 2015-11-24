/** Names: Patrick Stroud and Nathan Everritt
 *  Project 3
 *
 *  Purpose: sort.h describes the algorithms Insertion sort,
 *  Merge Sort, and Quick Sort.
 */

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class sort;

class sort{
public:

/**
 * Insertion Sort. Returns # of comparisons.
 *
 * @param array: array of data
 * @param length: length of array
 */
long iSort(int array[], int length){
	long compare = 0;
	for(int i = 1; i < length; i++){
		int key = array[i];
		// Insert array[i] into sorted sequence array[1..i-1]
		int j = i - 1; // tracks i - 1
		while((j >= 0) && (array[j] > key)){
			array[j+1] = array[j];
			j = j - 1;
			compare++;
		}
		if((j>=0) && (array[j] <= key)){
			compare++;
		}
		array[j+1] = key;
	}
	return compare;
}

/**
 * Merge Sort. Returns # of comparisons.
 *
 * @param array: array of data
 * @param first: first index of subarray
 * @param last: last index of subarray
 */
long mSort(int array[], int first, int last){
	long comparisons = 0;
	if(first < last){
		int middle = floor( ( first + last ) / 2 );
		comparisons += mSort( array, first, middle );
		comparisons += mSort( array, middle+1, last );
		comparisons += merge( array, first, middle, last );
	}	
	
	return comparisons;
}

long merge( int array[], int first, int middle, int last ){
	long comparisons = 0;			//tracks comparisons while merging
	int leftSize = middle - first + 1;	//num elements in left list
	int rightSize = last - middle;		//num elements in right list
	int * left;
	left  = new int[ leftSize ];		//allocates array for left list
	int * right;
	right = new int[ rightSize ];		//allocates array for right list

	// copies left elements of array to temp array
	for( int i = 0; i < leftSize; i++ ){
		left[ i ] = array[ first + i ];
	}

	// copies right elements of array to temp array
	for(int i = 0; i < rightSize; i++){
		right[ i ] = array[ middle + i ];
	}

	int j, k = 0;	// j and k track positions in right and left lists

	// loops from first to last in main array merging lists as it goes
	for( int i = first; i < last; i++ ){
		if(left[j] <= right[k]){
			array[i] = left[j];
			j = j + 1;
		} 
		else {
			array[i] = right[k];
			k = k + 1;
		}
		comparisons += 1;
	} 
	return comparisons;
}

/**
 * Quick Sort. Returns # of comparisons.
 *
 * @param array: array of data
 * @param length: length of array
 */
long qSort(int array[], int length){
	long compare = 0;

	return compare;
}

};
