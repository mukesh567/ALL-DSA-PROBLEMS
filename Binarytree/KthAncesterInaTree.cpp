

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *solve(Node *root, int &k, int node)

{
    // base cases
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node)
    {
        return root;
    }

    // call for left
    Node *leftAns = solve(root->left, k, node);

    // call for right
    Node *rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int KthAncester(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    int k = 2;
    int node = 4;
    cout << "kth ancester of given node is : " << KthAncester(root, k, node) << endl;

    return 0;
}