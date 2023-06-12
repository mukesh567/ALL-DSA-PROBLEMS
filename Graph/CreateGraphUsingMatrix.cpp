
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    vector<vector<int>> adjM(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adjM[x][y] = 1;
        adjM[y][x] = 1;
    }

    cout << "Adjacency Matrix are::" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjM[i][j] << " ";
        }
        cout << endl;
    }

    // if (adjM[3][7] == 1)
    // {
    //     cout << "There is a edge between 3 and 7" << endl;
    // }
    // else
    // {
    //     cout << "No edge in between! " << endl;
    // }
    return 0;
}