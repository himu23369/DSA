#include <iostream>
using namespace std;

int countFibo = 0;
int countFibo2 = 0;
int countFibo3 = 0;

//Brute force approach
int fibo(int n)
{
    countFibo++;
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int fibo2_helper(int *ans, int n)
{
    countFibo2++;

    if (n <= 1)
    {
        ans[n] = n;
        return n;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int a = fibo2_helper(ans, n - 1);
    int b = fibo2_helper(ans, n - 2);

    // Saving output for future use
    ans[n] = a + b;

    return ans[n];
}

// Concept of Memoization which is a top down approach in which we save our answers to use them in future
int fibo_2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fibo2_helper(ans, n);
}
// Complexity of fibo is 2^n and of fibo_2 is n

// Iterative approach
//Dynamic Programming(bottom-up)
int fibo_3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        countFibo3++;
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}
//Best posssible solution to choose
//Time complexity is n

int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "fibo function called " << countFibo << " times" << endl;
    cout << fibo(n) << endl;
    cout << "fibo_2 function called " << countFibo2 << " times" << endl;
    cout << fibo_2(n) << endl;
    cout << "fibo_3 function called " << countFibo3 << " times" << endl;
    cout << fibo_3(n) << endl;

    return 0;
}