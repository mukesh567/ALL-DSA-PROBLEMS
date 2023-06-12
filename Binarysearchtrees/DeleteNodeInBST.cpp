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
node *minValue(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *deleteInBST(node *root, int key)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == key)
    {
        // if 0 child exits
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // if 1 child extis from both side .....ak baar left and than right
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // if 2 child extis from both side
        if (root->left != NULL && root->right != NULL)
        {
            node *min = minValue(root->right);
            root->data = min->data;
            root->right = deleteInBST(root->right, min->data);
            return root;
        }
    }

    else if (root->data < key)
    {
        root->right = deleteInBST(root->right, key);
        return root;
    }
    else
    {
        root->left = deleteInBST(root->left, key);
        return root;
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return ;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    cout << "Before deletion : ";
    inorder(root);
    cout << endl;

    root = deleteInBST(root, 5);

    cout << "After deletion : ";
    inorder(root);
    cout << endl;

    return 0;
}