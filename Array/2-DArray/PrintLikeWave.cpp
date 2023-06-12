
#include <bits/stdc++.h>
using namespace std;

void printLikeWaveis(int arr[][3], int m, int n)
{

// i=row
// j=col

    for (int j = 0; j < n; j++)
    {

        if (j & 1)
        {
            // if col odd than row print bottom to top

            for (int i = m - 1; i >= 0; i--)
            {

                cout << arr[i][j] << " ";
            }
        }
        else
        {
            // if col even than row print top to bottom
            for (int i = 0; i < m; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        
    }
   
}

void printArray(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {1, 5, 3, 2, 4, 6, 8, 9, 10};

    cout << endl;
    cout << "The array is : " << endl;
    printArray(arr);

    cout << endl;
    cout<<"Wave wise print array is : ";
    printLikeWaveis(arr, 3, 3);

    return 0;
}