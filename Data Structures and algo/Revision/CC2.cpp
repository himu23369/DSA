// Using Linked List

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

class CircularQueue
{
    Node *head;
    Node *tail;

public:
    CircularQueue()
    {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int data)
    {
        // cout << "Called" << endl;
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
            tail->next = head;
        }

        tail->next = n;
        tail = n;
        tail->next = head;
    }

    void dequeue()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete temp;
        }
        else
        {
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void display()
    {
        if(head == NULL){
           cout << "Queue is empty" << endl;
        }

        if(head == tail){
            cout << head -> data;
        }

        Node *temp = head -> next;
        cout << head -> data << " ";
        while (temp != head)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
};

int main()
{
    CircularQueue c;
    c.enqueue(100);
    c.enqueue(200);
    c.enqueue(300);
    c.enqueue(400);
    c.enqueue(500);
    c.dequeue();

    c.display();
     
    return 0;
}