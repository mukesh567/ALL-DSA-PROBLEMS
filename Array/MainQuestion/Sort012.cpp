
#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int start = 0;
    int mid = 0;
    int end = n - 1;

    while (mid <= end)
    {
        switch (a[mid])
        {

        case 0:
            swap(a[start++], a[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(a[mid], a[end--]);
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort012(arr, n);

    return 0;
}