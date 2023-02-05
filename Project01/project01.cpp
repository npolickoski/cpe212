
//// Allowed Include Files & Using Declaration
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//// Functions Definitions

// Load Image 
//   - takes in data from text file and inputs it into an array
void LoadImage(const string imagefile, int image[MAXROWS][MAXCOLS])
{
    // Local Variables
    ifstream InputImage; // file input stream for image file specifically (separate from input file file stream)
    int ImageVal;        // individual piece of data taken in for image array loading


    // Open Test Image File (assumed it works as stated on Canvas)
    InputImage.open(imagefile.c_str());


    // Skipping Title Comment Line
    InputImage.ignore(100, '\n');
    //          InputImage.ignore('\n');


    // Copying Image Data to an Array (10x10
    for (int row = 0; row < MAXROWS; row++)     // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++) // for all columns
        {   
            InputImage >> ImageVal;
            image[row][col] = ImageVal;  // loads in data value from text file individually

            InputImage.ignore(1, '\n');  // ignores any non-integer characters
        }
    }


    // Closing File Stream
    InputImage.close();


    return;
}



// Horizontal Flip - flips 
//   - flips the array along the 2D y-axis
void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{
    // Local Variables
    int ImageCopy[MAXROWS][MAXCOLS];                                 // copy of "image" array to be changed


    // Horizontal Flip
    for (int row = 0; row < MAXROWS; row++)                          // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                      // for all columns
        {            
            ImageCopy[row][col] = image[row][(MAXCOLS - 1) - col];   // takes the values of the row image data and flips them
        }
    }


    // Copy Flip to Image Array
    for (int row = 0; row < MAXROWS; row++)                          // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                      // for all columns
        {            
            image[row][col] = ImageCopy[row][col];                   // takes the values of the row image data and flips them
        }
    }


    return;
}



// Vertical Flip
//   - flips the array along the 2D x-axis
void FlipVertical(int image[MAXROWS][MAXCOLS])
{
    // Local Variables
    int ImageCopy[MAXROWS][MAXCOLS];                                 // copy of "image" array to be changed


    // Vertical Flip
    for (int row = 0; row < MAXROWS; row++)                          // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                      // for all columns
        {            
            ImageCopy[row][col] = image[(MAXROWS - 1) - row][col];   // takes the values of the col image data and flips them
        }
    }


    // Copy Flip to Image Array
    for (int row = 0; row < MAXROWS; row++)                          // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                      // for all columns
        {            
            image[row][col] = ImageCopy[row][col];                   // takes the values of the row image data and flips them
        }
    }

    return;
}



// Clockwise Rotation
//   - rotates the array along the 3D z-axis 90 degrees in the right-most direction
void RotateCW(int image[MAXROWS][MAXCOLS])
{
    // Local Variables
    int ImageCopy[MAXROWS][MAXCOLS];                                // copy of "image" array to be changed


    // Clockwise Rotation
    for (int row = 0; row < MAXROWS; row++)                         // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                     // for all columns
        {            
            ImageCopy[col][row] = image[(MAXROWS - 1) - row][col];  // takes values of image data and rotates them 90 degrees CW
        }
    }


    // Copy Rotation to Image Array
    for (int row = 0; row < MAXROWS; row++)                         // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                     // for all columns
        {            
            image[row][col] = ImageCopy[row][col];                  // copies array data back to the image array
        }
    }


    return;
}


// Counter-Clockwise Rotation
//   - rotates the array along the 3D z-axis 90 degrees in the left-most direction
void RotateCCW(int image[MAXROWS][MAXCOLS])
{
    // Counter-Clockwise Rotation
    for(int i = 0; i < 3; i++)
    {
        RotateCW(image);                                              // literally just 3 clockwise rotations lol
    }
    

    return;
}


// Transpose
//   - switches the rows to columns and vice versa of the array (*see linear algebra)
void Transpose(int image[MAXROWS][MAXCOLS])
{
    // Local Variables
    int ImageCopy[MAXROWS][MAXCOLS];                              // copy of "image" array to be changed


    // Transposition
    for (int row = 0; row < MAXROWS; row++)                       // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                   // for all columns
        {            
            ImageCopy[col][row] = image[row][col];                // takes the values of the rows and columns of the image array and transposes
        }                                                         //    them into a copied array
    }


    // Copy Back
    for (int row = 0; row < MAXROWS; row++)                       // for all rows
    {
        for (int col = 0; col < MAXCOLS; col++)                   // for all columns
        {            
            image[row][col] = ImageCopy[row][col];                // copies array data back to the image array          
        }
    }


    return;
}

