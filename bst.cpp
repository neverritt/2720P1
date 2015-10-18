#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
	std::string line;
	std::string operation;
	std::string ins ("insert");	
	std::string del ("delete");
	bst* tree = new bst();

	ifstream file;
	file.open( argv[1] );
	if ( file.is_open() ) { 		  // if successful opening file
		while( !file.eof() ){ 		  // while file isn't empty
			int num;
			operation = "";
			getline( file,line ); 	  // gets the line as a string
			
			std::stringstream ss( line );
			ss >> operation >> num;   // split line into operation and num

			if( operation == "insert" ){
				tree->insert(num);
			}
			else if( operation == "delete" ){
				tree->deleteNode(num);
			}
		}


		file.close();
	}
	else { 
		cout << "Unable to open file" << endl;
		return 0;
	}
	
	cout << "Number of nodes in the bst: " << tree->size() << endl;
	tree->height();
	tree->preOrder();
	tree->inOrder();
	tree->postOrder();
	//cout << "Extra credit tree visualization: " << tree->visual() << endl;

	return 0;
}
