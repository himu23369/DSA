#include <iostream>
using namespace std;

#define MAX 10

class CircularQueue
{
    int queue[MAX];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if (front == -1 && rear == -1) // When the queue is empty
        {
            front = 0;
            rear = 0;
            queue[rear] = x;
        }

        else if (front == ((rear + 1) % MAX)) // When queue becomes full
        {
            cout << "Queue is full" << endl;
        }

        else
        {
            rear = (rear + 1) % MAX;
            queue[rear] = x;
        }

    }

    void dequeue()
    {
        if (front == rear == -1)
        {
            cout << "Underflow Condition" << endl;
        }

        else if (front == rear) // When only 1 element present in the queue
        {
            front = rear = -1;
        }

        else
        {
            front = (front + 1) % MAX;
        }
    }

    void display()
    {
        // cout << "Value of front = " << front << endl; 
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty" << endl;
        }

        else
        {
            for (int i = front; i != rear; i = (i + 1) % MAX)
            {
                cout << queue[i] << " ";
            }
            cout << queue[rear] << endl;
        }
    }
};

int main()
{
    CircularQueue c;
    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    c.dequeue();
    c.dequeue();
    c.dequeue();
    c.display();

    return 0;
}