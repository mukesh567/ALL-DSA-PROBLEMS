

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

void  inPre(node *root, node *&pre, int val)
{
    // base case
    if (root->data == val)
    {
        if (root->left != NULL)
        {
            node *temp = root->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }

            pre = temp;
        }
        return;
    }

    else if (root->data < val)
    {
        pre = root;
        inPre(root->right, pre, val);
    }
    
    else
    {
        inPre(root->left, pre, val);
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
    node *pre = NULL;

    root = insertBST(root, 50);
    insertBST(root, 15);
    insertBST(root, 37);
    insertBST(root, 44);
    insertBST(root, 23);
    insertBST(root, 70);

    cout << endl;
    inorder(root);
    cout << endl;

    inPre(root, pre, 23);

 if (pre != NULL)
    {
        cout << endl
             << "pre of given node is : " << pre->data << endl;
    }
    else
    {
        cout << endl
             << "pre does not exits : " << endl;
    }
    return 0;
}