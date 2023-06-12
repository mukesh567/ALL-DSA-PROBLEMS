
//  * * * * * *
//  * * * * * *
//  * * * * * *

#include <bits/stdc++.h>
using namespace std;

void rectaPattern(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int row;
    cout << "Enter rows : ";
    cin >> row;

    int col;
    cout << "Enter colms : ";
    cin >> col;

    rectaPattern(row, col);
    return 0;
}