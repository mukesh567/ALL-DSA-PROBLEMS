
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

bool isBalanced(Node *root, int *Height)
{
    if (root == NULL)
    {
        return true;
    }

    int leftHeight = 0, rightHeight = 0;
    if (isBalanced(root->left, &leftHeight) == false)
    {
        return false;
    }

    if (isBalanced(root->right, &rightHeight) == false)
    {
        return false;
    }
    
    *Height = max(leftHeight, rightHeight) + 1;
    if (abs(leftHeight - rightHeight) <= 1)
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // not balanced tree
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    int Height = 0;
    if (isBalanced(root2, &Height))
    {
        cout << "Balanced tree" << endl;
    }
    else
    {
        cout << "Not Balanced tree" << endl;
    }
    return 0;
}