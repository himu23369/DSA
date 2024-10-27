#include <iostream>
using namespace std;

int reverse(int x)
{
    int ans = -1;
    int p = 1;
    int y = x;

    while (y != 0)
    {
        y = x % 10;
        ans += p * y;
        p = p * 10;
    }

    return ans;
}

int main(){
  
    int x;
    cout << "Enter x: " << endl; 
    cin >> x; 

    cout << reverse(x);
}
