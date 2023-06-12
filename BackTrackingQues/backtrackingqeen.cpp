
#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // case 1 for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // case 2 for col me check karne ki jarurat nhi hai because ham
    // pehle se queen ko sahi col me place kar rhe hai

    // case 3 for same diagnol

    // for up daignol
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    // for down daignol
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    // solve one case rest of the case recursion will take care
    // ak col k liye saari rows me queen rakh k dekhne par

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // is palcing queen is safe
            board[row][col] = 1;
            // recursive call for next col
            solve(col + 1, ans, board, n);
            // back track karne par
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}

int main()
{
    int n;
    cout << "Enter the queen who you want to place : ";
    cin >> n;

    vector<vector<int>> ans = nQueen(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}