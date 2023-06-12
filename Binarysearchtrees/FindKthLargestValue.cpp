

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

int KthLargest(node *root, int &count, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    // inorder traversal karenge
    // left call
    int right = KthLargest(root->right, count, k);
    if (right != -1)
    {
        return right;
    }

    // than root node
    count++;
    if (count == k)
    {
        return root->data;
    }

    // than right call
    return KthLargest(root->left, count, k);
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
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    inorder(root);
    cout << endl;

    int count = 0;
    int k = 3;

    cout << "Our kth Largest element is : " << KthLargest(root, count, k) << endl;

    return 0;
}