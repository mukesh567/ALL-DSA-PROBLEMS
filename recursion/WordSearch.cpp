

#include <bits/stdc++.h>
using namespace std;

bool search(int i, int j, int n, int m, vector<vector<char>> &board, string &word, int k)
{
    // k is donoting char of word string
    if (k == word.size())
        return true;

    // Boundary cond
    if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
        return false;

    // geg aise word ko handle karne k liye g do baar traverse ho rha hai
    // ak baar traverse karne k baad vaha koi random char dalne par
    char ch = board[i][j];
    board[i][j] = '#';

    // All four direction
    // Down
    bool op1 = search(i + 1, j, n, m, board, word, k + 1);

    // right
    bool op2 = search(i, j + 1, n, m, board, word, k + 1);

    // up
    bool op3 = search(i - 1, j, n, m, board, word, k + 1);

    // left
    bool op4 = search(i, j - 1, n, m, board, word, k + 1);

    board[i][j] = ch;

    return op1 || op2 || op3 || op4;
}

bool isWordExist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // agar first char match huya to aage search karnege
            if (board[i][j] == word[0])
            {
                if (search(i, j, n, m, board, word, 0))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'a', 'g', 'b', 'c'},
                                  {'q', 'e', 'e', 'l'},
                                  {'g', 'b', 'k', 's'}};

    string word = "geeks";

    if (isWordExist(board, word))
    {
        cout << "Your word is exist in board array !" << endl;
    }
    else
    {
        cout << "Not exist !" << endl;
    }

    return 0;
}