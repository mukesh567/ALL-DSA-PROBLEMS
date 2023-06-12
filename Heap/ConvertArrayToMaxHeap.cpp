
#include <bits/stdc++.h>
using namespace std;

void maxheapify(int arr[], int i, int size)
{
    int largest = i;
    int child1 = 2 * i + 1;
    int child2 = 2 * i + 2;

    if (child1 < size && arr[largest] < arr[child1])
    {
        largest = child1;
    }

    if (child2 < size && arr[largest] < arr[child2])
    {
        largest = child2;
    }

    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxheapify(arr, largest, size);
    }
}

void buildHeap(int arr[], int size)
{

    for (int i = size / 2; i >= 0; i--)
    {
        maxheapify(arr, i, size);
    }

    return;
}

int main()
{
    int arr[] = {19, 1, 2, 3, 36, 25, 100, 17, 7};
    buildHeap(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}