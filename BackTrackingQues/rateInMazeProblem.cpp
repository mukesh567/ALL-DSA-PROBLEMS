
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &m, int n, vector<vector<int>> visited, int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    return false;
}

void solveMaze(vector<vector<int>> &m, int n, vector<vector<int>> visited,
               vector<string> &ans, int x, int y, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // mark visited
    visited[x][y] = 1;

    // Down
    int newX = x + 1;
    int newY = y;

    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('D');
        solveMaze(m, n, visited, ans, newX, newY, path);
        path.pop_back();
    }

    // Left
    newX = x;
    newY = y - 1;

    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('L');
        solveMaze(m, n, visited, ans, newX, newY, path);
        path.pop_back();
    }

    // Right
    newX = x;
    newY = y + 1;

    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('R');
        solveMaze(m, n, visited, ans, newX, newY, path);
        path.pop_back();
    }

    // Up
    newX = x - 1;
    newY = y;

    if (isSafe(m, n, visited, newX, newY))
    {
        path.push_back('U');
        solveMaze(m, n, visited, ans, newX, newY, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";

    if (m[0][0] == 0 || m[n-1][n-1]==0)
    {
        return ans;
    }

    solveMaze(m, n, visited, ans, 0, 0, path);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array  : ";
    cin >> n;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    vector<string> ans = ratInMaze(m, n);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}