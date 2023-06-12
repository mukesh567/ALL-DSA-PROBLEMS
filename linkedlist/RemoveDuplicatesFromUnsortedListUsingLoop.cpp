

#include <bits/stdc++.h>
#include <map>
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

node *removeDuplicatesUnsortedList(node *&head)
{

    node *curr, *temp, *dup;
    curr = head;

    /* Pick elements one by one */
    while (curr != NULL && curr->next != NULL)
    {
        temp = curr;

        /* Compare the picked element with rest
           of the elements */
        while (temp->next != NULL)
        {
            /* If duplicate then delete it */
            if (curr->data == temp->next->data)
            {
                /* sequence of steps is important here */
                dup = temp->next;
                temp->next = temp->next->next;
                delete (dup);
            }
            else
                temp = temp->next;
        }
        curr = curr->next;
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
    insertAtTail(head, 4);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    // display function call
    cout << "Before the remove duplicates linked list is ::" << endl;
    display(head);
    cout << "After the remove duplicates linked list is ::" << endl;
    removeDuplicatesUnsortedList(head);
    display(head);
}