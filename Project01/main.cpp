//
// main.cpp --  Project01, CPE212 Fall 2010 -- C++ Review Project
//
// Driver program for Image Processing Program which is used to test each
// image processing operation.
//
// DO NOT SUBMIT OR SUBMIT THIS FILE
//

// List of allowed include files appear below
#include <iostream>
#include <fstream>
#include <string>

using namespace std;                    // Global using declaration

// Global Constants -- you may use these global constants in your code
const int MAXROWS = 10;                 // Maximum number of rows in image
const int MAXCOLS = 10;                 // Maximum number of columns in image

// Function Prototypes for functions included at the end of main.cpp
void Print(const int image[MAXROWS][MAXCOLS]);
void Bars();

// Function Prototypes for the functions you must implement in project01.cpp
void LoadImage(const string imagefile, int image[MAXROWS][MAXCOLS]);
void FlipHorizontal(int image[MAXROWS][MAXCOLS]);
void FlipVertical(int image[MAXROWS][MAXCOLS]);
void RotateCW(int image[MAXROWS][MAXCOLS]);
void RotateCCW(int image[MAXROWS][MAXCOLS]);
void Transpose(int image[MAXROWS][MAXCOLS]);


// Start of main() function

int main (int argc, char * const argv[])      // Command-line arguments (more on this later)
{
  ifstream inputs;			      // Input file stream variable for test file
  char op, ch;				      // Hold operation and optional char input from test file
  string  comment;                            // Holds comment string input from test file
  int image[MAXROWS][MAXCOLS];                // Array of integers representing image
  string imagefile;                           // Name of image file

  
  // Output usage message if test input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project01  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open test input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  // Process comment line from input file
  getline(inputs, comment);                    // Input file header comment
  cout << endl << comment << endl << endl;     // Output file header comment
	
	
  // Below is primary loop that processes each operation appearing within the test file.
  // Starts with an initial priming read of first operation
	
  inputs >> op;			// Attempt to input first test operation from file
	
  while (inputs)                // While Not-EOF
  {
    switch (op)                 // Process operation input from test file
    {
	  case '#':   // Test file comment
                      getline(inputs, comment);      // Input and echo the comment appearing in the test file
                      cout << '#' << comment << endl;
                      break;
			
	  case 'p':   // Print Grid 
                      Print(image);                  // Function definition appears at the end of this file
                      break;					
			
	  case 'b':   // Print Bars
                      Bars();                        // Function definition appears at the end of this file
                      break;				
			
	  case 'i':   // Load Image
                      inputs >> imagefile;           // Input name of imagefile from test file
                      LoadImage(imagefile, image);   // Implement this function in project01.cpp
                      break;
					  
          case '+':   // Rotate Image Clockwise 90 Degrees
                      RotateCW(image);               // Implement this function in project01.cpp
                      break;

          case '-':   // Rotate Image Counterclockwise 90 Degrees
                      RotateCCW(image);              // Implement this function in project01.cpp
                      break;			  

	  case 'v':   // Flip Image Vertical
                      FlipVertical(image);           // Implement this function in project01.cpp
                      break;
						
	  case 'h':   // Flip Image Horizontal
                      FlipHorizontal(image);         // Implement this function in project01.cpp
                      break;

	  case 't':   // Transpose Image Across Major Diagonal
                      Transpose(image);              // Implement this function in project01.cpp
                      break;			

	  default:    // Error
                      cout << "Error - unrecognized operation '" << op << "'" << endl;
                      cout << "Terminating now..." << endl;
                      return 1;
                      break;
    }
    cout << endl;
	  
    inputs >> op;	                             // Attempt to input next command
  }
 
  
  return 0;
}

/************** Implementation of Print() and Bars() functions ********************/

// DO NOT MODIFY THIS CODE

void Print(const int image[MAXROWS][MAXCOLS]) 
// Print() -- outputs image row-by-row in desired format substituting
// * for 1 and - for 0.
{
	for(int r=0; r < MAXROWS; r++)               // Loop to visit each row in image
	{
		for(int c=0; c < MAXCOLS; c++)       // Loop to output every element on current row
		{
			if (image[r][c] == 1)        // Output appropriate symbol
			{
				cout << '*';
			}
			else if (image[r][c] == 0)
			{
				cout << '-';
			}
			else
			{
				cout << 'X';
			}
		}
		cout << endl;
	}
	
}  // End Print()

void Bars()
// Bars() -- prints two horizontal rows of bars 
{
	cout << "#################################################################" << endl;
	cout << "#################################################################" << endl;
}  // End Bars()

/************** DO NOT DELETE *************/
// The preprocessor directive below will import the function definitions 
// from the file project01.cpp and place them at the end of this file creating an
// Expanded Source File which is forwarded to the compiler for compilation.

#include "project01.cpp"

/**************  End of main.cpp  ***************/


