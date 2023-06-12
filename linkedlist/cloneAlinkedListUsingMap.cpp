

// and arbit pointers in O(n) time
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};
void insertAtTail(Node *&Head, Node *&Tail, int data)
{
    Node *n = new Node(data);
    if (Head == NULL)
    {
        Head = n;
        Tail = n;
        return;
    }
    Tail->next = n;
    Tail = n;
}

// in O(n) space
Node *clone(Node *head)
{
    // step-1 create a clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step-2 create a map and mapping both list data
    unordered_map<Node *, Node *> oldTonewNode;
    Node *originalNode = head;
    Node *cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        oldTonewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    
    // step-3 random pointer point karane par
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode->random = oldTonewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
    
}

//print the linked list
void print(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << "Data = " << ptr->data << ", Random = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // 1's random points to 3
    head->random = head->next->next;

    // 2's random points to 1
    head->next->random = head;

    // 3's and 4's random points to 5
    head->next->next->random =
        head->next->next->next->next;
    head->next->next->next->random =
        head->next->next->next->next;

    // 5's random points to 2
    head->next->next->next->next->random =
        head->next;
    cout << "Original list is : " << endl;
    print(head);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(head);
    print(cloned_list);

    return 0;
}
