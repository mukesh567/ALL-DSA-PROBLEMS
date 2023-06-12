
#include <bits/stdc++.h>
using namespace std;

void ReverseArray(int arr[], int n, int pos)
{
    int start = pos, end = n - 1;

    while (start <= end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {11, 7, 3, 12, 4};
    int position = 2;
    cout << "After that Position reverse the array : ";
    ReverseArray(arr, 5, 2);
    return 0;
}