
#include <iostream>
#include <new>
#include "list.h"

List::List()
{
    head = NULL;                                // initalizing pointer that will eventually point to the first node in the LList                                    
}


List::~List()
{
    Node* CrtPtr = head;                        // initalizes the first node to iterate through ("head-to-tail" method)
    Node* IndxPtr = NULL;

    while (CrtPtr != NULL)                      // iterates through each node in the LList ("head-to-tail" method)
    {
        IndxPtr = CrtPtr->next;                 // saves next node in the LList

        delete CrtPtr;                          // deallocates the memory assocated w/ each node
        CrtPtr = IndxPtr;                       // switches pointers to begin next deallocation
    }
}


void List::Append(string newword)
{
    Node* IndxPtr = new Node;                   // creates a new node w/ data and pointer to next node
    IndxPtr->word = newword;                    // (data)
    IndxPtr->next = NULL;                       // (pointer - must be NULL to be the "tail" of the LList)

    if (head == NULL)                           // conditional #1: node to appened is the head node      
    {
        head = IndxPtr;                         // assigns the new node as the head node
    }
    else                                        // conditional #2: node to append is at some position after the head node
    {
        Node* CrtPtr = head;

        while(CrtPtr->next != NULL)             // iterates through all nodes until the tail node is reached   
        {                                       
            CrtPtr = CrtPtr->next;              
        }                                         

        CrtPtr->next = IndxPtr;                 // assigns the new node as the new tail node                             
    }

    return;
}


void List::InsertAt(int pos, string newword)
{
    if ((pos > Length()) || (pos < 0))          // exception handeler: when the position is out of range (must be "0 <= pos <= Length()") 
    {
        throw ListBadPosition();
    }

    Node* TempPtr = new Node;                   // creates new node w/ new data, but not a new pointer (yet)
    TempPtr->word = newword;                    // (data)

    if ((head == NULL) || (pos == 0))           // conditional #1: if the incertion point is the head node                
    {
        TempPtr->next = head;
        head = TempPtr;
    }    
    else                                        // conditional #2: if the incertion point is after the head node
    {
        Node* CrtPtr = head;                    // initializes first node in the LList
        Node* BfrPtr = NULL;

        for (int i = 0; i < pos; i++)           // iterates though every node until the desired position is reached  
        {
            BfrPtr = CrtPtr;
            CrtPtr = CrtPtr->next;
        }

        TempPtr->next = CrtPtr;                 // sets the new node's pointer to the current position node
        BfrPtr->next = TempPtr;                 // sets the prior node's pointer to the new node now ("straightens the string")
    }
    
    return;
}


void List::Delete(string someword)
{
    Node* CrtPtr = head;                        // initalizes the first node to iterate through ("head-to-tail" method)
    Node* BfrPtr = NULL;                        

    while ((CrtPtr != NULL) && (CrtPtr->word != someword))  // iterates through all nodes until desired data point is found
    {
        BfrPtr = CrtPtr;                        // saves node that will be right before deallocated node
        CrtPtr = CrtPtr->next;                  // moves onto next node
    }

    if (CrtPtr == NULL)                         // exception handeler: if all nodes are gone through and point of data is not found
    {
        throw ListNotFound();
    }

    if (BfrPtr == NULL)                         // conditional #1: if the node to be deleted is the current head node
    {
        head = CrtPtr->next;
    }
    else                                        // conditional #2: if the node to be deleted is after the head node
    {
        BfrPtr->next = CrtPtr->next;
    }

    delete CrtPtr;                              // deallocates memory associated with node
}


void List::Replace(string oldword, string newword)
{
    Node* CrtPtr = head;                        // initalizes the first node to iterate through ("head-to-tail" method)

    while((CrtPtr != NULL) && (CrtPtr->word != oldword))    // iterates through all nodes until desired data point is found
    {
        CrtPtr = CrtPtr->next;
    }

    if (CrtPtr == NULL)                         // exception handeler: if all nodes are gone through and point of data is not found
    {
        throw ListNotFound();
    }

    CrtPtr->word = newword;                     // changes data in desired node to new point of data
}


int List::Length() const
{
    int count = 0;                              // initalizes count
    Node* CrtPtr = head;                        // initalizes the first node to iterate through ("head-to-tail" method)

    while (CrtPtr != NULL)                      // iterates through all nodes and counts how many have passed
    {
        count++;
        CrtPtr = CrtPtr->next;
    }
    
    return count;                               // returns number of nodes counted
}


bool List::Find(string someword) const
{
    Node* CrtPtr = head;                        // initalizes the first node to iterate through ("head-to-tail" method)

    while (CrtPtr != NULL)                      // iterates through all nodes until desired data point is found
    {
        if (CrtPtr->word == someword)           // conditional: if the current node's data point is the same as the 
        {                                       //      desired data point to be found
            return true;                        // returns true if data is found
        }
        
        CrtPtr = CrtPtr->next;                  // goes to next node in LList          
    }

    return false;                               // returns false if data is not found
}
