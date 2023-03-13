
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
    }

    Node* TempPtr = new Node;
    TempPtr->word = newword;

    if ((head == NULL) || (pos == 0))                         // condition for when the postion to add new node is within the length of the LList
    {
        TempPtr->next = head;
        head = TempPtr;
    }    
    else
    {
        Node* CrtPtr = head;
        Node* BfrPtr = NULL;

        for (int i = 0; i < pos; i++)           // iterates until the desired postion in the LList is met
        {
            BfrPtr = CrtPtr;
            CrtPtr = CrtPtr->next;
        }

        TempPtr->next = CrtPtr;
        BfrPtr->next = TempPtr;
    }
    
    return;
}


void List::Delete(string someword)
{
    Node* CrtPtr = head;
    Node* BfrPtr = NULL;

    while ((CrtPtr != NULL) && (CrtPtr->word != someword))
    {
        BfrPtr = CrtPtr;
        CrtPtr = CrtPtr->next;
    }

    if (CrtPtr == NULL)
    {
        throw ListNotFound();
    }

    if (BfrPtr == NULL)
    {
        head = CrtPtr->next;
    }
    else
    {
        BfrPtr->next = CrtPtr->next;
    }

    delete CrtPtr;
}


void List::Replace(string oldword, string newword)
{
    Node* CrtPtr = head;

    while((CrtPtr != NULL) && (CrtPtr->word != oldword))
    {
        CrtPtr = CrtPtr->next;
    }

    if (CrtPtr == NULL)
    {
        throw ListNotFound;
    }

    CrtPtr->word = newword;
}


int List::Length() const
{
    int count = 0;
    Node* CrtPtr = head;

    while (CrtPtr != NULL)
    {
        count++;
        CrtPtr = CrtPtr->next;
    }
    
    return count;
}


bool List::Find(string someword) const
{
    Node* CrtPtr = head;

    while (CrtPtr != NULL)                // iterates through all nodes in LList until tail node is reached
    {
        if (CrtPtr->word == someword)          // condition for when desired is found
        {
            return true;
        }
        
        CrtPtr = CrtPtr->next;                // otherwise iteration continues
    }

    return false;
}
