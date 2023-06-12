

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

void inorder(node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

node *constructInToBST(int start, int end, vector<int> inorderVal)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;

    node *root = new node(inorderVal[mid]);

    root->left = constructInToBST(start, mid - 1, inorderVal);
    root->right = constructInToBST(mid + 1, end, inorderVal);

    return root;
}

node *NorToBal(node *root)
{
    vector<int> inorderVal;

    // we store value in sorted
    inorder(root, inorderVal);

    return constructInToBST(0, inorderVal.size() - 1, inorderVal);
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 3);
    insertBST(root, 2);
    insertBST(root, 1);

    node *newRoot = NorToBal(root);
    cout << endl
         << endl
         << "new root node is : " << newRoot->data << endl;
    return 0;
}