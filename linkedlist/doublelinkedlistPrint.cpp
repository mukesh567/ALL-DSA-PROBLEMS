
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prevNode;
    node(int val)
    {
        data = val;
        next = NULL;
        prevNode = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prevNode = n;
    }
    head = n;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prevNode = temp;
}
void deleteAtHead(node* &head) {
 
    node* todelete = head;
    head = head->next;
    head->prevNode = NULL;
 
    delete todelete;
}
 
void deletion(node* &head, int pos) {
 
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
 
    node* temp = head;
    int count = 1;
 
    while (temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }
 
    temp->prevNode->next = temp->next;
 
    if (temp->next != NULL) {
        temp->next->prevNode = temp->prevNode;
    }
 
 
    delete temp;
 
}
 
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    cout << "linked List is::" << endl;
    display(head);
    cout << "After added head node:" << endl;
    insertAtHead(head, 5);
    display(head);
    cout<<"After deletion Node:"<<endl;
    deletion(head,1);
    display(head);
    return 0;
}