

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

vector<int> verticalTraversal(node *root)
{
    // create map for horizontel distance and levelVise travresal (level,nodes)
    map<int, map<int, vector<int>>> nodes;

    // create queue for node and horizontel dis + level
    queue<pair<node *, pair<int, int>>> q;

    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        // jis bhi level par hai pehle hd or level par value push karte hai
        nodes[hd][level].push_back(frontNode->data);

        // left part exits
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        }

        // right part exits
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
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
    root->right->left->right = new node(8);
    root->right->right = new node(7);
    root->right->right->right = new node(9);

    vector<int> ans = verticalTraversal(root);
    // output 4 2 1 5 6 3 8 7 9
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}