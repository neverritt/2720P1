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
	long compare = 0;
	if(first < last){
		int middle = floor((first+last)/2);
		compare += mSort(array, first, middle);
		compare += mSort(array, middle+1, last);
		merge(array, first, middle, last);
	}	
	
	return compare;
}

void merge(int array[], int first, int middle, int last){
	int leftMax = middle - first + 1;
	int rightMax = last - middle;
	int * left = new int[leftMax];
	int * right = new int[rightMax];
	for(int i = 0; i < leftMax; i++){
		left[i] = array[i+first];
	}
	for(int i = 0; i < rightMax; i++){
		right[i] = array[i+middle];
	}
	int j, k = 0;
	for(int i = first; i < last; i++){
		if(left[j] <= right[k]){
			array[i] = left[j];
			j = j + 1;
		} else {
			array[i] = right[k];
			k = k + 1;
		}
	} 
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
