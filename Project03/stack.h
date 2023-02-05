//
// stack.h   2010 Fall CPE 212 -- Project03 -- Stacks
//
// The comments have been updated, but there have been no changes to the code.
//
// Specification file for Stack class, a stack of integers implemented
// as a linked list of nodes.
//
// ***** DO NOT MODIFY OR SUBMIT THIS FILE *****
//
#include <iostream>
using namespace std;


#ifndef STACK_H
#define STACK_H

class StackEmpty           
{
	// Exception class - throw an object of this type when stack is empty
	// Hint: there is no code for exception classes
};


class StackFull            
{
	// Exception class - throw an object of this type when stack is full
};

class StackInvalidPeek     
{
	// Exception class - throw an object of this type when invalid peek position is used
};


class Stack               // Models stack of integers ADT implemented as a dynamically allocated array
{
  private:
    int* array;           // Points to the stack array
	int  num;              // Holds max number of elements that may be stored in stack array
	int  top;              // Holds the index of the top data value stored on the stack
	void Resize(int n);    // Attempts to increase size of stack array to 2*num and then push n onto stack
	                       // If unable to resize, throw StackFull exception
	
  public:
    Stack(int n);         // Parameterized constructor dynamically allocates an empty stack array  
	                       // that may hold no more than n elements and initializes other private variables
                           

    ~Stack();             // Destructor deallocates all dynamically-allocated memory
	                       // associated with the object

    void Push(int n);     // Pushes integer n onto top of stack.  If stack is full, attempts to
	                       // resize stack and then push n.  If unable to resize, throws StackFull exception.

    void Pop();           // Removes top integer from stack
                          // If stack is empty, throws StackEmpty exception

	bool IsEmpty() const;  // Returns true if stack is empty; false otherwise
	
    bool IsFull() const;  // Returns true if stack is full; false otherwise
	
    void MakeEmpty();     // Removes all items from stack leaving an empty, but usable stack with capacity num
	                       // If stack is already empty, MakeEmpty() does nothing
	
    int Top() const;      // Returns value of top integer on stack WITHOUT modifying the stack
                          // If stack is empty, throws StackEmpty exception

    int Size() const;     // Returns number of items on stack WITHOUT modifying the stack


    int Max() const;      // Returns value of largest integer on stack WITHOUT modifying the stack
                          // If stack is empty, throws StackEmpty

    int Min() const;      // Returns value of smallest integer on stack WITHOUT modifying the stack
                          // If stack is empty, throws StackEmpty

	int Peek(unsigned int n) const; // Returns stack value n levels down from top of stack. Peek(0) = Top()
	                                // If position n does not exist, throws StackInvalidPeek
	
	int Capacity() const;  // Returns total num of elements that maybe stored in stack array
	
	/*******  DO NOT MODIFY ANY OF THE CODE FOR PRINT()             *******/
	/******   DO NOT PLACE A COPY OF PRINT() CODE IN STACK.CPP!!!   *******/
		
    void Print() const    // Writes stack contents to stdout, separated by a space, followed by endl
    {                      
      int index = top; 
      cout << "Top { ";
		
      while (index != -1)    // Loop to output any values stored on stack
      {
        cout << array[index] << " ";  
        index--;
      }
      cout << "} Bottom" << endl;
    } // End Print()
	
};  // End Class Stack

#endif


