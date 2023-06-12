
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int *arr, int size, int key)
{
    // base case

    if (size == 0)
    {
        return false;
    }

    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return linearSearch(arr + 1, size - 1, key);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter your key : ";
    cin >> key;

    
    if (linearSearch(arr, size, key))
    {
        cout << "Element are found ! " << endl;
    }
    else
    {
        cout << "Element are not found ! " << endl;
    }
    return 0;
}