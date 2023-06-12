

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

node *insertBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inSucc(node *root, node *&succ, int val)
{
    // base case
    if (root->data == val)
    {
        if (root->right != NULL)
        {
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }

    else if (root->data < val)
    {
        inSucc(root->right, succ, val);
    }

    else
    {
        succ = root;
        inSucc(root->left, succ, val);
    }
}

void inorder(node *root)
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
    node *root = NULL;
    node *succ = NULL;

    root = insertBST(root, 50);
    insertBST(root, 15);
    insertBST(root, 37);
    insertBST(root, 44);
    insertBST(root, 23);
    insertBST(root, 70);

    cout << endl;
    inorder(root);
    cout << endl;

    inSucc(root, succ, 50);

    if (succ != NULL)
    {
        cout << endl
             << "Succ of given node is : " << succ->data << endl;
    }

    else
    {
        cout << endl
             << "Succ does not exits : " << endl;
    }

    return 0;
}