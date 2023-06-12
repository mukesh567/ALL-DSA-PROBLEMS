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
node *mergeRecursive(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
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
    node *head1 = NULL;
    node *head2 = NULL;
    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {2, 3, 6};
    for (int i = 0; i < 4; i++)
    {
        insertTail(head1, arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        insertTail(head2, arr2[i]);
    }

    cout << "Before the merging list ::" << endl;
    printList(head1);
    printList(head2);
    cout << "After the merge two linked list ::" << endl;
    node *newHead = mergeRecursive(head1, head2);
    printList(newHead);

    return 0;
}