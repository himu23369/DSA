#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
        return fibo(n - 1) + fibo(n - 2);
}
//Time Complexity here is order of 2^n(Brute Force Method)

/*****************************************************************/

int fibo_helper(int n, int *ans){
    if(n <= 1){
       return n;
    }
    if(ans[n] != -1){
       return ans[n];
    }

    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);

    ans[n] = a + b;

    return ans[n];
}

int fibo_2(int n){
    int *ans = new int[n + 1]; //Dyanmic Array created

    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }

    return fibo_helper(n, ans);
}
//So, here unique calls are n+1 and total work done is (n+1)k
//Time Complexity will be O(n)
//This process is known as MEMOZIATION(Top Down approach in which we store the previous results for future use.)

/*****************************************************************/

int fibo_3(int n){
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i <= n; i++){
       ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n]; 
}
//(Dynamic Programming)(bottom up)
//Time Complexity --> O(n)

//DP is generally iterative and Memoziation is Recursive

/*****************************************************************/

int main()
{
    int n;
    cout << "Enter the Fibonacci number you want" << endl;
    cin >> n;

    cout << fibo_2(n) << "==" << fibo_3(n);

    return 0;
}