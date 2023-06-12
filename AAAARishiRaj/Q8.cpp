
// Q8. Write a program to insert an element in single linkedList?

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
void insertAtHead(node *&head, int val)
{
    node *ptr = new node(val);
    ptr->next = head;
    head = ptr;
}
void insertAtbetween(node *&head, int val, int index)
{
    if (index == 0)
    {
        insertAtHead(head, val);
        return;
    }
    node *ptr = new node(val);
    node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
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
    insertTail(head, 4);
    insertTail(head, 5);
    cout << "Before the insertion linkedList::" << endl;
    printList(head);
    cout << "After the insertion  likedList::" << endl;
    insertAtbetween(head, 3, 0);
    printList(head);
    return 0;
}