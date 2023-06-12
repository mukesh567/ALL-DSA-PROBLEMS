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
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> s;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);

        if (root->right)
            q.push(root->right);

        if (root->left)
            q.push(root->left);
    }

    // Now pop all items from stack one by one and print them
    while (!s.empty())
    {
        root = s.top();
        ans.push_back(root->data);
        s.pop();
    }

    return ans;
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

    vector<int> ans = reverseLevelOrder(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}