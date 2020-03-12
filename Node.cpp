//// linkedList.cpp
////
//// Author: Jaedan Parsons
////
//// This library provides the functionality to make a linkedList
//// of linked lists, specificaly designed to keep track of areas 
//// of pixels that are similar to each other. 
////
//
//#include "linkedList.h"
//
//
//linkedList::linkedList()
//{
//	//masterNode.next = nullptr;
//	//masterNode.linkedPix = nullptr;//= ;
//	//masterNode = newNode();
//}
//
//Node linkedList::newNode()
//{
//	Node newNode;
//	
//	newNode.ifHead = false;
//	newNode.next = nullptr; 
//	newNode.row = -1; //error; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!     couldn't set to NULL (shouldn't try setting it to nullptr)
//	newNode.col = -1;
//
//
//	return newNode;
//}
//
//// newHeadNode : Creates a new Node and sets the row and col to specified aria
//// preconditions : given in bounds, positive rows and columns
//// postconditions : none
//Node linkedList::newNode(int row, int col)
//{
//	Node nodeNew;
//
//	nodeNew.ifHead = false;
//	nodeNew.col = col;
//	nodeNew.row = row;
//	nodeNew.next = nullptr;
//
//	return nodeNew;
//
//
//	//// if 0
//	//if (masterNode.next == nullptr)
//	//{
//	//	//masterList = new headNode;
//	//	//masterList->next = nullptr;
//	//	masterNode.next = &newBodyNode(row, col);
//	//}
//	//
//	//// if 1 nodes
//	//else if (masterList->linkedPix == nullptr)
//	//{
//	//	masterList = new headNode;
//	//	masterList->next = nullptr;
//	//	*masterList->linkedPix = newBodyNode(row, col);
//	//}
//	//// if more then 1 node
//	//else
//	//{
//	// /*	headNode* lastHead = masterList->next;
//	//	while (lastHead->next != nullptr)
//	//		lastHead = lastHead->next;*/
//	//lastHead->next = new headNode;
//	//lastHead = lastHead->next;
//	//lastHead->next = nullptr;
//	////}
//}
//
//Node linkedList::newNode(int row, int col, bool ifHead)
//{
//	Node nodeNew;
//
//	nodeNew.ifHead = ifHead;
//	nodeNew.col = col;
//	nodeNew.row = row;
//	nodeNew.next = nullptr;
//
//	return nodeNew;
//}
//
//Node linkedList::insertNode(int row, int col, Node * nextNode)
//{
//	Node nodeNew;
//
//	nodeNew.ifHead = false;
//	nodeNew.col = col;
//	nodeNew.row = row;
//	nodeNew.next = nextNode;
//
//	return nodeNew;
//}
//
//Node linkedList::operator = (const Node& orign) const
//{
//	return orign;
//}
//
//Node linkedList::merge(Node* list)
//{
//
//	//return Node();
//}
//
//
//
//
//void makeHead(Node headNode)
//{
//	headNode.ifHead = true;
//}
//
//
//
//
////// cant be called for some reason		/**/
////bodyNode linkedList::newBodyNode(int row, int col) 
////{
////	bodyNode newNode;
////
////	newNode.top = nullptr;
////	newNode.bottom = nullptr;
////	newNode.left = nullptr;
////	newNode.right = nullptr;
////	newNode.row = row;
////	newNode.col = col;
////	//newNode.pix->blue = 0;
////	//newNode.pix->green = 0;
////	//newNode.pix->red = 0;
////
////	return newNode;
////}
//
//
//linkedList::~linkedList()
//{
//}


// linkedList.cpp
//
// Author: Jaedan Parsons
//
// This library provides the functionality to make a linkedList
// of linked lists, specificaly designed to keep track of areas 
// of pixels that are similar to each other. 
//

#include "Node.h"
#include <cstddef>

														// NEED DEFINITIONS for the functions (also check the requierments for any missing functions) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// constructor
Node::Node()
{
	Node newNode;

	newNode.ifHead = false;
	newNode.next = nullptr;
	newNode.row = NULL; //error; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!     couldn't set to NULL (shouldn't try setting it to nullptr)
	newNode.col = NULL;


}

// copy constructor
Node::Node(/*const*/ Node* old)
{
	Node* nextNode,
		*prevNext = nullptr;
	
	while (prevNext != old)
	{
		nextNode = old;

		while (nextNode->next == nullptr && nextNode->next != prevNext)
		{
			nextNode = nextNode->next;
		}

		this->row = nextNode->row;
		this->col = nextNode->col;
		this->ifHead = nextNode->ifHead;
		this->next = nextNode->next;

		prevNext = nextNode;
	}
		

	

	// need to call for this.next
	//this->next(old->next);
}


