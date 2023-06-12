

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

bool fatch(node *root2, int value)
{
    if (root2 == NULL)
    {
        return false;
    }

    if (root2->data == value)
    {
        return true;
    }

    bool x;
    bool y;

    if (value < root2->data)
    {
        x = fatch(root2->left, value);
    }
    else if (value > root2->data)
    {
        y = fatch(root2->right, value);
    }

    return x || y;
}

void solve(node *root1, node *root2, int target, int &count)
{
    // base case
    if (root1 == NULL)
    {
        return;
    }

    // left call
    solve(root1->left, root2, target, count);

    // than node par
    if (fatch(root2, target - root1->data))
    {
        count++;  
    }

    // than right call
    solve(root1->right, root2, target, count);
}

int countPairInTwoBST(node *root1, node *root2, int target)
{
    int count = 0;
    solve(root1, root2, target, count);

    return count;
}

int main()
{
    node *root1 = NULL;
    root1 = insertBST(root1, 5);
    insertBST(root1, 8);
    insertBST(root1, 3);
    insertBST(root1, 6);
    insertBST(root1, 4);
    insertBST(root1, 2);
    insertBST(root1, 7);

    node *root2 = NULL;
    root2 = insertBST(root2, 10);
    insertBST(root2, 6);
    insertBST(root2, 15);
    insertBST(root2, 3);
    insertBST(root2, 8);
    insertBST(root2, 11);
    insertBST(root2, 18);

    int target = 16;

    cout << endl;
    cout << endl
         << "Number of pair for given target is : " << countPairInTwoBST(root1, root2, target) << endl
         << endl;

    return 0;
}