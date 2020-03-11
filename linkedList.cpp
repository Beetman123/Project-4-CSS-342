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

#include "linkedList.h"
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
Node::Node(const Node* old)
{
	this->row = old->row;
	this->col = old->col;
	this->ifHead = old->ifHead;
	this->next = old->next;
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

Node::Node(int row, int col, Node* nextNode)
{
	this->ifHead = false;
	this->col = col;
	this->row = row;
	this->next = nextNode;
}

Node Node::operator = (const Node& orign) const
{
	return orign;
}

void Node::merge(Node* list)
{
	Node* nxtNode = list;

	do
	{
		this->next = &Node(nxtNode); 

	// this if is done to check if there is only one node in the list and to not try checking nullptrs 'next'
		if(nxtNode->next != nullptr) 
			nxtNode = nxtNode->next;
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
