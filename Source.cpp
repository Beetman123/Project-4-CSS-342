// Jaedan Parsons
// program description (get from assignment)

//#include "Image.h"

//#include "linkedList.h" // ? // I don't need linkedList class I only need a node ion the Image class

#include "Image.h"
#include "linkedList.h"

using namespace std;

// Function Declarations

// spread : makes a bodyNode linkedList of all the objects that are  
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
void spread(const bodyNode& newHead, bodyNode& currentNode, const Image& oldPicture, Image& newPicture);

// ifNotTaken : checks if the image at a certian pixel is black or white
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
bool ifNotTaken();

// recursiveColorChange : changes the number of green color tone
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
void recursiveColorChange(const bodyNode* head, bodyNode* current, const Image& oldPicture, Image& newPicture);



int main() // have to use recursion and the up down left right
{
	Image picture,
		newPicture;

	headNode masterList,
		* currentMstr;

	// initialize variables
	//masterList.linkedPix = nullptr;
	
	bool addedToList = false;

	// read in picture
	picture.readImage("test4.gif");
	
	// make new "blank" picture (black) of same size
	newPicture.createImage(picture.getrows(), picture.getcols()); 

	// First loops mission:
	// looping through picture to make all the linked lists
	
	// loop through picture 
	// going through row by row 
			// check if the pixel is part of a linked list (already connected to a 'master' node)
				// if not then make it a master node and have that node "virus spread" through the entire picture
				// when making the node make the output version white (inorder to verify that it is part of a linkedlist)

	/*
	useful functions:
	
	// check if the colors are close enough
	picture.ifSimilarColor(int rowOrign, int colOrign, int rowNxt, int colNxt, int alowedDifference);
	


	*/
	

	for (int row = 0; row < picture.getrows(); row++)
	{
		for (int col = 0; col < picture.getcols(); col++)
		{
			//// if the pixel isn't part of a linked list = (black >>> newpicture)
			//if (newPicture.colorBlue(row, col) == 0 &&
			//	newPicture.colorRed(row, col) == 0 &&
			//	newPicture.colorGreen(row, col) == 0)
			//{
			//	// make the pixel the head of a NEW linked list
			//			// also: make it turn black
			//}

			//addedToList = false;

			//while (/*currentMstr ||*/ currentMstr->next == nullptr || addedToList == true)
			//{
			//	// if there are no masterNodes
			//	if (masterList.linkedPix == nullptr)
			//	{
			//		// create the first masterNode
			//		//masterList.linkedPix.newBodyNode(row, col);
			//		masterList.linkedPix = & /*linkedPix-> (?)*/newBodyNode(row, col);
			//		
			//	}
			//	// check if current pixel is similar to 
			//	if (picture.ifSimilarColor(masterrow, mastercol, row, col, 100))
			//	{
			//		// add it to the linked list
			//	}
			//	else if (cur)
			//	{
			//	}
			//	
			//	//get next
			//	currentMstr = currentMstr->next;
			//}

			// if not taken then create a new master node
			if (ifNotTaken())
			{
				// if there are no masterNodes
				if (masterList.linkedPix == nullptr)
				{
					// create the first masterNode
					//masterList.linkedPix.newBodyNode(row, col);
					masterList.linkedPix = & /*linkedPix-> (?)*/newBodyNode(row, col);
					currentMstr = &masterList;

					// get all the nodes that are similar
					spread(masterList.linkedPix, masterList.linkedPix, picture, newPicture);
				}

				// if there are then
				else
				{
					currentMstr->next = newHeadNode(row, col);
					currentMstr = currentMstr->next;

					// get all the nodes that are similar
					spread(currentMstr.linkedPix, currentMstr.linkedPix, picture, newPicture);
				}
			}
		}
	}


	// Second loops mission:
	// to color the new image
	
	//for (int row = 0; row < picture.getrows(); row++)
	//{
	//	for (int col = 0; col < picture.getcols(); col++)
	//	{
	//		// if i
	//		//if (picture. )
	//	}
	//}

	currentMstr = &masterList; // this is how it works

	while (currentMstr->next != nullptr)
	{
		// call the recursive function with the head body node as a paramater
		recursiveColorChange(currentMstr->linkedPix, currentMstr->linkedPix, picture, newPicture);
	}

	
	// to look at the image at different parts of the the code process use the 
	picture.saveImage("filename.gif");

	system("pause");
	return 0;
}

