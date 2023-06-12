
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
node *merge(node *left, node *right)
{
    node *p1 = left;
    node *p2 = right;
    node *dummyNode = new node(-1);
    node *p3 = dummyNode;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p3 = p1;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p3 = p2;
        p2 = p2->next;
    }
    dummyNode = dummyNode->next;
    return dummyNode;
}
node *findMid(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node *mergeSortUsingLinkedList(node *&head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // find mid in original list
    node *mid = findMid(head);

    // break linked list into two parts
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // reursive calls
    left = mergeSortUsingLinkedList(left);
    right = mergeSortUsingLinkedList(right);

    // merging two halves
    node *result = merge(left, right);
    return result;
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
    insertTail(head, 4);
    insertTail(head, 5);
    insertTail(head, 7);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 6);

    cout << "Before the sorting linked list ::" << endl;
    printList(head);

    mergeSortUsingLinkedList(head);
    cout << "After the using merge sort algorithm ! " << endl;
    printList(head);
    return 0;
}