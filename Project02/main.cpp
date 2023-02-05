//
// main.cpp --  Project02, CPE212 Fall 2010 -- Classes
//
// Driver program for Card program which is used to test each
// class member function.
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

// List of allowed include files appear below
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "heart.h"
#include "diamond.h"
#include "club.h"
#include "spade.h"


using namespace std;                    // Global using declaration

void Bar();                             // Prototype for Bar function
void Print(Card*  someCard);            // Prototype for Print function



// Start of main() function

int main (int argc, char * const argv[])      // Command-line arguments (more on this later)
{
  ifstream inputs;					     // Input file stream variable for test file
  char op, ch;							 // Hold operation and optional char input from test file
  string   comment;                      // Holds comment string input from test file
  Card*    ptr = NULL;                   // Pointer to the current card
  int      v;                            // Holds card value input from test file

  
  // Output usage message if test input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project02  <inputfile>\n";
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
  getline(inputs, comment);                          // Input file header comment
  cout << endl << comment << endl << endl;           // Output file header comment
	
	
  // Below is the primary loop that processes each operation appearing within the test file.
  // Starts with an initial priming read of first operation
	
  inputs >> op;				                         // Attempt to input first test operation from file
	
  while (inputs)                                     // While Not-EOF
  {
    switch (op)                                      // Process operation input from test file
    {
	  case '#':   // Test file comment
			      getline(inputs, comment);          // Input and echo the comment appearing in the test file
			      cout << '#' << comment << endl;
			      break;
	
	  case 'p':   // Print Card 
			      Print(ptr);
			      cout << endl;
			      break;	

	  case 'b':   // Print Bar
			      Bar();                            // Function definition appears at the end of this file
			      break;				
			
	  case '+':   // Constructor
			      inputs >> op;                      // Input card type into op
			      
			      try 
		          { 
				    switch (op)                      // Invoke requested constructor with argument as required
					{
					  case 'h':   inputs >> v;    cout << "Heart(" << v << ") -- ";      ptr = new Heart(v);      break;
					  case 'd':   inputs >> v;    cout << "Diamond(" << v << ") -- ";    ptr = new Diamond(v);    break;
					  case 'c':   inputs >> v;    cout << "Club(" << v << ") -- ";       ptr = new Club(v);       break;
					  case 's':   inputs >> v;    cout << "Spade(" << v << ") -- ";      ptr = new Spade(v);      break;
					  case 'b':   inputs >> v;    cout << "BlackCard(" << v << ") -- ";  ptr = new BlackCard(v);  break;
					  case 'r':   inputs >> v;    cout << "RedCard(" << v << ") -- ";    ptr = new RedCard(v);    break;
					  case 'x':   inputs >> v;    cout << "Card(" << v << ") -- ";       ptr = new Card(v);       break;
					  case 'z':                   cout << "Card() -- ";                  ptr = new Card;          break;
					  default:                    cout << "Error: Unknown Card Type";    ptr = NULL;              break;
					}
				    cout << "Successful"; 
				  }
			      catch ( ... )                      // Catch any exception thrown above
		          { 
				    cout << "Failed";  
				  }
			
			      cout << endl;                  
				  break;
					  
      case '-':   // Destructor
                  delete ptr;                        // Deallocate card 
			      ptr = NULL;                        // Make sure that ptr is not a dangling pointer
                  break;		

	  default:    // Error
                  cout << "Error - unrecognized operation '" << op << "'" << endl;
                  cout << "Terminating now..." << endl;
				      return 1;
                  break;
    }
    //cout << endl;
	  
    inputs >> op;	                                 // Attempt to input next command
  }
 
  
  return 0;
}

/************** Implementation of Print() and Bar() functions ********************/

// DO NOT MODIFY THIS CODE

void Bar()
// Bar() -- prints horizontal bar
{
	cout << "#################################################################" << endl;
}  // End Bar()


void Print(Card*  someCard)
// Writes description of card to stdout
{
	cout << someCard->Description();	// Hint:  Polymorphic function
}

/**************  End of main.cpp  ***************/


