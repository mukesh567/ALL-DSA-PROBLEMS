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
void flattenBinarytree(Node *root)
{
    Node *current = root;

    while (current != NULL)
    {
        if (current->left)
        {
            Node *pred = current->left;
            while (pred->right)
                pred = pred->right;
            
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        
        current = current->right;
    }
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flattenBinarytree(root);
    inorder(root);

    return 0;
}