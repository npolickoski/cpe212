//
// main.cpp -- 2010 Fall -- Project04 -- Lists
//
// Driver program for List ADT -- The text files (read by this code) contain a series of commands
// that will help you test your List ADT code by triggering various List class methods.
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//
#include <iostream>
#include <fstream>
#include <new>
#include <cstddef>
#include "list.h"

using namespace std;

int main(int argc, char* argv[])
{
  ifstream inputs;					// Input file for commands
  char op;						      // Hold operation and optional char input
  string value, value2;          // Values input from file
  string comment;                // Holds comment from file
  int pos;                       // Holds position value from file
  List* ptr = NULL;				   // Will point to List object
  
  // Output usage message if one input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project04  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  // Input and echo header comment from file
  getline(inputs, comment);          // Input and echo the comment appearing in the test file
  cout << endl << '#' << comment << endl << endl;	
	
  // Process commands from input file
  inputs >> op;				        // Attempt to input first command
  while (inputs)
  {
    switch (op)                     // Process operation input from file
    {
      case '#':   // Test file comment
                  getline(inputs, comment);     // Input and echo the comment appearing in the test file
                  cout << '#' << comment << endl;
                  break;
			
      case 'c':   // Parameterized Constructor
                  cout << endl << "List()";
                  try
                  {
                    ptr = new List();           // Attempt to create a List object
                    cout << " -- Successful" << endl;
                  }
                  catch ( std::bad_alloc )
                  {
                    cout << "Failed : Terminating now..." << endl;
                    return 1;
                  }
                  break;

      case 'a':   // Append
                  inputs >> value;
                  cout << "Append(" << value << ")";
                  try
                  {
                    ptr->Append(value);
                    cout << " -- successful";
                  }
                  catch (ListFull)
                  {
                    cout << " -- Failed Full List"; 
                  }
                  cout << endl;
                  break;

      case '-':   // Delete word
                  inputs >> value;
                  cout << "Delete(" << value << ") -- ";
                  try
                  {
                    ptr->Delete(value);
                    cout << "successful";
                  }
                  catch (ListNotFound)
                  {
                    cout << "Failed Not In List";
                  }
                  cout << endl;
                  break;
			
      case '+':   // Insert at position
                  inputs >> pos >> value;            
                  cout << "InsertAt(" << pos << ", " << value << ") -- ";
                  try
                  {
                    ptr->InsertAt(pos, value);
                    cout << "Successful" << endl;
                  }
                  catch (ListBadPosition)
                  {
                    cout << "Failed Bad Position" << endl;
                  }
                  break;			
		
      case 'p':   // Print List
                  cout << "Print() -- ";
                  ptr->Print();	
                  cout << endl;
                  break;

      case 'r':   // Replace word
                  inputs >> value >> value2;
                  try
                  {
                    cout << "Replace(" << value << ", " << value2 << ") -- ";
                    ptr->Replace(value, value2);
                    cout << "Successful" << endl;
                  }
                  catch (ListNotFound)
                  {
                    cout << "Failed Not Found in List" << endl;
                  }
                  break;	
		
      case '?':   // Find in List
                  inputs >> value;
                  if ( ptr->Find(value) )
                  {
                    cout << "Find(" << value << ") -- True" << endl;  
                  }
                  else
                  {
                    cout << "Find(" << value << ") -- False" << endl;
                  }
                  break;
			
      case 'l':   // Length of List
                  cout << "Length() -- " << ptr->Length() << endl;  
                  break;	

      case 'd':   // Destructor
                  delete ptr;
                  ptr = NULL;
                  cout << "~List()" << endl << endl;
                  break;

      default:    // Error
                  cout << "Error - unrecognized operation '" << op << "'" << endl;
                  cout << "Terminating now..." << endl;
				      return 1;
                  break;
    }
 
    inputs >> op;	// Attempt to input next command
  }
  
  return 0;
} // End main()

