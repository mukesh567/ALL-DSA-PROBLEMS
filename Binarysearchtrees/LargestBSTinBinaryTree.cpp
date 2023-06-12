

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

Info solve(node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    // call for left subtree
    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);

    Info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    // three condition check
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // update answer
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBSTinBT(node *root)
{
    int maxSize = 0;

    Info temp = solve(root, maxSize);
    return maxSize;
}
int main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout << "Largest BST in BT : size of : " << largestBSTinBT(root) << endl;

    return 0;
}