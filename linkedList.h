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

// A LinkedList Node for the 'master' / unique nodes
typedef struct Node
{
	Node * next;		// pointer to next node
	//bodyNode */**/ linkedPix;	// pointer to the head's bodynode

	int row,		// the row of current Node
		col;		// the column of current Node

	bool ifHead;
};


class linkedList
{
public:
	// linkedList : initalizes a linkedList
	// preconditions : none
	// postconditions : none
	linkedList();


	Node newNode();

	// newNode : Creates a new Node 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : none
	Node newNode(int row, int col);

	Node newNode(int row, int col, bool ifHead);

	Node insertNode(int row, int col, Node * nextNode);


	// newBodyNode : returns a new bodyNode 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : that the bodyNode isn't automaticaly attached
	//bodyNode newBodyNode(int row, int col);

	// linkedList : deletes a linkedList
	// preconditions : none
	// postconditions : none
	~linkedList();

private:
	//Node masterNode;
	//node* masterList; // the "head of heads"
};

