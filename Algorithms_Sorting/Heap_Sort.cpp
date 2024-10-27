// 2 steps for this:
// Build a max heap or a min heap and remove the data one by one

#include <iostream>
using namespace std;

void heapSort(int pq[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }

            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int size = n;

    while (size > 1)
    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;

        int pI = 0;
        int lcI = 2 * pI + 1;
        int rcI = 2 * pI + 2;

        while (lcI < size)
        {
            int minIndex = pI;

            if (pq[minIndex] > pq[lcI])
            {
                minIndex = lcI;
            }

            if (pq[minIndex] > pq[rcI] && rcI < size)
            {
                minIndex = rcI;
            }

            if (minIndex == pI)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[pI];
            pq[pI] = temp;

            pI = minIndex;
            lcI = 2 * pI + 1;
            rcI = 2 * pI + 2;
        }
    }
}

int main()
{

    int arr[] = {2, 1, 3, 4, 6};
    heapSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}