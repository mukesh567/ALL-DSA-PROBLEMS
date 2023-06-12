
// print inorder without stack and recursion
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
void morishTraversal(Node *root)
{
    Node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {

            // prec ka mean current k left k right me jate rho jab tak last right nhi milta
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == current)
            {
                pre->right = NULL;
                current = current->right;
            }

            else
            {

                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            }
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    morishTraversal(root);

    return 0;
}