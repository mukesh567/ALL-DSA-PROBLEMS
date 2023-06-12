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

int findPos(int inorder[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == element)
            return i;
    }
    return -1;
}

Node *solve(int preorder[], int inorder[], int &preOrderInd, int inorderStart, int inorderEnd, int n)
{
    // base case
    if (preOrderInd >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // preorder se ak value uthai
    int element = preorder[preOrderInd];
    preOrderInd++;

    // create nodes for this
    Node *root = new Node(element);

    // element ko inorder me search karne par
    int pos = findPos(inorder, element, n);

    // call for left
    root->left = solve(preorder, inorder, preOrderInd, inorderStart, pos - 1, n);

    //call for right
    root->right = solve(preorder, inorder, preOrderInd, pos + 1, inorderEnd, n);
    return root;
}

Node *buildTree(int preorder[], int inorder[], int n)
{
    // preorder starting index
    int preOrderInd = 0;

    Node *ans = solve(preorder, inorder, preOrderInd, 0, n - 1, n);
    return ans;
}

void postOrderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout << root->data << " ";
}
int main()
{
    int preorder[] = {1,6,8,7};
    int inorder[] = {1,6,7,8};

    int n = 4;

    Node *root = buildTree(preorder, inorder, n);
    postOrderPrint(root);
    return 0;
}