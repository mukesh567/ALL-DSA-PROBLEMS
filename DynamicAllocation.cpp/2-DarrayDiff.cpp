

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    int n;
    cin >> n;

    // creating mamory
    int **arr = new int *[m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    // taking inputs
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // print outputs
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // realising mamory
    for (int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}