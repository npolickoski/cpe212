#include "stack.h"

void Stack::Resize(int n)
{
    try {
        int* newArrayPtr = new int[2*num];
        array = newArrayPtr;
        num *= 2;
    } catch(...) {
        throw StackFull();
    }

    Push(n);
}

Stack::Stack(int n) : array(nullptr), num(0), top(-1)
{
    Resize(n);
}

Stack::~Stack()
{
    try {
        if (nullptr != array) {
            delete array;
        }
    } catch(...) {}
}

void Stack::Push(int n)
{
    // In the unlikely case that you instantiate the class with 0 for n
    if (Capacity() == 0 || nullptr == array) throw StackFull();

    if (IsFull()) {
        Resize(n);
    }
    else {
        top++;
        array[top] = n;
    }
}

void Stack::Pop()
{
    if (IsEmpty()) throw StackEmpty();
    top--;
}

bool Stack::IsEmpty() const
{
    return (nullptr == array) || (top < 0) || (0 == Capacity());
}

bool Stack::IsFull() const
{
    return top >= Capacity() - 1;
}

void Stack::MakeEmpty()
{
    top = -1;
}

int Stack::Top() const
{
    if (IsEmpty()) throw StackEmpty();

    return array[top];
}

int Stack::Size() const
{
    return top+1;
}

int Stack::Max() const
{
    if (IsEmpty()) throw StackEmpty();

    int maxSeen = INT_MIN;
    for (int i = 0; i <= top && i <= Capacity(); i++) {
        try {
            maxSeen = std::max(maxSeen, Peek(i));
        }
        catch (StackInvalidPeek&) {}
    }
    return maxSeen;
}

int Stack::Min() const
{
    if (IsEmpty()) throw StackEmpty();

    int minSeen = INT_MIN;
    for (int i = 0; i <= top; i++) {
        try {
            minSeen = std::min(minSeen, Peek(i));
        }
        catch (StackInvalidPeek&) {}
    }
    return minSeen;
}

int Stack::Peek(unsigned int n) const
{
    // Protect against stack overflow verifying greater than 0
    if (top < 0 || n > top || n < 0) throw StackInvalidPeek();
    return array[top-n];
}

int Stack::Capacity() const
{
    return num;
}
