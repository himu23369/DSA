#include <iostream>
using namespace std;

// Diagonal Matrix

/*
int main()
{
    int n;
    cout << "Enter the n value for n*n matrix" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements for Diagonal Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
               cout << arr[i] << " ";
            }
            else
               cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

// Lower Triangular Matrix

/*
int main()
{

    int n;
    cin >> n;
    int size = ((n) * (n + 1)) / 2;
    int arr[size];

    cout << "Enter the elements for Lower Triangular Matrix" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int x = 0;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (j >= k)
            {
                cout << arr[x] << " ";
                x++;
            }
            else if(j < k)
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

// Upper Triangular Matrix

/*
int main()
{
    int n;
    cin >> n;
    int size = ((n) * (n + 1)) / 2;
    int arr[size];

    cout << "Enter the elements for Lower Triangular Matrix" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int x = 0;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (j <= k)
            {
                cout << arr[x] << " ";
                x++;
            }
            else if(j > k)
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

// Symmetric Matrix

int main()
{
    cout << "Enter the value of n for n*n matrix" << endl;
    int n;
    cin >> n;
    int size = ((n) * (n + 1)) / 2;
    int arr[size];

    cout << "Enter the elements for Symmetric Matrix" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int x = 0;
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size; k++)
        {
            if (j >= k)
            {
                cout << arr[x] << " ";
                x++;
            }
            else if(j < k){

            }
        }
    }

    return 0;
}
