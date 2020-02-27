// linkedList.cpp
//
// Author: Jaedan Parsons
//
// This library provides the functionality to make a linkedList
// of linked lists, specificaly designed to keep track of areas 
// of pixels that are similar to each other. 
//

#include "linkedList.h"


linkedList::linkedList()
{
	masterList->next = nullptr;
	masterList->linkedPix = nullptr;
}

// newHeadNode : Creates a new headNode 
// preconditions : given in bounds, positive rows and columns
// postconditions : none
void linkedList::newHeadNode(int row, int col)
{
	// if 0
	if (masterList->linkedPix == nullptr)
	{
		//masterList = new headNode;
		//masterList->next = nullptr;
		masterList->linkedPix = &newBodyNode(row, col);
	}

	
	// if 1 nodes
	else if (masterList->linkedPix == nullptr)
	{
		masterList = new headNode;
		masterList->next = nullptr;
		*masterList->linkedPix = newBodyNode(row, col);
	}

	// if more then 1 node
	else
	{
		headNode* lastHead = masterList->next;
		while (lastHead->next != nullptr)
			lastHead = lastHead->next;
		
		lastHead->next = new headNode;
		lastHead = lastHead->next;
		lastHead->next = nullptr;
		
	}
}


// cant be called for some reason		/**/
bodyNode linkedList::newBodyNode(int row, int col) 
{
	bodyNode newNode;

	newNode.top = nullptr;
	newNode.bottom = nullptr;
	newNode.left = nullptr;
	newNode.right = nullptr;
	newNode.row = row;
	newNode.col = col;
	//newNode.pix->blue = 0;
	//newNode.pix->green = 0;
	//newNode.pix->red = 0;

	return newNode;
}


linkedList::~linkedList()
{
}
