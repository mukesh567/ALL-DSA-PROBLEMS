#include <bits/stdc++.h>
using namespace std;


void minheapify(int arr[], int i, int size)
{
    int smallest = i;
    int child1 = 2 * i + 1;
    int child2 = 2 * i + 2;

    if (child1 < size && arr[smallest] > arr[child1])
    {
        smallest = child1;
    }
    if (child2 < size && arr[smallest] > arr[child2])
    {
        smallest = child2;
    }

    if (smallest != i)
    {
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        minheapify(arr, smallest, size);
    }
}


void buildHeap(int arr[], int size)
{
    
    for (int i = size / 2; i >= 0; i--)
    {
        minheapify(arr, i, size);
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