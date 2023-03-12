
#include <iostream>
#include <new>
#include "list.h"

List::List()
{
    head = NULL;                                // initalizing first node in the LList                                    
}


List::~List()
{
    Node* CrtPtr = head;
    Node* IndxPtr = NULL;

    while (CrtPtr != NULL)
    {
        Node* IndxPtr = CrtPtr->next;
        
        delete CrtPtr;
        CrtPtr = IndxPtr;
    }
}


void List::Append(string newword)
{
    Node* IndxPtr = new Node;
    IndxPtr->word = newword;                    // assigns data to IndxPtr
    IndxPtr->next = NULL;

    if (head == NULL)                           // condition for when there are no nodes in the LList
    {
        head = IndxPtr;
    }
    else
    {
        Node* CrtPtr = head;

        while(CrtPtr->next != NULL)             // iterates til the tail node of the LList
        {                                       //
            CrtPtr = CrtPtr->next;              //
        }                                       //  

        CrtPtr->next = IndxPtr;                                             
    }

    return;
}


void List::InsertAt(int pos, string newword)
{
    if ((pos > Length()) || (pos < 0))          // exception handeling for when postion new node is added to is out of bounds
    {
        throw ListBadPosition();
        return;
    }

    Node* CrtPtr;
    Node* AftPtr;

    if (pos < Length())                         // condition for when the postion to add new node is within the length of the LList
    {
        CrtPtr = head;

        for (int i = 0; i < pos; i++)           // iterates until the desired postion in the LList is met
        {
            CrtPtr = CrtPtr->next;
        }

        AftPtr = CrtPtr;                        // creates exact copy of node at said position
        CrtPtr->word = newword;                 // assigns new data to orignal node
        CrtPtr->next = AftPtr;                  // "straightens out the string"
        delete AftPtr;                          // removes temp. poiner "AftPtr" to not cause memory leak
    }
    else if (pos == Length())                   // condition for when the desired postion is the tail node
    {
        Append(newword);                        // use Appened method
    }

    num++;                                      // increases length

    //throw ListFull();
    
    return;
}


void List::Delete(string someword)
{
    if (!(Find(someword)))                      // exception handling for when desired word to delete is not found
    {
        throw ListNotFound();
        return;
    }
    
    Node* TempPtr = NULL;
    Node* IndxPtr = head;

    while(IndxPtr->word != someword)            // interates through all nodes for exact data match
    {
        TempPtr = IndxPtr;                      // must keep copy of previous node (k-1)
        IndxPtr = IndxPtr->next;                // iterates to next node in LList
    }
    
    TempPtr->next = IndxPtr->next;              // once data is found, pointer to the node that contains said data is 
    delete IndxPtr;                             //      rerouted to node after said and thus deleted 
                                                // Ex: "k-1 -> k -> k+1" is now "k-1 -> k+1; k is deleted"    
    return;
}


void List::Replace(string oldword, string newword)
{
    if (!(Find(oldword)))                       // exception handeled for when data to replace is not in LList
    {
        throw ListNotFound();
        return;
    }

    Node* IndxPtr = head;

    while(IndxPtr->word != oldword)             // iterates through all nodes until desired data is found
    {
        IndxPtr = IndxPtr->next;
    }

    if (IndxPtr->word == oldword)               // assigns new data to node
    {
        IndxPtr->word = newword;
    }

    return;
}


int List::Length() const
{
    int num = 0;
    Node* TempPtr;

    if (head == NULL)                           // condition for when there are no nodes
    {
        return 0;
    }

    TempPtr = head;
    do
    {
        num++;                                  // adds 1 to length count
    
        if (TempPtr->next != NULL)              // iterates through all nodes in LList until tail node is reached
        {
            TempPtr = TempPtr->next;
        }

    } while (TempPtr->next != NULL);
    
    return num;
}


bool List::Find(string someword) const
{
    Node* IndxPtr = head;

    while(IndxPtr->next != NULL)                // iterates through all nodes in LList until tail node is reached
    {
        if (IndxPtr->word == someword)          // condition for when desired is found
        {
            return true;
        }
        
        IndxPtr = IndxPtr->next;                // otherwise iteration continues
    }

    return false;
}
