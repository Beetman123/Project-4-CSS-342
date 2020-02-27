// Image.h
//
// Author: Jaedan Parsons
//
// This file describes the interface to the ImageLib library
// This library provides
// functionality to read/write GIF images and process them in
// memory using a procedural style. As well as compare and 
// manipulate the images using normal math signs
//

#pragma once

#include <iostream>
#include "ImageLib.h"
// #include "Rectangle.h"

using namespace std;


class Image
{
	

public:
	
	// Constructor: creates an Image
	// Preconditions: None
	// Postconditions: a new image is returned
	//				The returned image has:
	//				rows = 0, cols = 0, pixels = nullptr.
	Image(); 
	

	// createImage: creates 
	// Preconditions: rows and cols describe the desired size of the new image.
	// Postconditions: if sufficient memory is available, a new image
	//				is returned using newly allocated memory.
	//				Each pixel has red = 0, green = 0, blue = 0.
	//				Otherwise, the returned image has:
	//				rows = 0, cols = 0, pixels = nullptr.
	Image (int rows, int cols);  
	
	// Copy Constructor: creates a blank, black image
	// Preconditions:  Image is initalized
	// Postconditions: sets the calling image to the old image
	Image (const Image & old_obj); 


	// Constructor:
	// Preconditions: rows and cols describe the desired size of the new image.
	// Postconditions: if sufficient memory is available, a new image
	//				is returned using newly allocated memory.
	//				Each pixel has red = 0, green = 0, blue = 0.
	//				Otherwise, the returned image has:
	//				rows = 0, cols = 0, pixels = nullptr.
	image createImage (int rows, int cols); 

	// readImage:
	// Preconditions:  filename refers to a file that stores a GIF image.
	// Postconditions: returns the image contained in "filename" using the
	//			conventions described for the image type above.
	//		   If the load is unsuccessful, returns an image with
	//		   rows = 0, cols = 0, pixels = nullptr.
	void readImage (string filename); 

	// operator == : checks if two images are exactly the same
	// Preconditions:  That both Images are initalized
	// Postconditions: returns true if the images are the same color for each pixel, and the same size
	const bool operator == (const Image & im2) const; 	

	// operator != : checks if two images are exactly the same
	// Preconditions:  That both Images are initalized
	// Postconditions: returns false if the images are the same color for each pixel, and the same size
	bool operator != (const Image& im2); 

	// operator > : compares if one picture has more/less pixels then the other
// Preconditions:  that both Images are initialized 
// Postconditions: returns a bool						
	const bool operator > (const Image & im2) const; 

	// operator < : compares if one picture has more/less pixels then the other
	// Preconditions:  that both Images are initialized 
	// Postconditions: returns a bool
	const bool operator < (const Image & im2) const; 

	// operator << : output the number of rows and the number of columns
	// Preconditions:  that the Image is initialized 
	// Postconditions: outputs the number of rows and the number of columns
	friend ostream& operator << (ostream& file, Image &pic);	
	
	// saveImage: saves an image as a GIF image
	// Preconditions: filename is valid filename to store a GIF image.
	//				inputImage holds an image using the conventions described
	//				for the image type above.
	// Postconditions: inputImage is saved as a GIF image at the location
	//				specified by filename.
	void saveImage(string filename);

	// flipImage: It flips the left and right sides of the images
	// Preconditions:  That the input image's have in.getrows * in.getcols pixels allocated 
	// Postconditions: That the image's original left is now it right and vice versa	
	void flipImage();

	// flipImageVert: It flips the top and bottom sides of the image
	// Preconditions:  That the input image's have in.getrows * in.getcols pixels allocated 
	// Postconditions: That the image's original top is now its bottom and vice versa
	void flipImageVert();

	// swapPixels: Swaps two pixels 
	// Preconditions:  None
	// Postconditions: 'a' = 'b' and 'b' = 'a'
	void swapPixels(pixel& p1, pixel& p2);



	// getSize : returns how many pixels are in the image
	// Preconditions:  that the Image is initialized 
	// Postconditions: returns how many pixels are in the image
	const int getSize() const;

	// operator = : set one image to equal another
	// Preconditions:  that the origonal Image is initialized 
	// Postconditions: the calling Image is now the same as the origonal image
	Image operator = (const Image & origonal); 

	// getrows : get the number of rows in the Image
	// Preconditions:  that the Image is initialized 
	// Postconditions: returns the number of rows in the Image
	const int getrows() const;

	// getcols : get the number of columns in the Image
	// Preconditions:  that the Image is initialized 
	// Postconditions: returns the number of columns in the Image
	const int getcols() const; 

	// colorBlue : outputs the number of blue color tone
	// Preconditions:  that the Image is initialized 
	// Postconditions: returns the number of blue color tone
	const byte colorBlue(int row, int col) const;

	// colorRed : outputs the number of red color tone
	// Preconditions:  that the Image is initialized 
	// Postconditions: returns the number of red color tone
	const byte colorRed(int row, int col) const; 


	// colorGreen : outputs the number of green color tone
	// Preconditions:  that the Image is initialized 
	// Postconditions: returns the number of green color tone
	const byte colorGreen(int row, int col) const;

	// changeBlue : changes the number of blue color tone
	// Preconditions:  that the Image is initialized
	// Postconditions: changes the number of blue color tone
	void changeBlue (int row, int col, byte color);

	// changeRed : changes the number of red color tone
	// Preconditions:  that the Image is initialized
	// Postconditions: changes the number of red color tone
	void changeRed (int row, int col, byte color); 

	// changeGreen : changes the number of green color tone
	// Preconditions:  that the Image is initialized
	// Postconditions: changes the number of green color tone
	void changeGreen (int row, int col, byte color);

	// ifSimilarColor : determines if two pixels are close enough in color 
	// Preconditions:  that the Image is initialized, and both rows and columns for both pixels are within the bounds of the image
	// Postconditions: returns if the colors are as similar as wanted or not 
	bool ifSimilarColor(int rowOrign, int colOrign, int rowNxt, int colNxt, int alowedDifference) const;

	~Image(); 

	
private:
	image picture;


	//Rectangle area;

	// isLarger : compares if one picture has more/less pixels then the other
	// Preconditions:  that both Images are initialized 
	// Postconditions: returns a int that turned into a bool when it decoded by the operators
	const int isLarger(Image im2) const;

	// isEqual : checks if two images are exactly the same
	// Preconditions:  That both Images are initalized
	// Postconditions: returns true if the images are the same color for each pixel, and the same size
	const bool isEqual(const Image& im2) const;
};

