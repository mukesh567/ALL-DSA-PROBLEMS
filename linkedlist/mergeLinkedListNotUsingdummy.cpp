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

node *solve(node *&head1, node *&head2)
{
    // if first list me only one element is present
    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }
    node *curr1 = head1;
    node *next1 = curr1->next;
    node *curr2 = head2;
    node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // insert the node
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // agar data dono k bich me lai na kare to pointer aage badhane par
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

node *merge(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data <= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
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
    insertTail(head1, 1);
    insertTail(head1, 4);
    insertTail(head1, 5);
    insertTail(head1, 7);
    insertTail(head2, 2);
    insertTail(head2, 3);
    insertTail(head2, 6);
    cout << "Before the merging list ::" << endl;

    printList(head1);
    printList(head2);
    cout << "After the merging linked list ::" << endl;
    node *newHead = merge(head1, head2);
    printList(newHead);
    return 0;
}