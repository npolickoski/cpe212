
#include <iostream>
#include <new>
#include "bstree.h"


//// Private Methods ////
template <typename SomeType>
void BSTree<SomeType>::Delete(BSTreeNode<SomeType>*& treePtr, SomeType& item)
// Recursive function that traverses the tree starting at treePtr to locate the data value to be removed
// Once located, DeleteNode is invoked to remove the value from the tree
// If tree is not empty and item is NOT present, throw NotFoundBSTree
{
    if (rootPtr == NULL)
    {
        throw EmptyBSTree();
    }
    
    if (item > treePtr->data)
    {
        if (treePtr->rightPtr == NULL)
        {
            throw NotFoundBSTree();
        }
        
        Delete(treePtr->rightPtr, item);
    }
    else if (item < treePtr->data)
    {
        if (treePtr->leftPtr == NULL)
        {
            throw NotFoundBSTree();
        }
        
        Delete(treePtr->leftPtr, item);
    }
    else
    {
        item = treePtr->data;
        DeleteNode(treePtr);
    }


    // if (treePtr == NULL)
    // {
    //     return;
    // }
    // else if (item == treePtr->data)
    // {
    //     DeleteNode(treePtr);
    // }
    // else if (item < treePtr->data)
    // {
    //     Delete(treePtr->leftPtr, item);
    // }
    // else if (item > treePtr->data)
    // {
    //     Delete(treePtr->rightPtr, item);
    // }
    // else
    // {
    //     throw NotFoundBSTree();
    // }
}


template <typename SomeType>
void BSTree<SomeType>::DeleteNode(BSTreeNode<SomeType>*& treePtr)
// Removes the node pointed to by treePtr from the tree
{
    SomeType x;
    BSTreeNode<SomeType>* tempPtr;
    tempPtr = treePtr;

    if (treePtr->rightPtr == NULL)
    {
        treePtr = treePtr->leftPtr;
        delete tempPtr;
    }
    else if (treePtr->leftPtr == NULL)
    {
        treePtr =  treePtr->rightPtr;
        delete tempPtr;
    }
    else
    {
        x = GetPredecessor(treePtr->leftPtr);
        treePtr->data = x;
        Delete(treePtr->leftPtr, x);
    }



    // BSTreeNode<SomeType>* childPtr = NULL;

    // if (treePtr->leftPtr == NULL)                             // 1 child (left)
    // {
    //     childPtr = treePtr->rightPtr;
    // }
    // else if (treePtr->rightPtr == NULL)                       // 1 child (right)
    // {
    //     childPtr = treePtr->leftPtr;
    // }
    // else                                                      // 2 children
    // {
    //     BSTreeNode<SomeType>* maxPtr; 
    //     maxPtr->data = GetPredecessor(treePtr->leftPtr);
    //     treePtr->data = maxPtr->data;
    //     DeleteNode(maxPtr);
    // }

    // delete treePtr;
    // treePtr = childPtr;

    // return;
}


template <typename SomeType>
void BSTree<SomeType>::Insert(BSTreeNode<SomeType>*& ptr, SomeType item)
// Recursive function that finds the correct position of item and adds it to the tree
// Throws FoundInBSTree if item is already in the tree
{
    if (ptr == NULL)
    {
        ptr = new BSTreeNode<SomeType>;
        ptr->data = item;
        ptr->leftPtr = NULL;
        ptr->rightPtr = NULL;
    }
    else if (item == ptr->data)
    {
        throw FoundInBSTree();
    }
    else if (item < ptr->data)
    {
        Insert(ptr->leftPtr, item);
    }
    else if (item > ptr->data)
    {
        Insert(ptr->rightPtr, item);
    }
     
    return;
}


template <typename SomeType>
void BSTree<SomeType>::Destroy(BSTreeNode<SomeType>*& ptr)
// Recursively deallocates every node in the tree pointed to by ptr
{
    if (ptr != NULL)
    {
        Destroy(ptr->leftPtr);
        Destroy(ptr->rightPtr);
        delete ptr;
    }

    return;
}


template <typename SomeType>
void BSTree<SomeType>::CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree)
// Recursively copies all data from original tree into copy
{
    if (originalTree == NULL)
    {
        copy = NULL;
    }
    else
    {
        copy = new BSTreeNode<SomeType>;
        copy->data = originalTree->data;

        CopyTree(copy->leftPtr, originalTree->leftPtr);
        CopyTree(copy->rightPtr, originalTree->rightPtr);
    }

    return;
}


template <typename SomeType>
SomeType BSTree<SomeType>::GetPredecessor(BSTreeNode<SomeType>* treePtr) const
// Finds the largest data value in the tree pointed to by treePtr and returns that data value
// as the functions return value
{
    if (treePtr->rightPtr == NULL)
    {
        return treePtr->data;
    }
    else
    {
        return GetPredecessor(treePtr->rightPtr);
    }
}


template <typename SomeType>
int BSTree<SomeType>::CountNodes(BSTreeNode<SomeType>* treePtr) const
// Recursive function that counts every node in the tree pointed to by treePtr and returns the
// count as the function return value
{
    if (treePtr == NULL)
    {
        return 0;
    }
    else
    {
        return (CountNodes(treePtr->leftPtr) + CountNodes(treePtr->rightPtr) + 1);
    }
}


