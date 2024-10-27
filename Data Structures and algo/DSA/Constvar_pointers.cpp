#include <iostream>
using namespace std;

// Const variable is useful during function calling

void g(int const &a)
{
    // a++;  Error bcos function is assuring me that it will not change the value and no need of making another copy
}

void f(const int *p)
{
    //(*p)++;  Error
}

int main()
{
    int const i = 10;
    /*int *p = &i;
    We cant store the address of constant integer into a normal pointer because you have only read only access and how can u give access to someone to change then.*/   
    int const *p = &i; // p is a pointer to a constant integer and so we can't change the value through this path as well
    
    int j = 12;
    int *p3 = &j;
    f(p3);
    g(j);

    int const *p2 = &j;
    cout << *p2 << endl;
    j++; // Ye kar skte hain bcos this is one path through which i am allowed to do so but i cant do (*p2)++
    cout << *p2 << endl;

    int a = 10;
    int b = 20;
    int const *q = &a;
    q = &b; // This is allowed
    /*q is pointing towards a constant integer mtlb p keh rha hai ki vo jis int ko point kr rha hai vo usse change nhi krega but
    vo khud toh change ho hi skta hai* but *q++ not allowed*/

    int *const r = &a; // r is constant pointer to a integer
    (*r)++;            // now we can modify the value
    /* (r = &b); this is wrong */

    /*int const*const t = &i;
    t= &j;
    (*t)++;*/
    //This is wrong and will show error

    return 0;
}