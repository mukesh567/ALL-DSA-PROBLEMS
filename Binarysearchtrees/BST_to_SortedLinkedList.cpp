

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

node *flattenSortedList(node *root)
{
    vector<int> inorderVal;

    // we store value in sorted
    inorder(root, inorderVal);

    // create a new node as a rootnode
    node *newRoot = new node(inorderVal[0]);

    node *curr = newRoot;

    for (int i = 1; i < inorderVal.size(); i++)
    {
        node *temp = new node(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // last node
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

void printList(node *root)
{
    node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->right;
    }
    cout << "NULL";
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 6);
    insertBST(root, 7);

    node *newRoot = flattenSortedList(root);
    printList(newRoot);

    // 1->2->3->4->5->6->7->NULL
    
    return 0;
}