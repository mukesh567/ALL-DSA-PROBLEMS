
#include <bits/stdc++.h>
using namespace std;

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
// insert the value of list
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

void swapingToNodes(node *&head, int x, int y)
{

    node *p;
    node *prev;

    // search node x
    p = head;
    prev = NULL;
    while (p != NULL && p->data != x)
    {
        prev = p;
        p = p->next;
    }
    node *px = p;
    node *prevX = prev;

    // search node y
    p = head;
    prev = NULL;
    while (p != NULL && p->data != y)
    {
        prev = p;
        p = p->next;
    }
    node *py = p;
    node *prevY = prev;

    // the last n node store to temp
    node *temp = py->next;
    py->next = px->next;
    px->next = temp;

    // if prevx and prevy is NULL
    if (prevX == NULL)
    {
        head = py;
        prevY->next = px;
    }

    if (prevY == NULL)
    {
        head = px;
        prevX->next = py;
    }

    // if prevx and prevy not NULL

    if (prevX != NULL && prevY != NULL)
    {
        prevX->next = py;
        prevY->next = px;
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
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    cout << "The original linked list is::" << endl;
    display(head);
    cout << "After swaping two nodes list are::" << endl;
    swapingToNodes(head, 4, 6);
    display(head);
    return 0;
}