
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

bool detectCycle(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;

    node *temp = head;

    while (temp != NULL)
    {
        // if cycle is present
        if (visited[temp] == true)
        {
            return true;
        }
        // pehle node ko true mark kiya than aage badhane par
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
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

    if (detectCycle(head))
    {
        cout << "Cycle is present ! " << endl;
    }
    else
    {
        cout << "Cycle is not present ! " << endl;
    }

    return 0;
}