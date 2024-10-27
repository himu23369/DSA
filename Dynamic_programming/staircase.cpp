#include <iostream>
using namespace std;

int ways(int n)
{
    cout << "Hello" << endl;
    int ans[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        cout << "Hello" << endl;
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    cout << "Hello" << endl;

    // ans[n] = ans[n] % (10 ^ 9 + 7);

    return ans[n];
    // delete []ans;
}

int main()
{
    // int n, t;
    // cout << "Enter the number of test cases to be run" << endl;
    // cin >> t;
    // for (int i = 0; i < 10; i++)
    // {
    // cout << "Enter number of steps" << endl;
    // cin >> n;
    for (int n = 1; n < 10; n++)
    {
        cout << "No. of ways are: " << ways(n) << endl;
    }

    return 0;
}
