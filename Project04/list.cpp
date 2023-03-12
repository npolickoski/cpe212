
#include <iostream>
#include <new>
#include "list.h"

List::List()
{
    head = NULL;
    cout << head->next;                                // initalizing first node in the LList
    //num = 0;                                     
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
        Node* TempPtr;

        while(TempPtr->next != NULL)            // iterates through every node until the next node pointed to points to NULL
        {
            TempPtr = head->next;               // assigns temporary pointer after the current head (k -> k+1)
            delete head;                        // removes current head node
            head = TempPtr;                     // assiigns node after the previous head as the new head (k+1 = k now)
        }

        delete head;                            // deletes all nodes (current head/ temp. pointer)
        delete TempPtr;
    }

    num = 0;                                    // sets length (num of word nodes) to 0
}


void List::Append(string newword)
{
    if (Length() == 0)                          // condition for when there are no nodes in the LList
    {
        head = new Node;
    }

    Node* IndxPtr = new Node;
    
    // if (IndxPtr == NULL)
    // {
    //     cout << IndxPtr << " :)";
    // }
    // else
    // {
    //     cout << IndxPtr->word << endl << IndxPtr->next << endl << IndxPtr;
    // }

    while(IndxPtr != NULL)                      // iterates til the tail node of the LList
    {                                           //
        IndxPtr = IndxPtr->next;                //
    }                                           //                                               

    IndxPtr->word = newword;                    // assigns data to IndxPtr
    IndxPtr->next = NULL;                       // assigns pointer of IndxPtr to NULL, thus making it the new tail node

    num++;                                      // increase the length by number of nodes added (1)

    //throw ListFull();

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
