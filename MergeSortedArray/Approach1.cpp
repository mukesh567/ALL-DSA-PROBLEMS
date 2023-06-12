
#include <bits/stdc++.h>
using namespace std;

void MergeArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i--], arr2[j++]);
        }
        else
        {
            j++;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main()
{
    vector<int> arr1 = {2, 4, 5, 6};
    vector<int> arr2 = {1, 3, 7};

    MergeArrays(arr1, arr2);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    for (int j = 0; j < arr2.size(); j++)
    {
        cout << arr2[j] << " ";
    }
    cout << endl;
    return 0;
}