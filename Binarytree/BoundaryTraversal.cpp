
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

// print left most part ....without print leaf nodes
void traversalLeft(node *root, vector<int> &ans)
{
    // base case    leaf node hui to return karna hai without print
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    // if left part exits
    if (root->left)
    {
        traversalLeft(root->left, ans);
    }
    else
    {
        traversalLeft(root->right, ans);
    }
}

// print all leaf nodes
void traversalLeaf(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // simple left or right k liye call maar di
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}

// print right most part
void traversalRight(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    // if right part exits
    if (root->right)
    {
        traversalRight(root->right, ans);
    }
    else
    {
        traversalRight(root->left, ans);
    }

    // vaapas jane par print or store karte jana
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // 1 root node ko to daal he do
    ans.push_back(root->data);

    // 2 left part ko print / store kara do
    traversalLeft(root->left, ans);

    // 3 all leaf nodes print kar do left or right me
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);

    // 4 right part ko print / store kara do
    traversalRight(root->right, ans);

    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    root->left->left = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> ans = boundaryTraversal(root);
    // output 1 2 4 8 9 6 7 3
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}