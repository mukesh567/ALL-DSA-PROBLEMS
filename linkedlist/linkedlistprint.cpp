
#include<bits/stdc++.h>
using namespace std;

// create a node class
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

// insert the value
void insertAtTail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

// print the linked list
void display(node* temp)   //node* head
{
    // node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    // intialised head
    node* head=NULL;
    // pass the function head and value
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    // display function call
    display(head);
    

}