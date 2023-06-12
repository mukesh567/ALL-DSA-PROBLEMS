
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
int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
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

    if (isBalanced(root2))
    {
        cout << "Balanced tree" << endl;
    }
    else
    {
        cout << "Not Balanced tree" << endl;
    }
    return 0;
}