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

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;

}

node *addLinkedList(node *&first, node *&second)
{
    int carry = 0;
    node *ansHead = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int value1 = 0;
        if (first != NULL)
        {
            value1 = first->data;
        }
        int value2 = 0;
        if (second != NULL)
        {
            value2 = second->data;
        }
        int sum = carry + value1 + value2;
        int digit = sum % 10;
        // insert in original ans linked list
        insertTail(ansHead, digit);
        carry = sum / 10;
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }

    // while (first != NULL && second != NULL)
    // {
    //     int sum = carry + first->data + second->data;
    //     int digit = sum % 10;
    //     // insert in original ans linked list
    //     insertTail(ansHead, digit);
    //     carry = sum / 10;
    //     first = first->next;
    //     second = second->next;
    // }
    // // agar first vaali list badi
    // while (first != NULL)
    // {
    //     int sum = carry + first->data;
    //     int digit = sum % 10;
    //     // insert in original ans linked list
    //     insertTail(ansHead, digit);
    //     carry = sum / 10;
    //     first = first->next;
    // }
    // // agar second vaali list badi ho
    // while (second != NULL)
    // {
    //     int sum = carry + second->data;
    //     int digit = sum % 10;
    //     // insert in original ans linked list
    //     insertTail(ansHead, digit);
    //     carry = sum / 10;
    //     second = second->next;
    // }
    // // agar carry bach jaye
    // while (carry != 0)
    // {
    //     int sum = carry;
    //     int digit = sum % 10;
    //     // insert in original ans linked list
    //     insertTail(ansHead, digit);
    //     carry = sum / 10;
    // }
    return ansHead;
}

node *addTwoNumbers(node *&first, node *&second)
{
    // reverse both linked list
    first = reverse(first);
    second = reverse(second);

    // add both linked list
    node *ans = addLinkedList(first, second);

    // reverse the ans
    ans = reverse(ans);

    return ans;
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
    insertTail(head1, 4);
    insertTail(head1, 5);

    insertTail(head2, 3);
    insertTail(head2, 4);
    insertTail(head2, 5);
    cout << "Before the adding linked list is ::" << endl;

    printList(head1);
    printList(head2);

    node *newHead = addTwoNumbers(head1, head2);
    printList(newHead);
    return 0;
}