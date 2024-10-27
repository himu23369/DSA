#include <iostream>
using namespace std;

int main()
{
    // const int
    const int i = 10;
    int const i2 = 10; // another way of writing

    // const ref from a non const int
    int j = 12;
    const int &k = j;
    j++;
    /* k++ will give error : non modifiable value*/
    cout << k << endl;

    //constant ref from const int 
    int const j2 = 12;
    int const &k2=j2;

    // reference from a const int
    int const j3 = 123;
    /*int &k3 = j3;
    k3++ is incorrect becos jo ham sirf read kar skte hain vo koi aur write kese kr skta hai */



    return 0;
}