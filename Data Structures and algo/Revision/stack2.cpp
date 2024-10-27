// Stacks using Linked List

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

class stack
{
    Node *head;
    int size;

public:
    stack()
    {
        head = NULL;
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

    void push(int element)
    {
        Node *n = new Node(element);

        if (head == NULL)
        {
            head = n;
        }

        else
        {
            n->next = head;
            head = n;
        }
        size++;
    }

    void pop()
    {
        if (head == NULL)
        {
            return;
        }

        head = head->next;
        size--;
    }

    void display()
    {
       if(head == NULL){
          cout << "Stack is Empty" << endl;
       }

       Node *temp = head;
       while(temp!= NULL){
         cout << temp -> data << " ";
         temp = temp -> next;
       } 
    }
};

int main()
{
    stack s;
    s.push(200);
    s.push(300);
    s.display();
    
    return 0;
}