
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

void solve(node *root, node *&head, node *&prev, int &f)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // inorder traversal me left , root , than right

    // recursive call for left part
    solve(root->left, head, prev, f);

    // hamara pehla node aa rha hai than
    //lets suppose right == next and left == prev
    if (f == 0)
    {
        f = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }

    // recursive call for right part
    solve(root->right, head, prev, f);
}

node *BtToDLL(node *root)
{
    node *head = 0;
    node *prev = 0;
    int f = 0;

    solve(root, head, prev, f);
    return head;
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
    node *root = new node(10);
    root->left = new node(12);
    root->right = new node(15);
    root->left->left = new node(25);
    root->left->right = new node(30);
    root->right->left = new node(36);

    inorder(root);
    cout << endl;

  node* head  = BtToDLL(root);
  cout<<"Head of the doubly linked list is : "<<head->data;
    cout << endl;

    return 0;
}