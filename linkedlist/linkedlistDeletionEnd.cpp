
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
void deleteEnd(node *&head)
{
    node *ptr = head;
    node *p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);
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
    cout << "Before the Deletion node::" << endl;
    printList(head);
    cout << "After the Deletion End node::" << endl;
    deleteEnd(head);
    printList(head);
    return 0;
}