

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

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool pairExitsOrNot(node *root, int target)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);

    // than like sorted array so apply two pointer approch
    int i = 0;
    int j = inorderVal.size() - 1;

    while (i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
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

    int target = 20;

    if (pairExitsOrNot(root, target))
    {
        cout << endl
             << endl
             << "pair present in this bst ! " << endl<<endl;
    }
    else
    {
        cout << endl
             << endl
             << "pair does'nt exits in this bst ! " << endl<<endl;
    }

    return 0;
}