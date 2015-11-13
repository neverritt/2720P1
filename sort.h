/** Names: Patrick Stroud and Nathan Everritt
 *  Project 3
 *
 *  Purpose: sort.h describes the algorithms Insertion sort,
 *  Merge Sort, and Quick Sort.
 */

#include <iostream>
#include <stdlib.h>

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
int iSort(int array[], int length){
	int compare = 0;
	for(int i = 1; i < length; i++){
		int key = array[i];
		// Insert array[i] into sorted sequence array[1..i-1]
		int j = i - 1; // tracks i - 1
		while((j >= 0) && (array[j] > key)){
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
	return compare;
}

/**
 * Merge Sort. Returns # of comparisons.
 *
 * @param array: array of data
 * @param length: length of array
 */
int mSort(int array[], int length){
	int compare = 0;
	
	return compare;
}

/**
 * Quick Sort. Returns # of comparisons.
 *
 * @param array: array of data
 * @param length: length of array
 */
int qSort(int array[], int length){
	int compare = 0;

	return compare;
}

};
