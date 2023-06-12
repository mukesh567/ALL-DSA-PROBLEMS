
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
void insertAthead(node *&head, int val)
{
    node *ptr = new node(val);
    ptr->next = head;
    head = ptr;
}
void printList(node *ptr)
{
    while (ptr->next != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);
    cout << "Before the insertion node::" << endl;
    printList(head);
    cout << "After the insertion Head node::" << endl;
    insertAthead(head, 1);
    printList(head);
    return 0;
}