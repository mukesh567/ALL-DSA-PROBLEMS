
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

vector<int> zigZaagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<node *> q;
    q.push(root);

    bool leftToright = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // level preccess
        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToright ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        
        // direction change karne par
        leftToright = !leftToright;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    node *root = new node(7);
    root->left = new node(9);
    root->left->right = new node(8);
    root->right = new node(7);
    root->right->left = new node(6);
    root->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->left->left = new node(10);

    vector<int> ans = zigZaagTraversal(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}