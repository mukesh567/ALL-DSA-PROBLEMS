
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
bool isBST(node *root, int min,int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool leftvalid = isBST(root->left, min, root->data);
        bool rightvalid = isBST(root->right, root->data, max);

        return leftvalid && rightvalid;
    }
    
    return false;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    // node *root = new node(5);
    // root->left = new node(2);
    // root->right = new node(8);
    if (isBST(root, INT_MIN, INT_MAX))
    {
        cout << "valid BST !";
    }
    else
    {
        cout << "invalid BST !";
    }

    return 0;
}