//
// main.cpp  2010 Fall CPE 212 - Project05 - Binary Search Tree Template
//
// Driver program for BSTree ADT Template -- The text files (read by this code) contain a series 
// of commands that will help you test your BSTree ADT Template code by triggering various class methods.
//
// DO NOT SUBMIT THIS FILE
//
#include <iostream>
#include <fstream>
#include <string>
#include "bstree.h"
#include "student.h"


using namespace std;


int main (int argc, char * const argv[]) 
{
  ifstream inputs;					    // Input file for commands
  char op, ch;							// Hold operation and optional char input
  BSTree<Student>* tPtr = NULL;			// Will point to BSTree object
  string  comment;

  
  // Output usage message if one input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project05  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  // Process commands from input file
  getline(inputs, comment);
  cout << endl << comment << endl << endl;           // Output header comment
  inputs >> op;				                 // Attempt to input first command
  while (inputs)
  {
    // Select and perform operation input from file

    switch (op)  
    {
      case '#':   // Test file comment
                  getline(inputs, comment);
                  cout << '#' << comment;
                  break;
			
      case 'c':   // Constructor
                  cout << endl << "Constructor()";
                  try
                  {
                    tPtr = new BSTree<Student>;
                    cout << endl;
                  }
                  catch ( std::bad_alloc )
                  {
                    cout << "Failed : Terminating now..." << endl;
                    return 1;
                  }
                  break;

      case '!':   // Test copy constructor
                  try
                  {
                    cout << endl << "*** Start Copy Constructor Test ***" << endl;
                    BSTree<Student> dummy = *tPtr;
                    Student s;
                    inputs >> s;
					cout << "Print Copy without new value" << endl;
					dummy.Print();
                    dummy.InsertItem(s);
					cout << "Print Copy plus new value" << endl;
                    dummy.Print();
					cout << "Print Original without new value" << endl;
					tPtr->Print();
                    cout << "CopyConstructor -- successful" << endl;
                  }
                  catch (...)
                  {
                    cout << "CopyConstructor -- Failed: copy constructor" << endl;
                  }
		          cout << "*** End Copy Constructor Test ***" << endl;
                  break;

      case '=':   // Test overloaded assignment operator
                  try
                  {
                    cout << endl << "*** Start Operator= Test ***" << endl;
                    BSTree<Student> dummy;
                    dummy = *tPtr;
					Student s;
					inputs >> s;
					cout << "Print Copy without new value" << endl;
					dummy.Print();
					dummy.InsertItem(s);
					cout << "Print Copy plus new value" << endl;
                    dummy.Print();
					cout << "Print Original without new value" << endl;
					tPtr->Print();
					cout << "Operator= -- successful" << endl;
                  }
                  catch (...)
                  {
                    cout << "Operator= -- Failed: assignment operator" << endl;
                  }         
			      cout << "*** End Operator= Test ***" << endl;
                  break;
      case '+':   // InsertItem

                  try
                  {
                    Student s;                   // Create temporary object to hold student info from file
                    inputs >> s;                 // Use overloaded operator to populate temporary object
                    cout << "InsertItem('";
                    s.Print();					  
                    cout << "')";
                    tPtr->InsertItem(s);
                  }
                  catch (FullBSTree)
                  {
                    cout << " -- Failed Full BSTree"; 
                  }
                  catch (FoundInBSTree)
                  {
                    cout << " -- Failed Item Already Found In BSTree";
                  }
                  cout << endl;
                  break;

      case '-':   // DeleteItem
                  try
                  {
                    int id;
                    inputs >> id;
                    Student s(id, "NULL", "NULL");
                    cout << "DeleteItem('" << id << "') -- ";
                    s = tPtr->DeleteItem(s);
                    cout << "Deleted  ";
                    s.Print();
                  }
                  catch (EmptyBSTree)
                  {
                    cout << " -- Failed Empty BSTree";
                  }
                  catch (NotFoundBSTree)
                  {
                    cout << " -- Failed Not Found in BSTree";
                  }
                  cout << endl;
                  break;
			  
      case 'p':   // Print BSTree
                  tPtr->Print();
                  break;

      case 's':   // Size of BSTree
                  cout << "Size() -- " << tPtr->Size() << endl;  
                  break;
				  
      case 'm':   // Make BSTree Empty
                  tPtr->MakeEmpty();
                  cout << "MakeEmpty()"<< endl;  
                  break;

      case 'd':   // Destructor
                  delete tPtr;
                  tPtr = NULL;
                  cout << "Destructor()" << endl << endl;
                  break;
			
      case '<':   // Minimum
                  cout << "Min() -- ";
                  try
                  {
                    cout << tPtr->Min() << endl;
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }
                  break;

       case '>':   // Maximum
                  cout << "Max() -- ";
                  try
                  {
                    cout << tPtr->Max() << endl;
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }			
                  break;
			
        case 'l':   // Size of BSTree
                  try
                  {
                    cout << "TotalLevels() -- " << tPtr->TotalLevels() << endl;
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "TotalLevels() -- Failed Empty BSTree" << endl;
                  }
                  break;	

        case '?':   // Size of BSTree
                  try
                  {
                    int id;
                    inputs >> id;
                    Student s(id, "NULL", "NULL");
                    cout << "Level('" << s << "') -- ";
                    cout << tPtr->Level(s) << endl;  
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }
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
}

/************** Implementation of Print() function ********************/

// DO NOT MODIFY THIS CODE

#include <queue> 

// This code uses the Standard Template Libary queue class, container adapter wrapper
// that makes the deque (double-ended queue) look more like a single-ended queue.
// Note the different names used for the enqueue and dequeue operations.

template <typename SomeType>
void PreOrder(BSTreeNode<SomeType>* tree, queue<SomeType>& preorder)
// Post: preorder contains the tree items in preorder.
{
	if (tree != NULL)
	{
		preorder.push(tree->data);
		PreOrder(tree->leftPtr, preorder);
		PreOrder(tree->rightPtr, preorder);
	}
}

template <typename SomeType>
void InOrder(BSTreeNode<SomeType>* tree, queue<SomeType>& inorder)
// Post: inorder contains the tree items in inorder.
{
	if (tree != NULL)
	{
		InOrder(tree->leftPtr, inorder);
		inorder.push(tree->data);
		InOrder(tree->rightPtr, inorder);
	}
}

template <typename SomeType>
void PostOrder(BSTreeNode<SomeType>* tree, queue<SomeType>& postorder)
// Post: postorder contains the tree items in postorder.
{
	if (tree != NULL)
	{
		PostOrder(tree->leftPtr, postorder);
		PostOrder(tree->rightPtr, postorder);
		postorder.push(tree->data);
	}
}

template <typename SomeType>
void BSTree<SomeType>::Print() const
{
	queue<SomeType> preorder, inorder, postorder;
	
	PreOrder(rootPtr, preorder);
	InOrder(rootPtr, inorder);
	PostOrder(rootPtr, postorder);
	
	cout << "Print() \n-- Inorder = { ";
	while (!inorder.empty())
	{
		cout << inorder.front() << " ";
		inorder.pop();
	}
	cout << "}   \n-- Preorder = { ";
	while (!preorder.empty())
	{
		cout << preorder.front() << " ";
		preorder.pop();		
	}
	cout << "}   \n-- Postorder = { ";
	while (!postorder.empty())
	{
		cout << postorder.front() << " ";
		postorder.pop();		
	}
	cout << "}" << endl;
}


