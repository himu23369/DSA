#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int value, weight;

    Item()
    {
        value = 0;
        weight = 0;
    }

    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double p = (double)a.value / (double)a.weight;
    double q = (double)b.value / (double)b.weight;
    return p > q;
}

double fractionalKnapsack(int w, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    double value = 0.0;
    double current_capacity = w;

    for (int i = 0; i < n; i++)
    {
        if (current_capacity > 0)
        {
            if (arr[i].weight <= current_capacity)
            {
                value += (double)arr[i].value;
                current_capacity -= (double)arr[i].weight;
                cout << "For iteration " << i + 1 << ": value is " << value << " & "
                     << "current_capacity is " << current_capacity << endl;
            }
            else
            {
                value += ((current_capacity) / (double)(arr[i].weight)) * (double)arr[i].value;
                current_capacity = 0;
            }
        }
        else
        {
            break;
        }
    }
    return value;
}

int main()
{
    int w;
    cout << "Enter the maximum weight of the bag" << endl;
    cin >> w;

    int n;
    cout << "Enter the number of items present to fill the bag" << endl;
    cin >> n;

    Item arr[n];
    cout << "Enter the value and weights" << endl;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        Item p(v, w);

        arr[i] = p;
    }

    cout << "Maximum value that can be obtained is: " << fractionalKnapsack(w, arr, n);

    return 0;
}

// for(int i = 0; i < n; i++){
//     cout << arr[i].value << " " << arr[i].weight << endl;
// }