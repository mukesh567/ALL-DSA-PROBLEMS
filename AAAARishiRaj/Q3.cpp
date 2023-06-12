
// Q3. write a program to delete an element from 1d array ?

#include <bits/stdc++.h>
using namespace std;

void delEle(int *arr, int n, int pos)
{
    if (pos >= n + 1)
        cout << "Deletion not possible."<<endl;
    else
    {
        for (int i = pos ; i < n - 1; i++)
            arr[i] = arr[i + 1];

        cout << "Array after deletion :";

        for (int i = 0; i < n - 1; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter arrays elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pos;
    cout << "Enter your position where you want to insert element : ";
    cin >> pos;

    delEle(arr, n, pos);
    return 0;
}