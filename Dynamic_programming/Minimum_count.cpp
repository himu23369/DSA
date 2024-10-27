#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}

int minCount(int n)
{

    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;
    int ans = n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        ans = min(ans, 1 + minCount(n - i * i));
    }

    return ans;
}