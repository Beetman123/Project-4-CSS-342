// Image.cpp
//
// Author: Jaedan Parsons
//
// This file describes the interface to the ImageLib library
// This library provides the functionality to read/write GIF 
// images and process them in memory using a procedural style. 
// As well as compare and manipulate the images using normal 
// math signs
//

#include "Image.h"

// Constructor: creates an Image
// Preconditions: None
// Postconditions: a new image is returned
//				The returned image has:
//				rows = 0, cols = 0, pixels = nullptr.
Image::Image()
{
	picture.rows = 0,
	picture.cols = 0;
	picture.pixels = nullptr;
	//area.changeFirstCols(0);
	//area.changeFirstRow(0);
	//area.changeLastCol(0);
	//area.changeLastRow(0);
}

// Constructor:
// Preconditions: rows and cols describe the desired size of the new image.
// Postconditions: if sufficient memory is available, a new image
//				is returned using newly allocated memory.
//				Each pixel has red = 0, green = 0, blue = 0.
//				Otherwise, the returned image has:
//				rows = 0, cols = 0, pixels = nullptr.
Image::Image(int rows, int cols)
{
	this->picture = CreateImage(rows, cols);
}



// Copy Constructor: creates a blank, black image
// Preconditions:  Image is initalized
// Postconditions: sets the calling image to the old image
Image::Image(const Image& oldPic)
{
	this->picture = CopyImage(oldPic.picture);
}


// createImage:
// Preconditions: rows and cols describe the desired size of the new image.
// Postconditions: if sufficient memory is available, a new image
//				is returned using newly allocated memory.
//				Each pixel has red = 0, green = 0, blue = 0.
//				Otherwise, the returned image has:
//				rows = 0, cols = 0, pixels = nullptr.
//image Image::createImage(int rows, int cols)
void Image::createImage(int rows, int cols)
{
	//return CreateImage(rows, cols);
	this->picture = CreateImage(rows, cols);
}


// readImage:
// Preconditions:  filename refers to a file that stores a GIF image.
// Postconditions: returns the image contained in "filename" using the
//			conventions described for the image type above.
//		   If the load is unsuccessful, returns an image with
//		   rows = 0, cols = 0, pixels = nullptr.
void Image::readImage(string filename)
{ 
	this->picture = ReadGIF(filename);
}



// operator == : checks if two images are exactly the same
// Preconditions:  That both Images are initalized
// Postconditions: returns true if the images are the same color for each pixel, and the same size
const bool Image::operator == (const Image& im2) const 
{
	return this->isEqual(im2);
}


// operator != : checks if two images are exactly the same
// Preconditions:  That both Images are initalized
// Postconditions: returns false if the images are the same color for each pixel, and the same size
bool Image::operator != (const Image& im2)
{
	return !this->isEqual(im2); // return the opposite of isEqual
}



// isEqual : checks if two images are exactly the same
// Preconditions:  That both Images are initalized
// Postconditions: returns true if the images are the same color for each pixel, and the same size
const bool Image::isEqual(const Image& im2) const
{
	bool isEqual = true;
		
	if (this->picture.cols == im2.picture.cols && this->picture.rows == im2.picture.rows)
	{
		for (int row = 0; row < this->picture.rows; row++)
		{
			for (int col = 0; col < this->picture.rows; col++)
			{ 
				if (this->picture.pixels[row][col].blue != im2.picture.pixels[row][col].blue ||
					this->picture.pixels[row][col].green != im2.picture.pixels[row][col].green ||
					this->picture.pixels[row][col].red != im2.picture.pixels[row][col].red)
				{ 
					isEqual = false;
					break;
				}
			} 
		}
	}	
	else
		isEqual = false;

	return isEqual;
}


// saveImage: saves an image as a GIF image
// Preconditions: filename is valid filename to store a GIF image.
//				inputImage holds an image using the conventions described
//				for the image type above.
// Postconditions: inputImage is saved as a GIF image at the location
//				specified by filename.
void Image::saveImage(string filename)
{
	WriteGIF(filename, this->picture);  
}


// flipImage: It flips the left and right sides of the images
// Preconditions:  That the input image's have in.getrows * in.getcols pixels allocated 
// Postconditions: That the image's original left is now it right and vice versa
void Image::flipImage()
{
	for (int row = 0; row < this->picture.rows; row++)
	{
		for (int col = 0; col < this->picture.cols / 2; col++)
		{
			swapPixels(this->picture.pixels[row][col], this->picture.pixels[row][this->getcols() - col - 1]);  
		}
	}
}

// flipImageVert: It flips the top and bottom sides of the image
// Preconditions:  That the input image's have in.getrows * in.getcols pixels allocated 
// Postconditions: That the image's original top is now its bottom and vice versa
void Image::flipImageVert()
{
	for (int col = 0; col < this->picture.cols; col++)
	{
		for (int row = 0; row < this->picture.rows / 2; row++)
		{
			swapPixels(this->picture.pixels[row][col], this->picture.pixels[this->getrows() - row - 1][col]);
		}
	}
}

// swapPixels: Swaps two pixels 
// Preconditions:  None
// Postconditions: 'a' = 'b' and 'b' = 'a'
void Image::swapPixels(pixel& p1, pixel& p2)
{
	pixel temppixel = p1;
	p1 = p2;
	p2 = temppixel;
}

