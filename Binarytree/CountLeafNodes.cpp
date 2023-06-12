
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

void inorder(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, count);

    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    inorder(root->right, count);
}

int CountLeaf(node *root)
{

    int count = 0;
    inorder(root, count);
    return count;
}

int main()
{
    node *root = new node(20);
    root->left = new node(10);
    root->right = new node(35);
    root->left->left = new node(5);
    root->left->right = new node(15);
    root->left->right->left = new node(53);
    root->right->left = new node(30);
    root->right->right = new node(42);

    cout << CountLeaf(root) << endl;

    return 0;
}