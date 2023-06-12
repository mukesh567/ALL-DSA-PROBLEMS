
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

int maxLevelSum(Node *root)
{

    if (root == NULL)
    {
        return -1;
    }

    // first we store the root data
    int result = root->data;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        int sum = 0;
        while (count--)
        {

            Node *temp = q.front();
            q.pop();

            sum += temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        result = max(result, sum);
    }
    return result;
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

    cout << "Level wise maximum sum is : " << maxLevelSum(root) << endl;

    return 0;
}