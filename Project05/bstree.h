//
// bstree.h  2010 Fall CPE 212 - Project05 - Binary Search Tree Template
//
// Provides a declaration of the BSTree class template.
//
// DO NOT MODIFY OR SUBMIT THIS FILE 
//

#ifndef BSTREE_H
#define BSTREE_H

#include <cstddef>
#include <new>
#include <string>

using namespace std;

class FullBSTree  						// Exception class models full BSTree condition
{ 
	/* No code here */
};

class EmptyBSTree						// Exception class models empty BSTree condition
{
	/* No code here */
};

class NotFoundBSTree					// Exception class models not found in BSTree condition
{
	/* No code here */
};

class FoundInBSTree                     // Exception class models found in BSTree condition
{
	/* No code here */
};

template <typename SomeType>
struct BSTreeNode						// Node of BSTree
{
  SomeType data;						// Data stored in node
  BSTreeNode<SomeType>* leftPtr;		// Pointer to left subtree
  BSTreeNode<SomeType>* rightPtr;		// Pointer to right subtree
};

template <typename SomeType>
class BSTree							// BSTree Abstract Data Type
{
private:
  BSTreeNode<SomeType>* rootPtr;		// Pointer to root of BSTree
	
  /**************  Start of Private Helper Functions You Must Implement ****************/	
  void Delete(BSTreeNode<SomeType>*& treePtr, SomeType& item);
  // Delete()
  // Recursive function that traverses the tree starting at treePtr to locate the data value to be removed
  // Once located, DeleteNode is invoked to remove the value from the tree
  // If tree is not empty and item is NOT present, throw NotFoundBSTree	
	
  void DeleteNode(BSTreeNode<SomeType>*& treePtr);
  // DeleteNode()
  // Removes the node pointed to by treePtr from the tree
  // Hint:  calls GetPredecessor and Delete

  void Insert(BSTreeNode<SomeType>*& ptr, SomeType item);
  // Insert()
  // Recursive function that finds the correct position of item and adds it to the tree
  // Throws FoundInBSTree if item is already in the tree	

  void Destroy(BSTreeNode<SomeType>*& ptr);
  // Destroy()
  // Recursively deallocates every node in the tree pointed to by ptr

  void CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree);
  // CopyTree()
  // Recursively copies all data from original tree into copy
	
  SomeType GetPredecessor(BSTreeNode<SomeType>* treePtr) const;
  // GetPredecessor()
  // Finds the largest data value in the tree pointed to by treePtr and returns that data value
  // as the functions return value
	
  int CountNodes(BSTreeNode<SomeType>* treePtr) const;
  // CountNodes()
  // Recursive function that counts every node in the tree pointed to by treePtr and returns the
  // count as the function return value
	
  int LevelCount(BSTreeNode<SomeType>* treePtr) const;
  // LevelCount()
  // Recursive function that traverses the entire tree to determine the total number of levels in the tree

  int FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const;
  // FindLevel()
  // Recursive function that traverses the tree looking for item and returns the level where
  // item was found


  /**************  End of Private Helper Functions You Must Implement ****************/

public:

  /**************  Start of Public Interface Functions You Must Implement ****************/
	
  BSTree();								
  // BSTree()
  // Default constructor initializes root pointer to NULL
	
  BSTree(const BSTree<SomeType>& someTree);
  // BSTree() 
  // Copy constructor for BSTree
  // Hint:  calls CopyTree
	
  void operator=(const BSTree<SomeType>& originalTree);
  // operator=() 
  // Overloaded assignment operator for BSTree.
  // Hint:  calls CopyTree

  ~BSTree();							
  // ~BSTree()
  // Destructor deallocates all tree nodes
  // Hint:  calls the private helper function Destroy
  
  void InsertItem(SomeType item);		
  // InsertItem()
  // Inserts item into BSTree;  if tree already full, throws FullBSTree exception
  // If item is already in BSTree, throw FoundInBSTree exception
  // Hint:  calls the private helper function Insert
  
  SomeType DeleteItem(SomeType item);		
  // DeleteItem()
  // Deletes item from BSTree if item is present AND returns object via function return value
  // If tree is empty, throw the EmptyBSTree exception
  // If tree is not empty and item is NOT present, throw NotFoundBSTree
  // Hint:  calls the private helper function Delete
  
  void MakeEmpty();						
  // MakeEmpty()
  // Deallocates all BSTree nodes and sets root pointer to NULL
  // Hint:  calls the private helper function Destroy
  
  int Size() const;	
  // Size()
  // Returns total number of data values stored in tree
  
  bool IsFull() const;					
  // IsFull()
  // Returns true if BSTree is full; returns false otherwise
  
  bool IsEmpty() const;					
  // IsEmpty()
  // Returns true if BSTree is empty; returns false otherwise
  	
  SomeType Min() const;                 
  // Min()
  // Returns minimum value in tree; throws EmptyBSTree if tree is empty
	
  SomeType Max() const;                 
  // Max()
  // Returns maximum value in tree; throws EmptyBSTree if tree is empty
	
  int TotalLevels() const;              
  // TotalLevels()
  // Returns the maximum level value for current tree contents
  // Levels are numbered 0, 1, ..., N-1.  This function returns N
  // Throws EmptyBSTree if empty
  // Hint:  calls the private helper function LevelCount

  int Level(SomeType item) const;       
  // Level()
  // Returns the level within the BSTree at which the value item is found
  // If tree is empty, throws EmptyBSTree
  // If tree is not empty and item is not found, throws NotFoundBSTree
  // Hint:  calls the private helper funtion FindLevel
	
  /**************  End of Functions You Must Implement ****************/
	
	
	
  void Print() const;  // DO NOT WRITE THIS FUNCTION
  // Print()
  // Prints binary search tree contents in inorder, preorder, and postorder forms
  // NOTE: THIS CODE HAS BEEN INCLUDED AT THE END OF main.cpp
};

#include "bstree.cpp"                   // Note: Template classes cannot be compiled on their own
                                        // since the data type argument is found in the client code.

#endif
