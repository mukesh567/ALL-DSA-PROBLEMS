
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

int solve(Node *&node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = solve(node->left);
    int right = solve(node->right);

    int old_value = node->data;

    node->data = left + right;
    return node->data + old_value;
}


void toSumTree(Node *node)
{
    solve(node);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    inorder(root);
    cout << "\n";
    toSumTree(root);
    inorder(root);
    cout << "\n";

    return 0;
}