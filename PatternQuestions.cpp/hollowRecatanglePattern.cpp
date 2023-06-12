

//  * * * * * *
//  *         *
//  * * * * * *

#include <bits/stdc++.h>
using namespace std;

void hollowRectaPattern(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
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

    hollowRectaPattern(row, col);
    return 0;
}