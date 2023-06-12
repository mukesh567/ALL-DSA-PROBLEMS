

#include <bits/stdc++.h>
#include <map>
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

// insert the value
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

node *removeDuplicatesUnsortedList(node *&head)
{

    node *curr = head;
    node *prev = NULL;
    unordered_map<int, int> visited;

    while (curr != NULL)
    {
        if (!visited[curr->data])
        {
            visited[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
        curr = prev->next;
    }
    return head;
}

// print the linked list
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
    // intialised head
    node *head = NULL;

    // pass the function head and value
    insertAtTail(head, 4);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    // display function call
    cout << "Before the remove duplicates linked list is ::" << endl;
    display(head);
    cout << "After the remove duplicates linked list is ::" << endl;
    removeDuplicatesUnsortedList(head);
    display(head);
}