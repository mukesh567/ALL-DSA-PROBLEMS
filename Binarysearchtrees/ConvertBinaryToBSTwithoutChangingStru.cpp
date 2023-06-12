

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

void inorder(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void inorderToBSTSameStructure(node *root, vector<int> v, int &i)
{
    if (root == NULL)
    {
        return;
    }

    // call for left
    inorderToBSTSameStructure(root->left, v, i);

    // curr node
    //  replace value
    root->data = v[i];
    i++;

    // call for right
    inorderToBSTSameStructure(root->right, v, i);
}
node *convertBtToBst(node *root)
{
    vector<int> v;
    inorder(root, v);

    sort(v.begin(), v.end());

    int i = 0;
    inorderToBSTSameStructure(root, v, i);
    return root;
}

void  inorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);

    node* newRoot = convertBtToBst(root);
    inorderPrint(newRoot);

    return 0;
}