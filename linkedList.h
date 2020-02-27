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

// A LinkedList node for the nodes simaliar to the unique node
typedef struct bodyNode 
{
	bodyNode * top, // pointer to the node above the current bodyNode
		* bottom,	// pointer to the node below the current bodyNode
		* left,		// pointer to the left of the current bodyNode
		* right;	// pointer to the right of the current bodyNode

	int row,		// the row of current bodyNode
		col;		// the column of current bodyNode
} ;

// A LinkedList node for the 'master' / unique nodes
typedef struct headNode
{
	headNode * next;		// pointer to next headNode
	bodyNode * linkedPix;	// pointer to the head's bodynode
};


class linkedList
{
public:
	// linkedList : initalizes a linkedList
	// preconditions : none
	// postconditions : none
	linkedList();



	// newHeadNode : Creates a new headNode 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : none
	void newHeadNode(int row, int col);

	// newBodyNode : returns a new bodyNode 
	// preconditions : given in bounds, positive rows and columns
	// postconditions : that the bodyNode isn't automaticaly attached
	bodyNode newBodyNode(int row, int col);

	// linkedList : deletes a linkedList
	// preconditions : none
	// postconditions : none
	~linkedList();

private:
	headNode* masterList; // the "head of heads"
};

