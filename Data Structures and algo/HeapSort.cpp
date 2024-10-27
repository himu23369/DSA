#include <iostream>
using namespace std;

void inplaceHeapSort(int pq[], int n)
{
    // Building the heap in input array(Process used -> Up-Heapify)
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
    // Till here we have only created our heap(Sorting to be done)
    // Now, we will call remove function n times to get our array in sorted order.
    // Process used -> Down-Heapify

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
    int arr[] = {5,1,2,0,8};
    inplaceHeapSort(arr,5);

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}