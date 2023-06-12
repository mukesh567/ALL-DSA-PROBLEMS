
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
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

bool isCircular(node *&head)
{
    if (head == NULL)
    {
        return true;
    }

    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    
    return false;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    // intialised head
    node *head = NULL;
    // pass the function head and value
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    cout << "Before add head node :";
    display(head);

    cout << endl;

    if (isCircular(head))
    {
        cout << "Linked list is circular ! " << endl;
    }
    else
    {
        cout << "Linked list is non-circular ! " << endl;
    }
    cout << endl;
    return 0;
}