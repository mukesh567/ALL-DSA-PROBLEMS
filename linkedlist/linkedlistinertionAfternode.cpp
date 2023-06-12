
#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node *next;
// node (int val)
// {
//     data=val;
//     next=NULL;
// }
};
// void insertTail(node *&head,int val)
// {
//     node *n=new node(val);
//     if(head==NULL)
//     {
//         head=n;
//         return;
//     }
//     node * ptr=head;
//     while(ptr->next!=NULL)
//     {
//         ptr=ptr->next;
//     }
//     ptr->next=n;
// }
void insertAtafternode(node* &head,node* &prev_node,int val)
{
    node * ptr=new node();
    ptr->data=val;
    ptr->next=prev_node->next;
    prev_node->next=ptr;
    
}
void printList(node * ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node *head=NULL;
    node *second=NULL;
    node *third=NULL;
    node *fourth=NULL;
    node *five=NULL;
    // insertTail(head,1);
    // insertTail(head,2);
    // insertTail(head,4);
    // insertTail(head,5);
    head=new node();
    second=new node();
    third=new node();
    fourth=new node();
    five=new node();
    head->data=1;
    head->next=second;
    second->data=3;
    second->next=third;
    third->data=4;
    third->next=fourth;
    fourth->data=5;
    fourth->next=five;
    five->data=6;
    five->next=NULL;
    cout<<"Before the insertion node::"<<endl;
    printList(head);
    cout<<" the insertion After node::"<<endl;
    insertAtafternode(head,head,2);
    printList(head);
    return 0;
}