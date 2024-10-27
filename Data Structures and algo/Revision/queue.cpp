// Queue implementation using array

#include <iostream>
using namespace std;

#define MAXLEN 100

struct queue
{
    int arr[MAXLEN];
    int front;
    int rear;
};

queue init()
{
    queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

bool isEmpty(queue q)
{
    return ((q.front == -1) || (q.front > q.rear));
}

bool isFull(queue q)
{
    return (q.rear == MAXLEN - 1);
}

int size(queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }

    return (q.rear - q.front) + 1;
}

int front(queue q)
{
    if (isEmpty(q) == 1)
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else
        return q.arr[q.front];
}

queue enqueue(queue q, int x)
{
    if (isFull(q))
    {
        cout << "OVERFLOW" << endl;
    }

    else if (isEmpty(q))
    {
        q.front = q.rear = 0;
        q.arr[q.rear] = x;
    }

    else
    {
        q.rear++;
        q.arr[q.rear] = x;
    }

    return q;
}

queue dequeue(queue q)
{
    if (isEmpty(q))
    {
        cout << "UNDERFLOW" << endl;
    }

    q.front++;
    return q;
}

void print(queue q)
{
    for (int i = q.front; i <= q.rear; i++)
    {
        cout << q.arr[i] << " ";
    }
}

int main()
{ 
    queue q;
    q = init();
    q = enqueue(q, 100);
    cout << size(q) << endl;
    q = enqueue(q, 200);
    q = enqueue(q, 300);
    q = dequeue(q);
    print(q);

    cout << "Front element is: " << front(q) << endl;
    cout << isEmpty(q) << endl;

    return 0;
}