// copyPixel: copys the color of one pixel to another
// Preconditions:  None
// Postconditions: a's color == b's color 
void Image::copyPixel(pixel& orgin, pixel& copy)
{
	copy.blue = orgin.blue;
	copy.green = orgin.green;
	copy.red = orgin.red;
}



// operator > : compares if one picture has more/less pixels then the other
// Preconditions:  that both Images are initialized 
// Postconditions: returns a bool
const bool Image::operator > (const Image & im2) const
{
	bool islarger = false;

	if (this->isLarger(im2) > 0)
		islarger = true;

	return islarger;
}

// operator < : compares if one picture has more/less pixels then the other
// Preconditions:  that both Images are initialized 
// Postconditions: returns a bool
const bool Image::operator < (const Image & im2) const
{
	bool isSmaller = false;

	if (this->isLarger(im2) < 0)
		isSmaller = true;

	return isSmaller;
}

// isLarger : compares if one picture has more/less pixels then the other
// Preconditions:  that both Images are initialized 
// Postconditions: returns a int that turned into a bool when it decoded by the operators
const int Image::isLarger(Image im2) const
{
	int isLarger = 0;

	if (this->getSize() > im2.getSize())
		isLarger++;

	else if (this->getSize() < im2.getSize())
		isLarger--;

	return isLarger;
}


// getSize : returns how many pixels are in the image
// Preconditions:  that the Image is initialized 
// Postconditions: returns how many pixels are in the image
const int Image::getSize() const
{
	return this->picture.cols*this->picture.rows;
}


// operator = : set one image to equal another
// Preconditions:  that the origonal Image is initialized 
// Postconditions: the calling Image is now the same as the origonal image
Image Image::operator = (const Image & origonal)
{
	return origonal;
}


// getrows : get the number of rows in the Image
// Preconditions:  that the Image is initialized 
// Postconditions: returns the number of rows in the Image
const int Image::getrows() const
{
	return this->picture.rows; 
}

// getcols : get the number of columns in the Image
// Preconditions:  that the Image is initialized 
// Postconditions: returns the number of columns in the Image
const int Image::getcols() const
{
	return this->picture.cols;
}


// operator << : output the number of rows and the number of columns
// Preconditions:  that the Image is initialized 
// Postconditions: outputs the number of rows and the number of columns
ostream& operator << (ostream& file, Image& pic)
{
	file << "The number of rows in the image is " << pic.getrows() << " and the number of columns is " << pic.getcols() << endl;
	return file;
}

// colorBlue : outputs the number of blue color tone
// Preconditions:  that the Image is initialized 
// Postconditions: returns the number of blue color tone
const byte Image::colorBlue(int row, int col) const
{
	return this->picture.pixels[row][col].blue;	
}

// colorRed : outputs the number of red color tone
// Preconditions:  that the Image is initialized 
// Postconditions: returns the number of red color tone
const byte Image::colorRed(int row, int col) const
{
	return this->picture.pixels[row][col].red;
}

// colorGreen : outputs the number of green color tone
// Preconditions:  that the Image is initialized 
// Postconditions: returns the number of green color tone
const byte Image::colorGreen(int row, int col) const
{
	return this->picture.pixels[row][col].green;			
}


// changeBlue : changes the number of blue color tone
// Preconditions:  that the Image is initialized
// Postconditions: changes the number of blue color tone
void Image::changeBlue(int row, int col, byte color)  
{
	this->picture.pixels[row][col].blue = color; 
}



// changeRed : changes the number of red color tone
// Preconditions:  that the Image is initialized
// Postconditions: changes the number of red color tone
void Image::changeRed(int row, int col, byte color)
{
	this->picture.pixels[row][col].red = color;
}

// changeGreen : changes the number of green color tone
// Preconditions:  that the Image is initialized
// Postconditions: changes the number of green color tone
void Image::changeGreen(int row, int col, byte color)
{
	this->picture.pixels[row][col].green = color;
}

// ifSimilarColor : determines if two pixels are close enough in color 
// Preconditions:  that the Image is initialized, and both rows and columns for both pixels are within the bounds of the image
// Postconditions: returns if the colors are as similar as wanted or not 
bool Image::ifSimilarColor(int rowA, int colA, int rowB, int colB, int alowedDifference) const
{
	// if pixelB's colors added up is within 100 of all of pixelA's colors added up
	if (this->colorBlue(rowB, colB) + this->colorGreen(rowB, colB) + this->colorRed(rowB, colB) <
		this->colorBlue(rowA, colA) + this->colorGreen(rowA, colA) + this->colorRed(rowA, colA) + alowedDifference &&
		this->colorBlue(rowB, colB) + this->colorGreen(rowB, colB) + this->colorRed(rowB, colB) >
		this->colorBlue(rowA, colA) + this->colorGreen(rowA, colA) + this->colorRed(rowA, colA) - alowedDifference)
		return true; // if true return true

	// else return false
	else
		return false;
}

//DeallocateImage:
//Preconditions: inputImage contains an image using the conventions
//				for the image type described above.
// Postconditions: the memory allocated to the pixels of inputImage has
//				been deallocated.Also, the image values are set to :
//				rows = 0, cols = 0, pixels = nullptr.
Image::~Image()
{
	DeallocateImage(picture); 
}