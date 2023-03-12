
#include <iostream>
#include <new>
#include "list.h"

List::List()
{
    head = NULL;
    //num = 0;                                    // LList w only one node (element) must point to NULL until new node is linked 
}


List::~List()
{
    // Node* TempPtr = new Node;
    // Node* IndxPtr = new Node;

    // while(Length() != 0)
    // {
    //     IndxPtr = head;

    //     while(IndxPtr->next != NULL)
    //     {
    //         TempPtr = IndxPtr;
    //         IndxPtr = IndxPtr->next
    //     }

    //     TempPtr->next = NULL;

    //     num--;
    // }

    // delete IndxPtr;
    // delete TempPtr;
    // delete head;

    if (head != NULL)
    {
        Node* TempPtr = new Node;

        while(TempPtr->next != NULL)
        {
            TempPtr = head->next;
            delete head;
            head = TempPtr;
        }

        delete head;
        delete TempPtr;
    }

    num = 0;
}


void List::Append(string newword)
{
    Node* TempPtr = new Node;
    Node* IndxPtr = head;

    while(IndxPtr->next != NULL)
    {
        IndxPtr = IndxPtr->next;
    }

    IndxPtr->next = TempPtr;

    TempPtr->word = newword;
    TempPtr->next = NULL;

    num++;

    //throw ListFull();

    return;
}


void List::InsertAt(int pos, string newword)
{
    if ((pos > Length()) || (pos < 0))
    {
        throw ListBadPosition();
        return;
    }

    Node* CrtPtr = new Node;
    Node* AftPtr = new Node;

    if (pos < Length())
    {
        CrtPtr = head;

        for (int i = 0; i < pos; i++)
        {
            CrtPtr = CrtPtr->next;
        }

        AftPtr = CrtPtr;
        CrtPtr->word = newword;
        CrtPtr->next = AftPtr;                            // straightens out the "string"
        delete AftPtr;
    }
    else if (pos == Length())
    {
        Append(newword);
    }

    num++;

    //throw ListFull();
    
    return;
}


void List::Delete(string someword)
{
    if (!(Find(someword)))
    {
        throw ListNotFound();
        return;
    }
    
    Node* TempPtr = NULL;
    Node* IndxPtr = head;

    while(IndxPtr->word != someword)
    {
        TempPtr = IndxPtr;
        IndxPtr = IndxPtr->next;
    }
    
    TempPtr->next = IndxPtr->next;
    delete IndxPtr;
    
    return;
}


void List::Replace(string oldword, string newword)
{
    if (!(Find(oldword)))
    {
        throw ListNotFound();
        return;
    }

    Node* IndxPtr = head;

    while(IndxPtr->word != oldword)
    {
        IndxPtr = IndxPtr->next;
    }

    if (IndxPtr->word == oldword)
    {
        IndxPtr->word = newword;
    }

    return;
}


int List::Length() const
{
    bitchass = 0;
    Node* TempPtr = new Node;

    if (head == NULL)
    {
        return 0;
    }

    TempPtr = head;
    do
    {
        bitchass++;
    
        if (TempPtr->next != NULL)
        {
            TempPtr = TempPtr->next;
        }

    } while (TempPtr->next != NULL);
    
    return bitchass;
}


bool List::Find(string someword) const
{
    Node* IndxPtr = head;

    while(IndxPtr->next != NULL)
    {
        if (IndxPtr->word == someword)
        {
            return true;
        }
        
        IndxPtr = IndxPtr->next;
    }

    return false;
}
