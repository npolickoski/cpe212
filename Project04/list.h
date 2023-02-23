//
// list.h -- 2010 Fall CPE 212 -- Project04 -- Lists
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class ListEmpty        {  /*** Empty Error Class ***/  };
class ListFull         {  /*** Empty Error Class ***/  };
class ListNotFound     {  /*** Empty Error Class ***/  };
class ListBadPosition  {  /*** Empty Error Class ***/  };

struct Node
{
  string word;          // A word in a phrase
  Node* next;           // Pointer to next node in sequence
};

class List              // List ADT used to store words in a phrase
{
 private:
  Node* head;           // Pointer to head of word list
  int   num;            // Number of words stored in list

 public:
  /***** Constructor and Destructor *****/
  List();               
  // Description of List()
  // Constructor sets state of list to empty

  ~List(); 
  // Description of ~List()             
  // Destructor must deallocate all list nodes


  /***** Transformer Methods *****/
  void Append(string newword);                   
  // Description of Append(...)
  // Appends newword to the end of the current phrase 
  // Error Handling: If list is full, throw ListFull object.

  void InsertAt(int pos, string newword);
  // Description of InsertAt(...)
  // Inserts newword at position pos.
  // Positions numbered starting with zero (0 <= pos <= num).
  // Hint: pos == num ==> append
  // Word previously at pos should now be at position pos+1
  // Error Handling: If list is full, throws ListFull object
  //                 If pos out of range, throws ListBadPosition object

  void Delete(string someword);
  // Description of Delete(...)
  // Deletes the first instance of someword if it is present.  
  // Error Handling: If someword is not in list, throws ListNotFound object

  void Replace(string oldword, string newword);
  // Description of Replace(...)
  // Replaces the first instance of oldword with newword.  
  // Error Handling: If oldword not found, throws ListNotFound object
  

  /***** Observer Methods *****/
  int Length() const;
  // Description of Length()
  // Returns number of words in the list
  // Error Handling: none

  bool Find(string someword) const;
  // Description of Find(...)
  // Returns true if someword is in list, false otherwise
  // Error Handling: none


  // DO NOT MODIFY OR SUBMIT Print()
  void Print() const                        
  // Description of Print()
  // Prints the entire phrase to stdout
  {
    Node*  temp = head;           // Temp variable for scanning through list starting at head

    cout << "Head {";             // Output open brace
    while (temp != NULL)          // While there are words that must be printed...
    {
      cout << ' ' << temp->word;  // ... print the next word
      temp = temp->next;          // ... and advance to the next node.
    }

    cout << " }";                  // Output close brace 
  }
};

#endif




