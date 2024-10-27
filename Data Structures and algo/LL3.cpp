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

Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        // else
        // {
        //     Node *temp = head;
        //     while (temp->next != NULL)
        //     {
        //         temp = temp->next;
        //     }
        //     temp->next = newNode;
        // }

        else{
            tail ->next = newNode;
            tail = newNode;
            //or tail = tail -> next;
        }
        //Now, Complexity becomes order of n i.e. O(n)
        cin >> data;
    }
    return head;
}
//With this , we are obtaining time complexity of n square because of while loop

void print(Node *head)
{
    Node *temp = head;
    // while (head->next != NULL)
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    
    // temp = head;
    // while (temp != NULL)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }
}

int main()
{
    Node *head = takeInput();
    print(head);

    return 0;
}