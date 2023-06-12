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

Node *solve(int postOrder[], int inorder[], int &postOrderInd, int inorderStart, int inorderEnd, int n)
{
    // base case
    if (postOrderInd <0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // postOrder se ak value uthai
    int element = postOrder[postOrderInd];
    postOrderInd--;

    // create nodes for this
    Node *root = new Node(element);

    // element ko inorder me search karne par
    int pos = findPos(inorder, element, n);

    // call for right
    root->right = solve(postOrder, inorder, postOrderInd, pos + 1, inorderEnd, n);

    // call for left
    root->left = solve(postOrder, inorder, postOrderInd, inorderStart, pos - 1, n);
    return root;
}

Node *buildTree(int postOrder[], int inorder[], int n)
{
    // preorder starting index
    int postOrderInd = n - 1;

    Node *ans = solve(postOrder, inorder, postOrderInd, 0, n - 1, n);
    return ans;
}

void preorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
int main()
{
    int postOrder[] = {5,9,3,4,2};
    int inorder[] = {9,5,2,3,4};

    int n = 5;

    Node *root = buildTree(postOrder, inorder, n);
    preorderPrint(root);
    return 0;
}