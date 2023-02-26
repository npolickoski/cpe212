
#include <iostream>
#include <new>
#include "stack.h"

void Stack::Resize(int n)
{
    size_t new_size = 2*num;                            // creates variable for doubling stack size

    int* newArrayPtr = new int[new_size];               // heap memory allocation for new array
    for(size_t i = 0; i < top; i++) 
    {
        newArrayPtr[i] = array[i];
    }

    array = newArrayPtr;                                // relocates new array back to original array but with size change
    num = new_size;                                     // changes max size of the array to the doubled size

    Push(n);                                            // adds next element if size of stack was exceded prior to resize
}


Stack::Stack(int n)
{
    array = new int[num];
}


Stack::~Stack()                 // in-progress
{
    if (nullptr != array) 
    {
        delete array;
    }
}


void Stack::Push(int n)
{
    top++;                                              // increases size of stack to accomodate more values
    array[top] = n;                                     // adds new point of data onto the stack          
}


void Stack::Pop()
{
    top--;                                              // decreases size of stack and thus removes top most element
}


bool Stack::IsEmpty() const
{
    return (Size() <= 0) || (0 == Capacity());;         // conditional if the top-most element of the stack is also the  bottem-most element
}


bool Stack::IsFull() const
{
    return Size() >= Capacity();                        // conditional if the top-most element of the stack is in the highest index possible of the stack 
}


void Stack::MakeEmpty()
{
    top = -1;                                           // removes all elements of the stack
}


int Stack::Top() const
{
    return array[top];                                  // returns top-most value of the stack w/o modifying said value
}


int Stack::Size() const
{
    return (top + 1);                                   // returns # of elements in the stack 
}


int Stack::Max() const
{
    int MaxOfStack = INT_MIN;                           // stdlib value for minimum integr

    for (int i = 0; i < Size() && i < Capacity(); i++)  // for all values of the stack array that don't excede # elements and # of spaces on stack that can be occupied
    {
        MaxOfStack = std::max(MaxOfStack, Peek(i));     // using stdlib function for maxiumum value between current min. value and current element in the stack
    }

    return MaxOfStack;
}


int Stack::Min() const
{
    int MinOfStack = INT_MIN;                           // stdlib value for minimum integr

    for (int i = 0; i < Size() && i < Capacity(); i++)  // for all values of the stack array that don't excede # elements and # of spaces on stack that can be occupied
    {
        MinOfStack = std::min(MinOfStack, Peek(i));     // using stdlib function for miniumum value between current min. value and current element in the stack
    }

    return MinOfStack;
}


int Stack::Peek(unsigned int n) const
{
    return array[top - n];
}


int Stack::Capacity() const
{
    return num;
}
