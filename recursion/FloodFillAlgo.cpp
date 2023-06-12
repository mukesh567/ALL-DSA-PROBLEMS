
#include <bits/stdc++.h>
using namespace std;

void flood(int i, int j, vector<vector<int>> &image, int &oldColor, int &newColor, int n, int m)
{
    if (i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor)
        return;

    image[i][j] = newColor;

    // down
    flood(i + 1, j, image, oldColor, newColor, n, m);

    // up
    flood(i - 1, j, image, oldColor, newColor, n, m);

    // right
    flood(i, j + 1, image, oldColor, newColor, n, m);

    // left
    flood(i, j - 1, image, oldColor, newColor, n, m);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{

    int oldColor = image[x][y];

    if (oldColor == newColor)
        return image;

    int n = image.size();
    int m = image[0].size();

    flood(x, y, image, oldColor, newColor, n, m);

    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};

    int x = 1;
    int y = 1;
    int newColor = 2;

    vector<vector<int>> ans = floodFill(image, x, y, newColor);

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