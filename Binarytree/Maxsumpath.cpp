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

int solvePath(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    // If node is negiative then return 0
    int leftC = max(0, solvePath(root->left, maxi));
    int rightC = max(0, solvePath(root->right, maxi));

    // Update maxi
    maxi = max(maxi, root->data + leftC + rightC);

    return max(leftC, rightC) + root->data;
}

int maxPathsum(Node *root)
{
    int ans = INT_MIN;
    solvePath(root, ans);
    return ans;
}
int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << maxPathsum(root) << endl;

    return 0;
}