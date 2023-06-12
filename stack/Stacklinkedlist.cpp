
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node *top = NULL;

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Node *&top)
{
    Node *p = new Node();
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node *push(Node *&top, int x)
{
    if (isFull(top))
    {
        cout << "Stack Overflow ! " << endl;
    }
    else
    {
        Node *n = new Node();
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(Node *&tp)
{
    if (isEmpty(tp))
    {
        cout << "Stack Underflow !" << endl;
    }
    else
    {
        Node *n = tp;
        tp = (tp)->next;
        int x = n->data;
        delete n;
        return x;
    }
}
void PrintlinkedList(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    push(top, 78);
    push(top, 7);
    push(top, 8);
    PrintlinkedList(top);

    int element = pop(top);
    cout << "Popped element is: " << element << endl;
    PrintlinkedList(top);
    return 0;
}