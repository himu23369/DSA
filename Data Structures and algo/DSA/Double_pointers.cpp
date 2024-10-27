#include <iostream>
using namespace std;

void increment(int **p)
{
    p=p+1;
    //No change reflected here in p
}


void increment(int **p)
{
    *p=*p+1;
    //Change will come in p
}

void increment(int **p)
{
   **p=**p+1; 
   //Change will come in p
}

int main()
{
    int i = 10;
    int *p = &i;
    int **p2 = &p;

    cout << p2 << endl;
    cout << &p << endl;

    cout << p << endl;
    cout << *p2 << endl;
    cout << &i << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

    return 0;
}