// Jaedan Parsons
// program description (get from assignment)

//#include "Image.h"

//#include "linkedList.h" // ? // I don't need linkedList class I only need a Node ion the Image class

#include "Image.h"
#include "linkedList.h"

using namespace std;

// Function Declarations

// spread : makes a Node linkedList of all the objects that are  
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture

// void spread(Node & newHead, Node & list, const Image& oldPicture, Image& newPicture, linkedList linklst, int allowedDif);
Node * spread(Node& seed, Node& list, const Image& oldPicture, Image& newPicture, int allowedDif);

// Done

// ifNotTaken : checks if the image at a certian pixel is black or white
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
bool ifNotTaken(const Image& picture, int row, int col);

void averageColor(Node head, Image picture, Image newPicture);

// recursiveColorChange : changes the number of green color tone
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
void recursiveColorChange(const Node * head, Node * current, Image& newPicture);



int main() // have to use recursion and the up down left right
{
	// Initialize variables

	Image picture, // inputed picture
		newPicture; // picture but changed				

	//linkedList picList;  // used to call linkedList functions

	Node * list = nullptr, // head of entire list of nodes  error given is that list is uninialized
		* listBack = nullptr, // pointer to the end of the list											 ?!!
		* current = nullptr;

	const int allowedDifInPixels = 100;
	int numberOfSeedPixels = 0;


	//masterList.next = nullptr;

	// read in picture
	picture.readImage("test4.gif"); 
	
	// make new "blank" picture (black) of same size
	newPicture.createImage(picture.getrows(), picture.getcols());			// it starts as all black  // works!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// TESTING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//newPicture.saveImage("newPictureBefore.gif");

	// First loops mission:
	// looping through picture to make all the linked lists
	
	// loop through picture 
	// going through row by row 
			// check if the pixel is part of a linked list (already connected to a 'master' node)
				// if not then make it a master Node and have that Node "virus spread" through the entire picture
				// when making the Node make the output version white (inorder to verify that it is part of a linkedlist)

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

			//while (/*list ||*/ list->next == nullptr || addedToList == true)
			//{
			//	// if there are no masterNodes
			//	if (masterList.next == nullptr)
			//	{
			//		// create the first masterNode
			//		//masterList.next.newBodyNode(row, col);
			//		masterList.next = & /*next-> (?)*/newBodyNode(row, col);
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
			//	list = list->next;
			//}

			// if not taken then create a new master node
			if (ifNotTaken(newPicture, row, col))
			{
				cout << "numberOfSeedPixels = " << ++numberOfSeedPixels << "   ";

				// Make the list for the seed
				
				//Node * newList = spread(*listBack, *listBack, picture, newPicture, allowedDifInPixels); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				Node* newList = &Node(row, col, true);
				//Node * firstNode = &Node(row, col, true);

				//newList = spread(*newList, *newList, picture, newPicture, allowedDifInPixels);
				newList->addPixel(spread(*newList, *newList, picture, newPicture, allowedDifInPixels));


				 //spread isn't working !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				 //	 spread isn't returning what it is supposed to

				// then merge it to the existing list 
				newList->merge(list);

				// then delete the newList
				
				// do I need to do this ????											// Question !!!



				// use if need be ---------------------------------------------------------------------------------------------------------------------

				// WHat NEEDS TO HAPPEN IS THAT THIS IS PART OF MERGE AND MERGE IS SUPPOSED TO COME AFTER SPREAD
				// if list.next doesn't have 
				if (list == nullptr)
				{
					list = &Node(row, col, true);
					listBack = list;
					//listBack->next = nullptr; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				}

				else
				{
					listBack->next = &Node(row, col, true);
					listBack = listBack->next;
					//listBack->next = nullptr; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				}

				//picList.newNode(row, col, true);

				//list->next = picList.newNode();

				// get all the nodes that are similar
				
			
				//}
				// if there are then create a new one
				//else
				//{
					//picList.newnode(row, col, list);
					//picList.insertNode(row, col, list.next);
					//list = list.next;

					// get all the nodes that are similar
					//spread(list.next, list.next, picture, newPicture, picList);
				//}
			}
		}
		cout << " row is " << row << endl;
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
//
//
//
	//list = &masterList; // this is how it works
//
//
//
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//while (list.next != nullptr)
	//{
	//	// call the recursive function with the head body Node as a paramater
	//	recursiveColorChange(list.next, list.next, picture, newPicture);
	//}

	// set current to 
	current = list; // current is set to nullptr !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	while (current->next != nullptr)  // 
	{
		if (current->ifHead)
		{
			averageColor(*current, picture, newPicture);
			recursiveColorChange(current, current, newPicture);
		}


		current = current->next;
	}


	newPicture.saveImage("newPictureAfterwards.gif");
	
	// to look at the image at different parts of the the code process use the 
	picture.saveImage("filename.gif");

	system("pause");
	return 0;
}



// spread : makes a Node linkedList of all the objects that are  
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
Node * spread(Node & seed, Node & curNode, const Image& oldPicture, Image& newPicture, int allowedDif)
{
	
		 //= head; // NEED TO MAKE A = OPERATOR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	
	// change color of new image at current postion to white becuase it starts as black,  (black = 0, white = 255)
	newPicture.changeBlue(curNode.row, curNode.col, 255);
	newPicture.changeGreen(curNode.row, curNode.col, 255);
	newPicture.changeRed(curNode.row, curNode.col, 255);


	// recursively call for the top, left right and bottom of current node

	// top
	//if (curNode.row - 1 >= 0 && ifNotTaken(newPicture, curNode.row - 1, curNode.col) && // something wrong with ifNotTaken (parameters not function)
	//	oldPicture.ifSimilarColor(seed.row, seed.col, curNode.row - 1, curNode.col, allowedDif))
	//{
	//	// create new bodyNode (and insert it after the seed)
	//	curNode.next = &Node(curNode.row - 1, curNode.col, curNode.next);

	//	// call spread for that node
	//	//spread(newHead, /*list->top*/ curNode, oldPicture, newPicture, list, allowedDif); // shouldn't be calling for curNode
	//	curNode.next = spread(seed, /*list->top*/ *curNode.next, oldPicture, newPicture, allowedDif);
	//}

	// bottom
	if (curNode.row + 1 < oldPicture.getrows() && ifNotTaken(newPicture, curNode.row + 1, curNode.col) &&
		oldPicture.ifSimilarColor(seed.row, seed.col, curNode.row + 1, curNode.col, allowedDif))
	{
		// create new bodyNode (and insert it after the newHead)
		curNode.next->addPixel(&Node(curNode.row + 1, curNode.col, curNode.next));

		curNode = curNode.next;

		// curNode is updated

		// call spread for that node
		//curNode.next = spread(seed, curNode, oldPicture, newPicture, allowedDif);
		curNode.next = &Node(spread(seed, curNode, oldPicture, newPicture, allowedDif), curNode.next);
	}

	//// left
	//if (curNode.col - 1 >= 0 && ifNotTaken(newPicture, curNode.row, curNode.col - 1) &&
	//	oldPicture.ifSimilarColor(seed.row, seed.col, curNode.row, curNode.col - 1, allowedDif))
	//{
	//	// create new bodyNode (and insert it after the newHead)
	//	curNode.next = &Node(curNode.row, curNode.col - 1, curNode.next);

	//	// call spread for that node
	//	curNode.next = spread(seed, *curNode.next, oldPicture, newPicture, allowedDif);
	//}

	//// Right
	//if (curNode.col + 1 < oldPicture.getcols() && ifNotTaken(newPicture, curNode.row, curNode.col + 1) &&
	//	oldPicture.ifSimilarColor(seed.row, seed.col, curNode.row, curNode.col + 1, allowedDif))
	//{
	//	// create new bodyNode (and insert it after the newHead)
	//	curNode.next = &Node(curNode.row, curNode.col + 1, curNode.next);

	//	// call spread for that node
	//	curNode.next = spread(seed, *curNode.next, oldPicture, newPicture, allowedDif);
	//}
	
	// return curNode
	return &curNode;
}

//// spread : makes a Node linkedList of all the objects that are  
//// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
//// Postconditions: the newPicture will look like a watered-down version of oldPicture
//void spread(Node & newHead, Node & curNode, const Image & oldPicture, Image & newPicture, linkedList list, int allowedDif)
//{
//	// change color of new image at current postion to white becuase it starts as black,  (black = 0, white = 255)
//	newPicture.changeBlue(curNode.row, curNode.col, 255);
//	newPicture.changeGreen(curNode.row, curNode.col, 255);
//	newPicture.changeRed(curNode.row, curNode.col, 255);
//	
//
//	// recursively call for the top, left right and bottom of current node
//
//	// top
//	if (curNode.row - 1 >= 0 && ifNotTaken(newPicture, curNode.row - 1, curNode.col) && // something wrong with ifNotTaken (parameters not function)
//		oldPicture.ifSimilarColor(newHead.row, newHead.col, curNode.row - 1, curNode.col, allowedDif))
//	{
//		// create new bodyNode (and insert it after the newHead)
//		curNode.next = &list.insertNode(curNode.row - 1, curNode.col, curNode.next);
//
//
//		// call spread for that node
//		//spread(newHead, /*list->top*/ curNode, oldPicture, newPicture, list, allowedDif); // shouldn't be calling for curNode
//		spread(newHead, /*list->top*/ *curNode.next, oldPicture, newPicture, list, allowedDif);
//	}
//
//	// bottom
//	if (curNode.row + 1 < oldPicture.getrows() && ifNotTaken(newPicture, curNode.row + 1, curNode.col) && 
//		oldPicture.ifSimilarColor(newHead.row, newHead.col, curNode.row + 1, curNode.col, allowedDif))
//	{
//		// create new bodyNode (and insert it after the newHead)
//		curNode.next = &list.insertNode(curNode.row + 1, curNode.col, curNode.next); 
//
//		// call spread for that node
//		spread(newHead, *curNode.next, oldPicture, newPicture, list, allowedDif);
//	}
//
//	// left
//	if (curNode.col - 1  >= 0 && ifNotTaken(newPicture, curNode.row, curNode.col - 1) &&
//		oldPicture.ifSimilarColor(newHead.row, newHead.col, curNode.row, curNode.col - 1, allowedDif))
//	{
//		// create new bodyNode (and insert it after the newHead)
//		curNode.next = &list.insertNode(curNode.row, curNode.col - 1, curNode.next);
//
//		// call spread for that node
//		spread(newHead, *curNode.next, oldPicture, newPicture, list, allowedDif);
//	}
//
//	// Right
//	if (curNode.col + 1 < oldPicture.getcols() && ifNotTaken(newPicture, curNode.row, curNode.col + 1) &&
//		oldPicture.ifSimilarColor(newHead.row, newHead.col, curNode.row, curNode.col + 1, allowedDif))
//	{
//		// create new bodyNode (and insert it after the newHead)
//		curNode.next = &list.insertNode(curNode.row, curNode.col + 1, curNode.next);
//
//		// call spread for that node
//		spread(newHead, *curNode.next, oldPicture, newPicture, list, allowedDif);
//	}
//}



// NOTE: needs to be the average color of all the pixels in the linked list

// averageColor : Gets the average color from head node until next ifHead is true and changes head to the average
// preconditions: The head and picture are initalized and head (and nodes following) are in the bounds of the image
// postconditions :
void averageColor(Node head, Image picture, Image newPicture)
{
	// loop through the linkedList of Node and using their rows and columns I would get the 
	// pixel colors add them up and devide by the number of pixels

	int numOfPixels = 0,
		red = 0,
		blue = 0,
		green = 0;

	Node* current = &head;

	// while next node isn't a headNode add
	do 
	{
		blue += picture.colorBlue(current->row, current->col);
		green += picture.colorGreen(current->row, current->col);
		red += picture.colorRed(current->row, current->col);

		numOfPixels++;

		current = current->next;
	} while (!current->next->ifHead && current->next != nullptr); //!current.next->ifHead)						 // error is here

	// then get the average by divide by numOfPixels added

	blue /= numOfPixels;
	red /= numOfPixels;
	green /= numOfPixels;

	// change head to this color in the new picture
	newPicture.changeBlue(head.row, head.col, blue);
	newPicture.changeRed(head.row, head.col, red);
	newPicture.changeGreen(head.row, head.col, green);
}


// ifNotTaken : checks if the image at a certian pixel is black or white
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: the newPicture will look like a watered-down version of oldPicture
bool ifNotTaken(const Image & picture, int row, int col)
{
	// If it is black it has not been taken
	bool ifBlack = false;

	if (picture.colorBlue(row, col) + picture.colorGreen(row, col) + picture.colorRed(row, col) == 0)
		ifBlack = true;

	return ifBlack;
}


//needs to change but first need to make the averageColor functionand a way to access the red, blue, green of the node, (the averageColor could just change the head)
//have a copyPixel function(copying the color);

// recursiveColorChange : changes the color of all the nodes under head to the color that head is
// Preconditions:  that the Image's are initialized, and that head and current also have proper linkedLists
// Postconditions: all the nodes between head and and the next node with ifHead == true;
void recursiveColorChange(const Node * head, Node * current, Image & newPicture) // need average color not current / head (only need one not both)
{
	// if it isn't the first time that this is called 
	//if (head != current)
	//{
		//// change the color of the current node
		//newPicture.changeBlue(current->row, current->col, oldPicture.colorBlue(head->row, head->col));
		//newPicture.changeGreen(current->row, current->col, oldPicture.colorGreen(head->row, head->col));
		//newPicture.changeRed(current->row, current->col, oldPicture.colorRed(head->row, head->col));
	//}

	// if the current node isn't the head
	if (head != current)
	{
		// change the color of the current node
		newPicture.changeBlue(current->row, current->col, newPicture.colorBlue(head->row, head->col));
		newPicture.changeGreen(current->row, current->col, newPicture.colorGreen(head->row, head->col));
		newPicture.changeRed(current->row, current->col, newPicture.colorRed(head->row, head->col));
	}
	
	// if the next node isn't a head node call recursively 
	if (!current->next->ifHead && current->next != nullptr)
		recursiveColorChange(head, current->next, newPicture);


	// recursively call for the top, left right and bottom
	/*if (current->top != nullptr)
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
	}*/
}




















// make a linked list of the head nodes so that when you want to call them to print you can call it without knowing how many there are