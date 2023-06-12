// T(m+n)
// space O(h1+h2);

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

node *insertBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void convertBSTtoDLL(node *&root, node *&head)
{
    if (root == NULL)
    {
        return;
    }

    // first call right part
    convertBSTtoDLL(root->right, head);

    // pointer change
    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;

    // than call left part
    convertBSTtoDLL(root->left, head);
}

node *mergeTwoLinkedList(node *&head1, node *&head2)
{
    node *head = NULL;
    node *tail = NULL;

    while ( head1 != NULL && head2 != NULL )
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodesOfLL(node *&head)
{
    int count = 0;
    node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }

    count;
}

node *sortedListToBST(node *&head, int NumberOfNode)
{

    // base case
    if (NumberOfNode <= 0)
    {
        return NULL;
    }

    // left call for n/2
    node *left = sortedListToBST(head, NumberOfNode / 2);

    // create root node of the bst
    node *root = head;
    root->left = left;
    head = head->right;

    // right call for remaining nodes n-n/2-1
    root->right = sortedListToBST(head, NumberOfNode - NumberOfNode / 2 - 1);

    return root;
}

node *mergeBST(node *root1, node *root2)
{
    // convert bst to sorted DLL
    node *head1 = NULL;
    convertBSTtoDLL(root1, head1);
    head1->left = NULL;

    node *head2 = NULL;
    convertBSTtoDLL(root2, head2);
    head2->left = NULL;

    // merged two sorted list
    node *head = mergeTwoLinkedList(head1, head2);

    // sorted list to construct whole bst
    // number of nodes in linked list
    int Nodes = countNodesOfLL(head);

    return sortedListToBST(head, Nodes);
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
    node *root1 = NULL;
    root1 = insertBST(root1, 10);
    insertBST(root1, 15);
    insertBST(root1, 20);
    insertBST(root1, 5);

    node *root2 = NULL;
    root2 = insertBST(root2, 8);
    insertBST(root2, 12);
    insertBST(root2, 18);
    insertBST(root2, 4);
    insertBST(root2, 2);

    node *mergedBst = mergeBST(root1, root2);
    inorder(mergedBst);

    return 0;
}