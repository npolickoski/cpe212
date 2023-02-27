
#include <iostream>
#include <new>
#include "stack.h"

void Stack::Resize(int n)
{
    try
    {
        int new_size = 2 * num;                                 // creates variable for doubling stack size

        int* newArray = new int[new_size];                      // heap memory allocation for new array
        for(int i = 0; i < num; i++)
        {
            newArray[i] = array[i];
        }

        delete array;
        array = newArray;                                       // relocates new array back to original array but with size change
        num = new_size;                                         // updates max size of the array to the doubled size
    }
    catch(...)
    {
        throw StackFull();
    }

    Push(n);                                                    // adds next element if size of stack was exceded prior to resize
}


Stack::Stack(int n) : num(n), top(-1)
{
    array = new int[num];
}


Stack::~Stack()                
{
    try
    {
        if (NULL != array) 
        {
            delete array;                                       // deallocates heap memory locations
        }
    }
    catch(...) {}
}


void Stack::Push(int n)
{
    if (Capacity() == 0 || NULL == array)
    {
        throw StackFull();                                      // conditional for if there's nothing in the stack
    } 

    if (IsFull()) 
    {
        Resize(n);
    }
    else
    {
        top++;                                                  // increases size of stack to accomodate more values
        array[top] = n;                                         // adds new point of data onto the stack          
    }
}


void Stack::Pop()
{
    if (IsEmpty()) 
    {
        throw StackEmpty();                                     // conditional for if stack is empty
    }

    top--;                                                      // decreases size of stack and thus removes top most element
}


bool Stack::IsEmpty() const
{
    return (NULL == array || Size() <= 0) || (0 == Capacity());    // conditional if the top-most element of the stack is also the  bottem-most element
}


bool Stack::IsFull() const
{
    return Size() >= Capacity();                                // conditional if the top-most element of the stack is in the highest index possible of the stack 
}


void Stack::MakeEmpty()
{
    top = -1;                                                   // removes all elements of the stack
}


int Stack::Top() const
{
    if (IsEmpty())
    {
        throw StackEmpty();                                     // conditional for if nothing is in the stack at all
    }

    return array[top];                                          // returns top-most value of the stack w/o modifying said value
}


int Stack::Size() const
{
    return (top + 1);                                           // returns # of elements in the stack 
}


int Stack::Max() const
{
    if (IsEmpty())
    {
        throw StackEmpty();                                     // conditional for if nothing is in the stack at all
    }

    int MaxOfStack = 0;                                         // stdlib value for minimum integr (header file not allowed to be used)
    for (int i = 0; i < Size() && i < Capacity(); i++)          // for all values of the stack array that don't excede # elements and # of spaces on stack that can be occupied
    {
        MaxOfStack = std::max(MaxOfStack, Peek(i));             // using stdlib function for maxiumum value between current min. value and current element in the stack
    }

    return MaxOfStack;
}


int Stack::Min() const
{
    if (IsEmpty())
    {
        throw StackEmpty();                                     // conditional for if nothing is in the stack at all
    }

    int MinOfStack = 1000000000;                                // stdlib value for minimum integr (header file not allowed to be used)
    for (int i = 0; i < Size() && i < Capacity(); i++)          // for all values of the stack array that don't excede # elements and # of spaces on stack that can be occupied
    {
        MinOfStack = std::min(MinOfStack, Peek(i));             // using stdlib function for miniumum value between current min. value and current element in the stack
    }

    return MinOfStack;
}


int Stack::Peek(unsigned int n) const
{
    if (
        Size() <= 0                                             // The stack is empty, no peek is valid
        || n >= Size()                                          // The query is beyond the number of elements
        || n < 0                                                // Negative is invalid for an unsigned
    ) 
    {
        throw StackInvalidPeek();                                
    }

    return array[top - n];
}


int Stack::Capacity() const
{
    return num;
}
