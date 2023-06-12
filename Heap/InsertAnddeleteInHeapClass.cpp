
#include <bits/stdc++.h>
using namespace std;

class heap
{

public:
    int arr[100];
    int size;

    // constructer
    heap()
    {
        size = 0;
    }

    void insert(int val)
    {
        // time com:  O(logn)
        size = size + 1;
        int index = size;

        arr[index] = val;

        // ab ese isko sahi position par le jana hai

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete ! " << endl;
            return;
        }

        // last element ko root me dalne par
        arr[1] = size;

        // last ko delete karne par
        size--;

        // jo root node hai vo sahi position par hai ya nhi
        // max heap me maximum hona chahiye

        // our new root node
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < rightIndex)
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    return 0;
}