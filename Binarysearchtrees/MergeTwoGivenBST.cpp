
// time O(m+n);
// space O(m+n);

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

vector<int> mergedVectors(vector<int> &bst1, vector<int> &bst2)
{
    vector<int> ans(bst1.size() + bst2.size());

    int i = 0, j = 0, k = 0;

    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
        {
            ans[k++] = bst1[i];
            i++;
        }
        else
        {
            ans[k++] = bst2[j];
            j++;
        }
    }

    while (i < bst1.size())
    {
        ans[k++] = bst1[i];
        i++;
    }

    while (j < bst2.size())
    {
        ans[k++] = bst2[j];
        j++;
    }
    return ans;
}

node *MergerdInorderToBST(int start, int end, vector<int> &mergedVector)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;

    node *root = new node(mergedVector[mid]);

    root->left = MergerdInorderToBST(start, mid - 1, mergedVector);
    root->right = MergerdInorderToBST(mid + 1, end, mergedVector);

    return root;
}

node *mergeBST(node *root1, node *root2)
{
    // store inorder for both bst
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // mergerd both vector
    vector<int> mergedVector = mergedVectors(bst1, bst2);

    // mergerdInorder to bst
    int start = 0;
    int end = mergedVector.size() - 1;

    return MergerdInorderToBST(start, end, mergedVector);
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
    node *root1 = NULL;
    root1 = insertBST(root1, 10);
    insertBST(root1, 15);
    insertBST(root1, 20);
    insertBST(root1, 5);

    node *root2 = NULL;
    root2 = insertBST(root2, 8);
    insertBST(root2, 12);
    insertBST(root2, 18);
    insertBST(root2, 4);
    insertBST(root2, 2);

    node *mergedBst = mergeBST(root1, root2);
    inorder(mergedBst);

    return 0;
}