
// Q9. Write a program to delete an element in single linkelist?

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
void insertTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
}
void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void printList(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    cout << "Before the Deletion linkedList::" << endl;
    printList(head);
    cout << "After the Deletion linkedList::" << endl;
    deletion(head, 2);
    printList(head);

    return 0;
}