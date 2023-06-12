

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

// mapping create
// find target node
node *createParentMapping(node *root, int target, map<node *, node *> &nodeToparent)
{
    node *targetRes = NULL;

    // level order traversal with mapping
    queue<node *> q;
    q.push(root);

    // root ka parent null
    nodeToparent[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            targetRes = front;
        }
        if (front->left)
        {
            // create mapping for left part
            nodeToparent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            // create mapping for right part
            nodeToparent[front->right] = front;
            q.push(front->right);
        }
    }
    return targetRes;
}

// burn tree
int burnTree(node *root, map<node *, node *> &nodeToparent)
{
    map<node *, bool> visited;

    queue<node *> q;
    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process neigh nodes
            node *front = q.front();
            q.pop();

            // for left part
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            // for right part
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            // for parent node
            if (nodeToparent[front] && !visited[nodeToparent[front]])
            {
                flag = 1;
                q.push(nodeToparent[front]);
                visited[nodeToparent[front]] = 1;
            }
        }

        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}

int minTime(node *root, int target)
{

    map<node *, node *> nodeToparent;

    node *targetNode = createParentMapping(root, target, nodeToparent);

    int ans = burnTree(targetNode, nodeToparent);

    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->right->right = new node(6);
    root->right->right->right = new node(9);
    root->right->right->right->right = new node(10);

    int minTimeReq = minTime(root, 8);

    cout << endl
         << "The minimum time to burn tree for node 8 is : " << minTimeReq << endl
         << endl;
    ;

    return 0;
}