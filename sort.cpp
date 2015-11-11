/** Names: Patrick Stroud and Nathan Everritt
 *  Project 3 : Sorting
 *
 *  Purpose: The executable file. sort.cpp processes cmd line arguments containing
 *  one flag indicating the sorting method, followed by a set of
 *  integers to pass as input.
 */
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]){
	if( argc < 3 ) {
		cout << "usage: -sortingmethod [set of integers] (no brackets)" << endl;
	}
	
	// flag can be -i, -m, or -q
	if(strcmp(argv[1],"-i") == 0){
		cout << "isort" << endl;
	} else if (strcmp(argv[1],"-m") == 0){
		cout << "msort" << endl;
	} else if (strcmp(argv[1],"-q") == 0){
		cout << "qsort" << endl;
	}

	return 0;
}
