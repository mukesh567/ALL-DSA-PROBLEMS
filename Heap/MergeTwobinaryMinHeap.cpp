


#include <bits/stdc++.h>
using namespace std;
void minheapify(vector<int> &arr, int i, int size)
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
void buildHeap(vector<int> &arr, int size)
{

    for (int i = size / 2; i >= 0; i--)
    {
        minheapify(arr, i, size);
    }
    return;
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b)
{
    // step-1;  merge two arrays
    vector<int> ans;
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    //step-2; merging array to create minHeap
    int size = ans.size();
    buildHeap(ans, size);

    return ans;
}

int main()
{
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};

    vector<int> ans = mergeHeaps(arr1, arr2);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}