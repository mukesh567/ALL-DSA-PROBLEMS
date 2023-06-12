#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void SubtreeNodes(Node *root,int k)
{
    if(root==NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    SubtreeNodes(root->left,k-1);
    SubtreeNodes(root->right,k-1);
}
int PrintNodesAtK(Node *root,Node *target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        SubtreeNodes(root,k);
        return 0;
    }
    int dl=PrintNodesAtK(root->left,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }else{
            SubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
     int dr=PrintNodesAtK(root->right,target,k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }else{
            SubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
   
PrintNodesAtK(root,root->left,1);
    

    return 0;
}