//Node Node::newNode()
//{
//	Node newNode;
//
//	newNode.ifHead = false;
//	newNode.next = nullptr;
//	newNode.row = -1; //error; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!     couldn't set to NULL (shouldn't try setting it to nullptr)
//	newNode.col = -1;
//
//
//	return newNode;
//}

// newHeadNode : Creates a new Node and sets the row and col to specified aria
// preconditions : given in bounds, positive rows and columns
// postconditions : none
Node::Node(int row, int col)
{
	this->ifHead = false;
	this->col = col;
	this->row = row;
	this->next = nullptr;
}

Node::Node(int row, int col, bool ifHead)
{
	this->ifHead = ifHead;
	this->col = col;
	this->row = row;
	this->next = nullptr;
}


Node::Node(int row, int col, Node* nextNode) // calling this function !!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	this->ifHead = false;
	this->col = col;
	this->row = row;
	this->next = nextNode;
}


Node::Node(const Node* nextNode, Node * nextPtr)
{
	this->ifHead = nextNode->ifHead;
	this->col = nextNode->col;
	this->row = nextNode->row;
	this->next = nextPtr;
}





//Node Node::operator = (const Node& orign) // for Nodes
//{
//
//
//
//	//if (&orign != nullptr)
//	//{
//	//	// get to last node of orign
//	//	const Node* last = &orign,
//	//		* prevLast = nullptr;
//
//	//	do
//	//	{
//	//		// loops through to the last element in the list
//	//		while (last != nullptr && last->next != nullptr && last->next == prevLast)
//	//			last = last->next;
//
//	//		//copy it and have this point to it
//	//		this->next = &Node(last, this->next);
//
//	//		prevLast = last;
//
//	//	} while (prevLast != &orign);
//
//	//	// repeat
//
//	//	return this;
//
//	//	//if (orign.next == nullptr)
//	////	return orign;
//
//
//	////else
//	////	
//	////	
//
//	////last = &Node(orign);
//	////	
//	////	orign->next = nxtNode->next;
//
//	////nxtNode = nxtNode->next;
//	////orign = orign->next;
//
//
//	//	// this if is done to check if there is only one node in the list and to not try checking nullptrs 'next'
//	//		//if(list->next != nullptr)
//	//			//list = list->next;
//
//	//}
//
//	//else
//	//	return orign;
//	
//}



// for pointers
//Node * Node::operator = (Node * orign) // would li
//{
//	return orign;
//}

// needs to be recusive
//Node Node::operator += (const Node& orign)
void Node::addPixel(Node& orign, Node* currentNode)
{
	if (&orign != nullptr)
	{
		// get to last node of orign
		Node* last = &orign,
			* prevLast = nullptr;

		do
		{
			// loops through to the last element in the list
			while (last != nullptr && last->next != nullptr && last->next == prevLast)
				last = last->next;

			//copy it and have this point to it
			currentNode->next = last;
			

			prevLast = last;

		} while (prevLast != &orign);// repeat

		

		//return *this;


		// this if is done to check if there is only one node in the list and to not try checking nullptrs 'next'
			//if(list->next != nullptr)
				//list = list->next;

	}

	//else
		//return orign;
	

	//												original 
	/*const Node* last = this;

	while (last->next != nullptr)
		last = last->next;

	last = &Node(orign);
	return *this;*/
}




// precondition : that there is at least 1 node in the list
// postcondition : that 
void Node::merge(Node* list)
{
	Node* nxtNode = this;

	do
	{
		if (this == nullptr)
			*this = nxtNode;

		else
			list->next = nxtNode->next;
		
		nxtNode = nxtNode->next;
		list = list->next;

	// this if is done to check if there is only one node in the list and to not try checking nullptrs 'next'
		//if(list->next != nullptr)
			//list = list->next;
	} while (nxtNode->next != nullptr);
}




void makeHead(Node headNode)
{
	headNode.ifHead = true;
}




//// cant be called for some reason		/**/
//bodyNode Node::newBodyNode(int row, int col) 
//{
//	bodyNode newNode;
//
//	newNode.top = nullptr;
//	newNode.bottom = nullptr;
//	newNode.left = nullptr;
//	newNode.right = nullptr;
//	newNode.row = row;
//	newNode.col = col;
//	//newNode.pix->blue = 0;
//	//newNode.pix->green = 0;
//	//newNode.pix->red = 0;
//
//	return newNode;
//}


Node::~Node()
{
}
