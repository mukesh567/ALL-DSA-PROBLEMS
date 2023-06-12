

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

int countNodes(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCompleteBinaryTree(node *root, int index, int count)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    // agar index number of nodes se bahar chala jaye
    if (index >= count)
    {
        return false;
    }

    else
    {
        bool left = isCompleteBinaryTree(root->left, 2 * index + 1, count);
        bool right = isCompleteBinaryTree(root->right, 2 * index + 2, count);

        return left && right;
    }
}

bool isMaxHeap(node *root)
{
    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    // only left child exits
    if (root->right == NULL)
    {
        return root->data > root->left->data;
    }
    else
    {

        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

bool isHeap(node *root)
{
    // first value of 0th index
    int index = 0;

    // sabhi nodes ka count nikalne par
    int totalCountOfNodes = countNodes(root);

    // agar complete binary tree and maxHeap ho to return true
    if (isCompleteBinaryTree(root, index, totalCountOfNodes) && isMaxHeap(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(3);

    // complete binary tree or maxHeap ki property ko satisfy kare to
    // this will be our answer

    if (isHeap(root))
    {
        cout << endl
             << "This binary tree is a Heap !" << endl;
    }
    else
    {
        cout << endl
             << "Not a heap ! " << endl;
    }

    return 0;
}