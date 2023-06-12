

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

node *insertBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int countNodesRange(node *root, int low, int upp)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data >= low && root->data <= upp)
    {
        return 1 + countNodesRange(root->left, low, upp) + countNodesRange(root->right, low, upp);
    }
    else if (root->data < low)
    {
        return countNodesRange(root->right, low, upp);
    }
    else
    {
        return countNodesRange(root->left, low, upp);
    }
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 10);
    insertBST(root, 5);
    insertBST(root, 50);
    insertBST(root, 1);
    insertBST(root, 40);
    insertBST(root, 100);

    int lowerBound = 5;
    int upperBound = 45;

    cout << endl
         << endl
         << "Number of nodes in given range is : " << countNodesRange(root, lowerBound, upperBound) << endl
         << endl;

    return 0;
}