// spread : makes a bodyNode linkedList of all the objects that are  
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
void spread(const bodyNode & newHead, bodyNode & currentNode, const Image & oldPicture, Image & newPicture)
{
	// change color of new image at current postion to whatever a wanabia ?
	// to black
	newPicture.changeBlue(currentNode.row, currentNode.col, 255); // is this supposed to be 255 or 0 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	newPicture.changeGreen(currentNode.row, currentNode.col, 255);
	newPicture.changeRed(currentNode.row, currentNode.col, 255);
	
	
	// recursively call for the top, left right and bottom

	// top
	if (currentNode.row - 1 >= 0 && ifNotTaken() && 
		oldPicture.ifSimilarColor(newHead.row, newHead.col, currentNode.row - 1, currentNode.col, 100))
	{
		// create new bodyNode
		currentNode->top = newBodyNode(currentNode.row - 1, currentNode.col);

		// call spread for that node
		spread(newHead, currentNode->top, oldPicture, newPicture);
	}

	// bottom
	if (currentNode.row + 1 < oldPicture.getrows() && ifNotTaken() && 
		oldPicture.ifSimilarColor(newHead.row, newHead.col, currentNode.row + 1, currentNode.col, 100))
	{
		// create new bodyNode
		currentNode->bottom = newBodyNode(currentNode.row + 1, currentNode.col);

		// call spread for that node
		spread(newHead, currentNode->bottom, oldPicture, newPicture);
	}

	// left
	if (currentNode.col - 1  >= 0 && ifNotTaken() && 
		oldPicture.ifSimilarColor(newHead.row, newHead.col, currentNode.row, currentNode.col - 1, 100))
	{
		// create new bodyNode
		currentNode->left = newBodyNode(currentNode.row, currentNode.col - 1);

		// call spread for that node
		spread(newHead, currentNode->left, oldPicture, newPicture);
	}

	// Right
	if (currentNode.col + 1 < oldPicture.getcols() && ifNotTaken() && 
		oldPicture.ifSimilarColor(newHead.row, newHead.col, currentNode.row, currentNode.col + 1, 100))
	{
		// create new bodyNode
		currentNode->right = newBodyNode(currentNode.row, currentNode.col + 1);

		// call spread for that node
		spread(newHead, currentNode->right, oldPicture, newPicture);
	}
}

// ifNotTaken : checks if the image at a certian pixel is black or white
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
bool ifNotTaken()
{
	

	return true;
}


// recursiveColorChange : changes the number of green color tone
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
void recursiveColorChange(const bodyNode * head, bodyNode * current, const Image & oldPicture, Image & newPicture)
{
	// if it isn't the first time that this is called 
	if (head != current)
	{
		// change the color of the current node
		newPicture.changeBlue(current->row, current->col, oldPicture.colorBlue(head->row, head->col));
		newPicture.changeGreen(current->row, current->col, oldPicture.colorGreen(head->row, head->col));
		newPicture.changeRed(current->row, current->col, oldPicture.colorRed(head->row, head->col));
	}

	// recursively call for the top, left right and bottom
	if (current->top != nullptr)
	{
		recursiveColorChange(head, current->top, oldPicture, newPicture);
	}

	if (current->bottom != nullptr)
	{
		recursiveColorChange(head, current->bottom, oldPicture, newPicture);
	}

	if (current->left != nullptr)
	{
		recursiveColorChange(head, current->left, oldPicture, newPicture);
	}

	if (current->right != nullptr)
	{
		recursiveColorChange(head, current->right, oldPicture, newPicture);
	}
}


// make a linked list of the head nodes so that when you want to call them to print you can call it without knowing how many there are