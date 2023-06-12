#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int calculateDiameter(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = calculateDiameter(root->left, &leftHeight);
    int rightDiameter = calculateDiameter(root->right, &rightHeight);
    *height = max(leftHeight, rightHeight) + 1;
    int currDiameter = leftHeight + rightHeight + 1;
    return max(currDiameter, max(leftDiameter, rightDiameter));
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout << calculateDiameter(root, &height) << endl;

    return 0;
}