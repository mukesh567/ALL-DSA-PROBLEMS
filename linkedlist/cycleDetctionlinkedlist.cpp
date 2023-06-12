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
void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

// void removecycle(node *&head)
// {
//     node *slow = head;
//     node *fast = head;
//     do
//     {
//         slow = slow->next;
//         fast = fast->next->next;

//     } while (slow != fast);
//     fast = head;
//     while (slow->next != fast->next)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     slow->next = NULL;
// }
node *detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}
node *firstNode(node *&head) // jaha se cycle start ho rhi hai vo node find karne  liye iske liye detect ko node
{
    if (head == NULL) // me badlna padega ....return slow   or return null karna padega
    {
        return NULL;
    }
    node *meet = detectCycle(head);
    node *fast = head;
    while (fast != meet)
    {
        fast = fast->next;
        meet = meet->next;
    }
    return fast;
}

void removeCycle(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *loopStart = firstNode(head);
    node *temp = loopStart;

    while (temp->next != loopStart)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
    // intialised head
    node *head = NULL;
    // pass the function head and value
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    makeCycle(head, 3);

    if (detectCycle(head) != NULL)
    {
        cout << "Cycle is present ! " << endl;
    }
    else
    {
        cout << "Cycle is not present ! " << endl;
    }

    node *startingNode = firstNode(head);
    cout << "Loop start at node : " << startingNode->data << endl;

    removeCycle(head);

    cout << "After removing the cycle linked list is : ";
    printList(head);
    return 0;
}