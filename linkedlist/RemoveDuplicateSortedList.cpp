

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

node *removeDuplicates(node *&head)
{
    // if linked list is empty
    if (head == NULL)
    {
        return NULL;
    }
    // if linked list is non-empty
    node *curr = head;

    while (curr != NULL)
    {
        // if data is equal
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            node *next_next = curr->next->next;
            node *todelete = curr->next;
            delete (todelete);
            curr->next = next_next;
        }
        else
        {
            // if data is not equal
            curr = curr->next;
        }
    }
}

// print the linked list
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
    // intialised head
    node *head = NULL;

    // pass the function head and value
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    // display function call
    cout << "Before the remove duplicates linked list is ::" << endl;
    display(head);
    cout << "After the remove duplicates linked list is ::" << endl;
    removeDuplicates(head);
    display(head);
}