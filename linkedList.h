// linkedList.h
//
// Author: Jaedan Parsons
//
// This library provides the functionality to make a linkedList
// of linked lists, specificaly designed to keep track of areas 
// of pixels that are similar to each other. 
//


#pragma once

//#include <iostream>



// cant include Image.h, cant use pixel at all
// cant be able to access pixels

// A LinkedList Node for the nodes simaliar to the unique node
//typedef struct bodyNode  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!!!!!!!!!!!!!!!!! Dont need top bottom left right (probably dont need bodynode)
//{
//	bodyNode * top, // pointer to the Node above the current bodyNode
//		* bottom,	// pointer to the Node below the current bodyNode
//		* left,		// pointer to the left of the current bodyNode
//		* right;	// pointer to the right of the current bodyNode
//
//	
//} ;

// constructor, copy constructor, operator=, destructor, addPixel, and merge(see below.) You can implement other member functions(including sizeand averageColor), if desired.

// A LinkedList Node for the 'master' / unique nodes

class Node
{
public:
	// linkedList : initalizes a linkedList
	// preconditions : none
	// postconditions : none
	Node();

	// need a description for copy constructor !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Node(/*const*/ Node * old); // for some reason the const affects the program !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// but I need the const for the copy constructor right?

	//Node newNode();

	// Node : Creates a new Node 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : new Node is returned
	Node(int row, int col);

	// Node : Creates a new Node 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : new Node is returned
	Node(int row, int col, bool ifHead);

	// Node : Creates a new Node 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : new Node is returned with its next pointing to nextNode
	Node(int row, int col, Node* nextNode);

	// Node : Creates a new Node 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : new Node is returned
	Node(const Node* nextNode, Node* nextPtr);



	//Node operator = (const Node& orign);

	/*Node * operator = (Node* orign);*/

	Node addPixel (const Node& orign);


	void merge(Node* list);

	// newBodyNode : returns a new bodyNode 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : that the bodyNode isn't automaticaly attached
	//bodyNode newBodyNode(int row, int col);

	// linkedList : deletes a linkedList
	// preconditions : none
	// postconditions : none
	~Node();
	

	Node * next;		// pointer to next node
	//bodyNode */**/ linkedPix;	// pointer to the head's bodynode

	int row,		// the row of current Node
		col;		// the column of current Node

	bool ifHead;

private:
	//Node masterNode;
	//node* masterList; // the "head of heads"
};



//// A LinkedList Node for the 'master' / unique nodes
//typedef struct Node
//{
//	Node * next;		// pointer to next node
//	//bodyNode */**/ linkedPix;	// pointer to the head's bodynode
//
//	int row,		// the row of current Node
//		col;		// the column of current Node
//
//	bool ifHead;
//};
//
//
//class linkedList
//{
//public:
//	// linkedList : initalizes a linkedList
//	// preconditions : none
//	// postconditions : none
//	linkedList();
//
//	// need a copy constructor !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//	Node a(const Node oldNode);
//
//
//	Node newNode();
//
//	// newNode : Creates a new Node 
//	// preconditions : given in bounds, positive rows and columns
//	// postconditions : none
//	Node newNode(int row, int col);
//
//	Node newNode(int row, int col, bool ifHead);
//
//	Node insertNode(int row, int col, Node * nextNode);
//
//	Node operator = (const Node & orign) const;
//
//
//	Node merge(Node* list);
//
//	// newBodyNode : returns a new bodyNode 
//	// preconditions : given in bounds, positive rows and columns
//	// postconditions : that the bodyNode isn't automaticaly attached
//	//bodyNode newBodyNode(int row, int col);
//
//	// linkedList : deletes a linkedList
//	// preconditions : none
//	// postconditions : none
//	~linkedList();
//
//private:
//	//Node masterNode;
//	//node* masterList; // the "head of heads"
//};

