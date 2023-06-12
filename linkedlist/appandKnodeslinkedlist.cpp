
#include <bits/stdc++.h>
using namespace std;

// create a node class
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
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
node *Kappand(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *Tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    while (Tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = Tail;
        }
        if (count == l - k + 1)
        {
            newHead = Tail;
        }
        Tail = Tail->next;
        count++;
    }
    newTail->next = NULL;
    Tail->next = head;
    return newHead;
}
void printList(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    // intialised head
    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    cout << "Before the appand list::" << endl;
    printList(head);
    cout << "After the K appand list::" << endl;
    node *newHead = Kappand(head, 3);
    printList(newHead);

    return 0;
}