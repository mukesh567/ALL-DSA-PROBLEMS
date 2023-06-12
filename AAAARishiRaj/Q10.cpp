
// Q 10. Write a program to create and display the elements of doubly linked list?

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
    cout << "Doubly linked List is::" << endl;
    display(head);

    return 0;
}