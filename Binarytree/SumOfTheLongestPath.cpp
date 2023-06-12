
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void solve(Node *root, int len, int &maxLen, int sum, int &maxSum)
{
    // base case
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    // first store roots data
    sum += root->data;

    // call for left
    solve(root->left, len + 1, maxLen, sum, maxSum);

    // call for right
    solve(root->right, len + 1, maxLen, sum, maxSum);
}

int sumOflongestPath(Node *root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;
    solve(root, len, maxLen, sum, maxSum);

    return maxSum;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    cout << "The longest path whose sum is : " << sumOflongestPath(root) << endl;

    return 0;
}