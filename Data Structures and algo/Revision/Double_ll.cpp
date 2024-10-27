//Double Linked List

#include <iostream>
using namespace std;

struct node
{
    int val;
    node *prev;
    node *next;
};

node *head = NULL;
node *temp;

void create();
void insert(int);
void show();
void insert_beg();
void insert_mid(int);
node *find(int);
void insert_end();
void delete_beg();
void delete_end();

int main()
{
    int num = 0;
    cout << "Enter the intial value";
    create();
    while (num != 8)
    {
        cout << "Enter the choice" << endl
             << "1. Insert" << endl
             << "2. Show" << endl
             << "3. Insert at begning" << endl
             << "4. Insert in middle" << endl
             << "5.Insert at End" << endl
             << "6. delete end" << endl
             << "7. delete begning" << endl
             << "8. End" << endl;

        cin >> num;
        switch (num)
        {
        case 1:
            int data;
            cout << "Enter data" << endl;
            cin >> data;
            insert(data);
            break;
        case 2:
            show();
            break;
        case 3:
            insert_beg();
            break;
        case 4:
            int bata;
            cin >> bata;
            insert_mid(bata);
            break;
        case 5:
            insert_end();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_beg();
            break;
        case 8:
            break;
            break;
        default:
            cout << "Enter correct value" << endl;
        }
    }
    return 0;
}

void create()
{
    if (head == NULL)
    {
        head = new node;
        cin >> head->val;
        head->next = NULL;
        head->prev = NULL;
        temp = head;
    }
}

void insert(int data)
{
    temp->next = new node;
    temp->next->prev = temp;
    temp = temp->next;
    temp->val = data;
    temp->next = NULL;
    cout << "Data added Succesfully!" << endl;
}
void show()
{
    node *ptr = head;
    while (ptr)
    {
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
    delete[] ptr;
}

void insert_beg()
{
    if (head != NULL)
    {

        node *ptr = new node;
        cin >> ptr->val;
        ptr->prev = NULL;
        head->prev = ptr;
        ptr->next = head;
        head = ptr;
    }
    else
        create();
}

node *find(int data)
{
    node *ptr = head;
    while (ptr)
    {
        if (ptr->val == data)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void insert_mid(int data)
{
    node *str = find(data);
    if (str)
    {
        node *ptr = new node;
        int abc;
        cout << "Enter the value" << endl;
        cin >> abc;
        ptr->val = abc;
        ptr->next = str->next;
        str->next->prev = ptr;
        ptr->prev = str;
        str->next = ptr;
        cout << "data added Succesfully!" << endl;
    }
    else
    {
        cout << "Entry not found" << endl;
    }
}

void insert_end()
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    temp->next = new node;
    temp->next->val = data;
    temp->next->prev = temp;
    temp->next->next = NULL;
    temp = temp->next;
    cout << "Data added Succesfully!" << endl;
}

void delete_beg()
{
    node *p = head;
    head = head->next;
    head->prev = NULL;
    delete[] p;
}

void delete_end()
{
    node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    temp = ptr;
    delete[] ptr->next;
    temp->next = NULL;
}