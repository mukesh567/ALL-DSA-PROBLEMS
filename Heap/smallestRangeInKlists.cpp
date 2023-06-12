
#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    int row;
    int col;

    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

pair<int, int> findSmallestRange(vector<vector<int>> &KSortedArray, int n, int k)
{

    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node *, vector<node *>, compare> minHeap;

    // harek array ka first element dalne or max and min update karne par
    for (int i = 0; i < k; i++)
    {
        int element = KSortedArray[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    // abhi tak k max or min
    int start = mini;
    int end = maxi;

    while (!minHeap.empty())
    {
        node *temp = minHeap.top();
        minHeap.pop();

        // min nikalne par
        mini = temp->data;

        // answer update karne par
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // agar jis bhi row par hai uska agla element extis kare to
        if (temp->col + 1 < n)
        {
            // max ko update karne par
            maxi = max(maxi, KSortedArray[temp->row][temp->col + 1]);
            minHeap.push(new node(KSortedArray[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            break;
        }
    }

    return {start, end};
}

int main()
{
    int n = 5, K = 3;

    vector<vector<int>> KSortedArray{
        {1, 3, 5, 7, 9},
        {0, 2, 4, 6, 8},
        {2, 3, 5, 7, 11}};

    pair<int, int> ans = findSmallestRange(KSortedArray, n, K);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}