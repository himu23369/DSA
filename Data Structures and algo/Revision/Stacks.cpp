// Implementation of stack using static arrays

#include <iostream>
using namespace std;

#define MAXLEN 100

typedef struct
{
    int arr[MAXLEN];
    int topIndex;
} stack;

stack init()
{
    stack s;
    s.topIndex = -1;
    return s;
}

int isEmpty(stack s)
{
    return s.topIndex == -1;
}

int isFull(stack s)
{
    return s.topIndex == MAXLEN - 1;
}

int top(stack s)
{
    if (isEmpty(s))
    {
        cout << "Underflow Condition i.e. Stack is empty" << endl;
    }

    return s.arr[s.topIndex];
}

stack push(stack s, int data)
{
    if (isFull(s))
    {
        cout << "Overflow Condition i.e. stack is full" << endl;
    }
    s.topIndex++;
    s.arr[s.topIndex] = data;

    return s;
}

stack pop(stack s)
{
    if (isEmpty(s))
    {
        cout << "UnderFlow Condition" << endl;
    }
    s.topIndex--;

    return s;
}

void print(stack s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty" << endl;
    }

    for (int i = s.topIndex; i >= 0; i--)
    {
        cout << s.arr[i] << " ";
    }
}

int main()
{
    stack s;
    s = init();
    s = push(s, 10);
    s = push(s, 20);
    s = push(s, 30);
    cout << top(s) << endl;
    print(s);

    return 0;
}