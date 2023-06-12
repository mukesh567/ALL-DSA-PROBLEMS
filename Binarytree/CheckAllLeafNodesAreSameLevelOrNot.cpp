
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

 int ans = true;

void solve(node *root, int height, int &MaxH)
{
    // base cases
    if (root == NULL)
    {
        return;
    }

    if (ans == false)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (MaxH == -1)
        {
            MaxH = height;
        }
        else
        {
            if (height != MaxH)
            {
                ans = false;
            }
        }
        return;
    }

    // left call
    solve(root->left,  height+1, MaxH);

    // right call
    solve(root->right, height+1, MaxH);
}

bool isSameLevelLeaf(node *root)
{
   
    int height = 0;
    int MaxH = -1;

    solve(root,  height, MaxH);
    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    

    if (isSameLevelLeaf(root))
    {
        cout << "Leaf nodes are in same level ! " << endl;
    }
    else
    {
        cout << "Leaf nodes are not in same level !" << endl;
    }

    return 0;
}