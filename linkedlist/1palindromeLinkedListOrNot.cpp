
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

// find the middle node
node *middle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// reverse the linked list
node *Reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

// define palindromic function
bool isPalindrome(node *&head)
{
    if (head == NULL)
    {
        return true;
    }
    node *mid = middle(head);        // puri linked list me se mid find kiya middle functon se
    node *last = Reverse(mid->next); // mid se last tak reverse kiya

    node *curr = head;
    while (last != NULL)
    {
        if (curr->data != last->data)
        {
            return false;
        }

        last = last->next;
        curr = curr->next;
    }
    
    return true;
}

int main()
{
    // intialised head
    node *head = NULL;

    // pass the function head and value
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);

    if (isPalindrome(head))
    {
        cout << "Linked list is palindrome !" << endl;
    }
    else
    {
        cout << "Linked list is Not  palindrome !" << endl;
    }
}