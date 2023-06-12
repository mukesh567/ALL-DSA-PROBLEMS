
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[100], pos, n;

    cout << "Enter the number of elements of the array :";
    cin >> n;

    cout << "\nInput the array elements : ";

    for (int i = 0; i < n; i++)
        cin >> array[i];

    cout << "\nEnter the position :";
    cin >> pos;

    if (pos >= n + 1)
        cout << "\nDeletion not possible.\n";
    else
    {
        for (int i = pos - 1; i < n - 1; i++)
            array[i] = array[i + 1];

        cout << "\nArray after deletion :";

        for (int i = 0; i < n - 1; i++)
            cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}