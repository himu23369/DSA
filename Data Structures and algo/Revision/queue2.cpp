// Using LinkedList

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {
        Node *n = new Node(data);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }

        else
        {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "EMPTY" << endl;
        }

        else
        {
            head = head->next;
            size--;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp!= NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.dequeue();
    q.display();

    return 0;
}