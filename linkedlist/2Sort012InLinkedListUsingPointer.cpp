

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

node *sortList(node *&head)
{
    // create dummy node
    node *zeroHead = new node(-1);
    node *oneHead = new node(-1);
    node *twoHead = new node(-1);

    // create all tails
    node *zeroTail = zeroHead;
    node *oneTail = oneHead;
    node *twoTail = twoHead;

    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zeroTail->next = curr;
            zeroTail = curr;
        }
        else if (curr->data == 1)
        {
            oneTail->next = curr;
            oneTail = curr;
        }
        else if (curr->data == 2)
        {
            twoTail->next = curr;
            twoTail = curr;
        }

        curr = curr->next;
    }

    // merge three linked list
    if (oneHead->next != NULL)
    {
        // agar 1s list non empty
        zeroTail->next = oneHead->next;
    }
    else
    {
        // agar 1s vaali list ho he naa
        zeroTail->next = twoHead->next;
    }
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // head point to
    head = zeroHead->next;

    // delete all dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// print the linked list
void display(node *temp) // node* head
{
    // node* temp=head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main()
{
    // intialised head
    node *head = NULL;
    // pass the function head and value
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 0);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    // display function call
    cout << "Before sorting 0,1,2 in linked list : ";
    display(head);
    cout << "After sorting linked list is : ";
    sortList(head);
    display(head);
}