
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(node *n)
{
    if (n == 0)
    {
        return 0;
    }
    return n->height;
}

int getBalancedFactor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return y;
}
node *insertBST(node *root, int val)
{
    if (root == NULL)

        return new node(val);

    if (val < root->data)

        root->left = insertBST(root->left, val);

    else if (val > root->data)

        root->right = insertBST(root->right, val);

    return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBalancedFactor(root);

    // left-left case than right rotate

    if (bf > 1 && val < root->left->data)
    {
        return rightRotate(root);
    }

    // right-right case than left rotate

    if (bf < -1 && val > root->right->data)
    {
        return leftRotate(root);
    }

    // left-right case than first child of root node left is called leftrotate and than rightrotate

    if (bf > 1 && val > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right-left case than first child of root node right is called rightrotate and than leftrotate

    if (bf < -1 && val < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
    node *root = NULL;
    root = insertBST(root, 1);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 5);
    root = insertBST(root, 6);
    root = insertBST(root, 3);

    Preorder(root);

    return 0;
}
