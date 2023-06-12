

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

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        n->prevNode = NULL;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prevNode = temp;
}
void reverse(node *&head)
{
    node *temp = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        temp = curr->prevNode;
        curr->prevNode = curr->next;
        curr->next = temp;
        curr = curr->prevNode;
    }

    if (temp != NULL)
        head = temp->prevNode;
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
    cout << "Before reverse the linked List is::" << endl;
    display(head);

    cout << "After reverse the linked List is::" << endl;
    reverse(head);
    display(head);

    return 0;
}