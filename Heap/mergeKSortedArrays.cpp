
#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    int i;
    int j;

    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
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

vector<int> mergeKsortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    // sabhi arrays k first elements uthane par means k
    for (int i = 0; i < k; i++)
    {
        node *tmp = new node(arr[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;
    while (minHeap.size() > 0)
    {
        node *tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if (j + 1 < arr[i].size())
        {
            node *next = new node(arr[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main()
{
    int k = 3;

    vector<vector<int>> arr{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> ans = mergeKsortedArrays(arr, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}