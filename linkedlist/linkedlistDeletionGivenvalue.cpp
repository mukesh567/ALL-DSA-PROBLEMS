
#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node *next;
node (int val)
{
    data=val;
    next=NULL;
}
};
void insertTail(node *&head,int val)
{
    node *n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node * ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=n;
}
void deleteGivenvalue(node* &head,int val)
{
    node * p=head;
    node * q=head->next;
    while(q->data!=val && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==val)
    {
        p->next=q->next;
        free(q);
    }
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
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    cout<<"Before the Deletion node::"<<endl;
    printList(head);
    cout<<"After the Deletion Given value::"<<endl;
    deleteGivenvalue(head,3);
    printList(head);
    return 0;
}