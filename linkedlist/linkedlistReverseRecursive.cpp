
#include <bits/stdc++.h>
using namespace std;

// create a node class
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// insert the value
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
node *ReverseRecursive(node *&head, node *curr, node *prev)

{

    if (curr == NULL)
    {
        head = prev;
        return head;
    }

    ReverseRecursive(head, curr->next, curr);
    curr->next = prev;
    // if(head==NULL || head->next==NULL)
    // {
    //     return head;
    // }
    // node* newhead=ReverseRecursive(head->next);
    // head->next->next=head;
    // head->next=NULL;
    // return newhead;
}
// print the linked list
void display(node *temp) // node* head
{
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << endl;
}
int main()
{
    // intialised head
    node *head = NULL;

    // pass the function head and value
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    // display function call
    cout << "Before the reverse node::" << endl;
    display(head);
    cout << "After recursive reverse the node:" << endl;
    node *curr = head;
    node *prev = NULL;
    node *newhead = ReverseRecursive(head, curr, prev);
    display(head);
}