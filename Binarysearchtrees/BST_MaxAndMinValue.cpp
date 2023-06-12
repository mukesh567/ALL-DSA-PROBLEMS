

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

node *minValue(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *maxValue(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
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
    root = insertBST(root, 50);
    insertBST(root, 15);
    insertBST(root, 37);
    insertBST(root, 44);
    insertBST(root, 23);
    insertBST(root, 70);

    cout << endl;
    inorder(root);
    cout << endl;

    cout << endl;
    node *min = minValue(root);
    cout << "Minimum value of this bst is : " << min->data << endl;

    cout << endl;
    node *max = maxValue(root);
    cout << "Maximum value of this bst is : " << max->data << endl;
    cout << endl;
    return 0;
}