template <typename SomeType>
int BSTree<SomeType>::LevelCount(BSTreeNode<SomeType>* treePtr) const
// Recursive function that traverses the entire tree to determine the total number of levels in the tree
{
    if (treePtr == NULL) 
    {
        return 0;
    } 
    else 
    {
        int leftHeight = LevelCount(treePtr->leftPtr);
        int rightHeight = LevelCount(treePtr->rightPtr);

        return std::max(leftHeight, rightHeight) + 1;
    }
}


template <typename SomeType>
int BSTree<SomeType>::FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const
// Recursive function that traverses the tree looking for item and returns the level where
// item was found
{
    if (treePtr == NULL)
    {
        throw NotFoundBSTree();
    }
    else if (item == treePtr->data) 
    {
        return 0;
    } 
    else if (item < treePtr->data) 
    {
        int leftLevel = FindLevel(treePtr->leftPtr, item);
        
        if (leftLevel == -1) 
        {
            return -1;
        } 
        else
        {
            return leftLevel + 1;
        }
    }
    else if (item > treePtr->data)
    {
        int rightLevel = FindLevel(treePtr->rightPtr, item);

        if (rightLevel == -1) 
        {
            return -1;
        } 
        else 
        {
            return rightLevel + 1;
        }
    }
}


//// Public Methods /////
template <typename SomeType>
BSTree<SomeType>::BSTree()
// Default constructor initializes root pointer to NULL
{  
    rootPtr = NULL;
}


template <typename SomeType>
BSTree<SomeType>::BSTree(const BSTree<SomeType>& someTree)
// Copy constructor for BSTree
{
    CopyTree(rootPtr, someTree.rootPtr);
}


template <typename SomeType>
void BSTree<SomeType>::operator=(const BSTree<SomeType>& originalTree)
// Overloaded assignment operator for BSTree.
{
    if (&originalTree == this)
    {
        return;
    }
    
    Destroy(rootPtr);
    CopyTree(rootPtr, originalTree.rootPtr);
}


template <typename SomeType>
BSTree<SomeType>::~BSTree()
// Destructor deallocates all tree nodes
{
    Destroy(rootPtr);
}


template <typename SomeType>
void BSTree<SomeType>::InsertItem(SomeType item)
// Inserts item into BSTree;  if tree already full, throws FullBSTree exception
// If item is already in BSTree, throw FoundInBSTree exception
{
    if (IsFull())
    {
        throw FullBSTree();
    }   

    try
    {
        Insert(rootPtr, item);
        return;
    }
    catch(const FoundInBSTree& e)
    {
        throw e;
    }
}


template <typename SomeType>
SomeType BSTree<SomeType>::DeleteItem(SomeType item)
// Deletes item from BSTree if item is present AND returns object via function return value
// If tree is empty, throw the EmptyBSTree exception
// If tree is not empty and item is NOT present, throw NotFoundBSTree
{
    if (IsEmpty())
    {
        throw EmptyBSTree();
    }

    try
    {
        Delete(rootPtr, item);
        return item;
    }
    catch(const NotFoundBSTree& e)
    {
        throw e;
    }    
}


template <typename SomeType>
void BSTree<SomeType>::MakeEmpty()
// Deallocates all BSTree nodes and sets root pointer to NULL
{
    Destroy(rootPtr);
    rootPtr = NULL;
    
    return;
}


template <typename SomeType>
int BSTree<SomeType>::Size() const
// Returns total number of data values stored in tree
{
    return CountNodes(rootPtr);
}


template <typename SomeType>
bool BSTree<SomeType>::IsFull() const
// Returns true if BSTree is full; returns false otherwise
{
    BSTreeNode<SomeType>* location;

    try
    {
        location = new BSTreeNode<SomeType>;
        delete location;

        return false;
    }
    catch(std::bad_alloc)
    {
        return true;
    }
}


template <typename SomeType>
bool BSTree<SomeType>::IsEmpty() const
// Returns true if BSTree is empty; returns false otherwise
{
    return (rootPtr == NULL);
}


template <typename SomeType>
SomeType BSTree<SomeType>::Min() const
// Returns minimum value in tree; throws EmptyBSTree if tree is empty
{
    if (IsEmpty())
    {
        throw EmptyBSTree();
    }

    BSTreeNode<SomeType>* tempPtr = rootPtr;

    while (tempPtr->leftPtr != NULL)
    {
        tempPtr = tempPtr->leftPtr;
    }
    
    return tempPtr->data;
}


template <typename SomeType>
SomeType BSTree<SomeType>::Max() const
// Returns maximum value in tree; throws EmptyBSTree if tree is empty
{
    if (IsEmpty())
    {
        throw EmptyBSTree();
    }
    else
    {
        return GetPredecessor(rootPtr);
    }
    
}

template <typename SomeType>
int BSTree<SomeType>::TotalLevels() const
// Returns the maximum level value for current tree contents
// Levels are numbered 0, 1, ..., N-1.  This function returns N
// Throws EmptyBSTree if empty
{
    if (IsEmpty())
    {
        throw EmptyBSTree();
    }

    return LevelCount(rootPtr);
}


template <typename SomeType>
int BSTree<SomeType>::Level(SomeType item) const
// Returns the level within the BSTree at which the value item is found
// If tree is empty, throws EmptyBSTree
// If tree is not empty and item is not found, throws NotFoundBSTree
{
    if (IsEmpty())
    {
        throw EmptyBSTree();
    }

    try
    {
        return FindLevel(rootPtr, item);
    }
    catch (const NotFoundBSTree& e)
    {
        throw e;
    }
}

