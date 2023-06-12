

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

vector<int> bottomViewTraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // create map for horizontal dis and data
    map<int, int> topNode;

    // create queue for nodes and horizontal dis
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for a hd than
        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        // than left k liye
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        // than right k liye
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> ans = bottomViewTraversal(root);
    // output 4 2 1 3 7
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}