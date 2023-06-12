

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

void inorderEle(node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorderEle(root->left, arr);
    arr.push_back(root->data);
    inorderEle(root->right, arr);
}

void constructBstToHeap(node *root, vector<int> arr, int &index)
{
    if (root == NULL)
    {
        return;
    }

    // left call
    constructBstToHeap(root->left, arr, index);

    // right call
    constructBstToHeap(root->right, arr, index);

    // than create root node of heap
    root->data = arr[index];
    index++;
}

void convertToMaxHeap(node *root)
{
    // first store bst data in vector
    vector<int> arr;
    inorderEle(root, arr);

    // convert this array to heap
    int index = 0;
    constructBstToHeap(root, arr, index);
}

void printPostorderOfMinHeap(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printPostorderOfMinHeap(root->left);
    printPostorderOfMinHeap(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 6);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 5);
    insertBST(root, 7);

    convertToMaxHeap(root);
    printPostorderOfMinHeap(root);

    return 0;
}