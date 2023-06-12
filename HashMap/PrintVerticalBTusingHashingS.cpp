//  program for printing vertical order of a given binary tree
#include <bits/stdc++.h>
using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int val)
    {
        key = val;
        left = NULL;
        right = NULL;
    }
};

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m)
{
    // Base case
    if (root == NULL)
        return;

    // Store current node in map 'm'
    m[hd].push_back(root->key);

    // Store nodes in left subtree
    getVerticalOrder(root->left, hd - 1, m);

    // Store nodes in right subtree
    getVerticalOrder(root->right, hd + 1, m);
}

void printVerticalOrder(Node *root)
{

    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);

    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
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
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    cout << "Vertical order traversal is n " << endl;
    printVerticalOrder(root);
    return 0;
}
