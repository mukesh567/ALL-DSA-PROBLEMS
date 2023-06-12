

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

bool isIsomorphism(node *root1, node *root2)
{
    // base cases
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if (root1->data != root2->data)
    {
        return false;
    }

    bool first = isIsomorphism(root1->left, root2->left) && isIsomorphism(root1->right, root2->right);
    bool second = isIsomorphism(root1->left, root2->right) && isIsomorphism(root1->right, root2->left);

    return first || second;
}

int main()
{
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);

    node *root2 = new node(1);
    root2->left = new node(3);
    root2->right = new node(2);
    root2->right->right = new node(4);

    // isomorphism means ....data same hona chahiye agar same nhi hai to unka swapping
    // same hona chahiye ...or jiska child jiske niche laga hai vo dusre tree me bhi
    // usi k niche lagna chahiye chaye right me lage ya left me

    if (isIsomorphism(root1, root2))
    {
        cout << endl
             << "Trees are isomorphism !" << endl
             << endl;
    }
    else
    {
        cout << endl
             << "Trees are not isomorphism !" << endl
             << endl;
    }

    return 0;
}