#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class bst;

/**
 * Node class in tree
 */
class Node {
	friend class bst;
	int key;
	Node * left = nullptr;
	Node * right = nullptr;
	Node * p = nullptr;
}; // Node 
/**
 * Binary Tree Class
 */
class bst {
public:
	Node * root = nullptr;
	int height = 0;
	int numNodes = 0;

/**
 * Searches for a key in the tree
 */
bool search( Node* node, int data ) {
	if( node == nullptr ){
		return 1;
	}
	if( node->key == data ){
		return 0;
	}
	if( data < node->key ){
		return search( node->left, data );
	}
	else {
		return search( node->right, data);
	}
}

/**
 * inserts node into proper spot in tree
 *
 * @param data - integer to be held in node
 */
void insert( int data ) {
	// Search for existing data
	Node* tmp = root;
	if(search(tmp, data) == 1){
	
	// creates node to insert
	Node* newNode = new Node();
	
	newNode->key = data;
	
	// Finding spot for node
	Node * parentPtr = nullptr;	// points to parent of node
	Node * nodePtr = root;		// points where to insert node
	while( nodePtr != nullptr ) {
	
		parentPtr = nodePtr;

		if( newNode->key < nodePtr->key ) {
			nodePtr = nodePtr->left;  // iterates ptr
		}
		else {
			nodePtr = nodePtr->right;  // iterates ptr
		}
	}
	
	newNode->p = parentPtr;  // sets nodes parent

	// either sets ptr as root if tree empty or sets node as child of parent
	if( parentPtr == nullptr )
		root = newNode;
	else if( newNode->key < parentPtr->key )
		parentPtr->left = newNode;
	else
		parentPtr->right = newNode;

	numNodes++;
	}
} // Insert Method

/**
 * Prints Pre-Order Traversal of BST Object
 */
void preOrder (){
	cout << "Pre-order traversal: " << endl;
	Node * nodePtr = root;
	preOrderPrint( nodePtr );
	cout << endl;
} 
/**
 * Prints subtree rooted at node in Pre-Order Traversal
 *
 * @param node - Node that it will recursively sart printing from
 */
void preOrderPrint ( Node* node ) {
	if( node != nullptr ) {
		cout << node->key << " ";
		
		preOrderPrint( node->left );

		preOrderPrint( node->right );
	}
	
//	if( node->key == treeMaximum() )
//		cout << endl;
} // Pre-Order Print

/**
 * Prints In-Order Traversal of BST Object
 */
void inOrder (){
	cout << "In-order traversal: " << endl;
	Node * nodePtr = root;
	inOrderPrint( nodePtr );
	cout << endl;
}

/** 
 * Prints subtree rooted at node in In-Order Traversal
 *
 * @param node - Node that it will recursively start printing from
 */
void inOrderPrint( Node* node ) {
	if( node != nullptr ){
		inOrderPrint( node->left );
		cout << node->key << " ";
		inOrderPrint( node->right );
	}
}

/**
 * Prints Post-Order Traversal of BST Object
 */
void postOrder (){
	cout << "Post-order traversal: " << endl;
	Node * nodePtr = root;
	postOrderPrint( nodePtr );
	cout << endl;
}

/** 
 * Prints subtree rooted at node in Post-Order Traversal
 *
 * @param node - Node that it will recursively start printing from
 */
void postOrderPrint( Node* node ) {
	if( node != nullptr ){
		postOrderPrint( node->left );
		postOrderPrint( node->right );
		cout << node->key << " ";
	}
}


/**
 * Finds maximum of tree
 */
int treeMaximum( Node* node ) {
	if( node != nullptr ){
		while( node->right != nullptr ) {
			node = node->right;
		}
	}

	return node->key;
}

/**
 * Finds minimum of tree
 */
int treeMinimum( Node* node ) {
	if ( node != nullptr ){
		while( node->left != nullptr ) {
			node = node->left;
		}
	}
	return node->key;
}

/**
 * Replaces a subtree with another
 *
 * @param old - root node of old subtree
 * @param node - root node of subtree to be transplanted
 */
void transplant( Node* old, Node* node ){
	// if node is root, node is now root
	if( old->p == nullptr ){
		root = node;
	}
	// Assign node to the left or right child of old's parent
	else if ( old == (old->p)->left ){
		(old->p)->left = node;
	}
	else {
		(old->p)->right = node;
	}
	// Assign old's parent as node's parent
	if( node != nullptr ){
		node->p = old->p;
	}
}

/**
 * Deletes a node from the tree. Transplants the successor
 * or the left child.
 *
 * @param data - data of node to be deleted
 */
void deleteNode( int data ){
	// must check if node exists by its key
	// traversing tree using node	
	Node* node = root;
	int finish = 0;
	while( finish != 1 ){
		if( node == nullptr ){ // Node was not found. Finish
			finish = 1;
		} // Deleting the found node
		else if( node->key == data ){
			// Transplant left child if no right child
			if ( node->right == nullptr ){
					transplant( node, node->left );
			}
		
			// Transplant successor if right child exists
			else {
				Node* successorNode = node->right;
				// Assigning successorNode to minimum of right child subtree
				while( successorNode->left != nullptr ) {
					successorNode = successorNode->left;
				}	
				// if successorNode's parent is not the deleted node,
				// transplant successor's right child to successor
				if( successorNode->p != node ){
					//if( successorNode->right != nullptr ){
						transplant( successorNode, successorNode->right );
						successorNode->right = node->right;
						(successorNode->right)->p = successorNode;
					//}
				}
				transplant( node, successorNode );
				// Assign the deleted node's left child to successor
				successorNode->left = node->left;
				if( successorNode->left != nullptr ){
					(successorNode->left)->p = successorNode;
				}				
			}
			numNodes--;
			finish = 1;
		} // traversing
		else if( data < node->key ){
			node = node->left;
		}
		else if( data > node->key ) {
			node = node->right;
		}
	}

}
/**
 * returns the number of nodes ( including given node ) in the bst rooted at node
 */
int subSize( Node* node ){
	int num = 0;
	if ( node != nullptr ){
		num++;
		num = num + subSize( node->left );
		num = num + subSize( node->right );
	}
	return num;
}

/**
 * Prints Height of BST Object
 */
void treeHeight() {
	cout << "Height of the bst: ";
	Node* nodePtr = root;
	cout << getHeight( nodePtr );
	cout << endl;
}

/**
 * finds the height of the subtree rooted at node
 *
 * @param node - the node which will serve as root of subtree
 */
int getHeight( Node* node ) {
	int height = 0;
	int L_Height = 0;
	int R_Height = 0;

	if( node == nullptr ) { // if nil
		return -1;
	}
	if( node->left == nullptr && node->right == nullptr ){ // if leaf ( base case )
		return 0;
	}
	else { // if has children
		L_Height = getHeight( node->left );
		R_Height = getHeight( node->right );
	}


	if( L_Height > R_Height )
		height = L_Height;
	else
		height = R_Height;
	
	height++;

	return height;
}

/**
 * Prints visualization of the tree
 */
void visualTree(){
	Node * nodePtr = root;
	int height = getHeight( nodePtr );
	// widest level = 2^height nodes (maximum)
	// width is space before number is inserted
	int width = pow(2.0, height);

	// holds each level of tree as string with [0] being root level
	vector<string> treeArray ( height + 1, " " );

	// calls the recursive method to fill out string array representation of bst
	treeArray = populateTreeArray( nodePtr, treeArray, width, 0 );

	// prints out each level of the string array, making the tree level by level
	for( int i = 0; i < treeArray.size(); i++ ) {
		cout << treeArray[i] << endl;
	}
	
}

/**
 * recursively adds nodes in tree to treeArray with proper spacing
 *
 * @param nodePtr - node to iterate from
 * @param tree - vector of strings that represents the bst where each string is a certain level of the bst
 * @param spacing - how much space should be between the numbers on that level of the tree
 * @param treeLevel - tracks what level of the bst that the current node is on
 */
vector<string> populateTreeArray( Node* nodePtr, vector<string> tree, int spacing, int treeLevel ) {

	if( nodePtr == nullptr ) {
		if( treeLevel < tree.size() ) { // if below leaf but still not below lowest node
			string padding(spacing, ' ');
			// adding padding twice for space before and after missing node
			tree[treeLevel] += padding;
			tree[treeLevel] += padding;
		}
		return tree;
	}

	// padding is a string containing spaces of some length
	string padding(spacing, ' ');
	// adds spacing before, number, then spacing after to a temporary string
	string newString = padding;
	newString += to_string(nodePtr->key);
	newString += padding;
	// adds temp string to existing string on that level of the tree
	tree[treeLevel] += newString; 

	spacing = spacing/2; // adjusts sapcing for next level of tree
	treeLevel++;	

	tree = populateTreeArray( nodePtr->left, tree, spacing, treeLevel );
	tree = populateTreeArray( nodePtr->right, tree, spacing, treeLevel );

	return tree;
}

/**
 * Return size of bst
 */
int size() {
	return numNodes;
}

}; 
