#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter n" << endl;
    cin >> n;

    char c[n];
    cout << "Enter the character array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int f[n];
    cout << "Enter the frequency array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }


   
    return 0;
}