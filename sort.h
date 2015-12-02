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

private:

long comparisons = 0;

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
	left  = new (nothrow) int[ leftSize ];		//allocates array for left list

	int * right;
	right = new (nothrow) int[ rightSize ];		//allocates array for right list

	// makes sure space was allocated for arrays
	if( right == nullptr || left == nullptr ) {
		cout << "Error: could not allocate memory for dynamic arrays";
		return 0;
	}

	// copies left elements of array to temp array
	for( int i = 0; i < leftSize; i++ ){
		left[ i ] = array[ first + i ];
	}

	// copies right elements of array to temp array
	for(int i = 0; i < rightSize; i++){
		right[ i ] = array[ middle + i + 1 ];
	}

	int i = 0;  // tracks position in left list
	int j = 0;  // tracks position in right list
	int k = first;  // tracks position in main array
	while( i < leftSize && j < rightSize ){
		if( left[ i ] < right[ j ] ){
			array[ k ] = left[ i ];
			i = i + 1;
		}
		else{
			array[ k ] = right[ j ];
			j = j + 1;
		}
		k += 1;
		comparisons = comparisons + 1;
	}

	// if right completes before left this will add rest of left list to array
	while( i < leftSize ) {
		array[ k ] = left[ i ];
		i = i + 1;
		k = k + 1;
	}

	// if left completes before right, this will add rest of right list to array
	while( j < rightSize ) {
		array[ k ] = right[ j ];
		k = k + 1;
		j = j + 1;
	}
	delete[] left;
	delete[] right;
	return comparisons;
}

/**
 * Quick Sort. Returns # of comparisons.
 *
 * @param array: array of data
 * @param first: first index of subarray
 * @param last: last index of subarray
 */
long qSort(int array[], int first, int last){
	long compare = comparisons;
	comparisons = 0;
	if(first < last){
		int pivot = partition(array, first, last);
		compare += qSort(array, first, pivot - 1);
		compare += qSort(array, pivot + 1, last);			
	}
	comparisons = 0;
	return compare;
}
/**
 * Partitions array for quick sort. Returns the pivot index
 *
 * @param array: array of data
 * @param first: first index of subarray
 * @param last: last index of subarray
 */
int partition(int array[], int first, int last){
	int pivot = array[first];

	do{
		while((first < last) && (array[last] >= pivot)){
			last--;
			comparisons++;
		}
		if(first < last){
			// swaps # smaller than pivot
			array[first] = array[last];
			// look for # larger than pivot
			while((first < last) && (array[first] <= pivot)){
				first++;
				comparisons++;
			}
			// moving to position
			if(first < last){
				array[last] = array[first];
			}	
		}

	} while(first < last);	

	// move pivot
	array[first] = pivot;	
	
	return first;
}

};
