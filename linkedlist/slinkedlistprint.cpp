
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void printList(node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    // intialised all node in null
    // node *head = NULL;
    // node *second = NULL;
    // node *third = NULL;
    // asigned new node
    // head = new node();
    // second = new node();
    // third = new node();
    // asigned value of each node
    
// dynamic heap mamory allocated
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    printList(head);

    return 0;
}