

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

bool checkPalindrome(vector<int> &arr)
{
    int start = 0,end = arr.size()-1;
    while(start<=end)
    {
        if(arr[start]!=arr[end])
        {
            return 0;
        }
        
        else
        {
            start++,end--;
        }
    }
    return 1;   
}

// define palindromic function
bool isPalindrome(node *&head)
{
    
    vector<int> arr;
    node* temp = head;
    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next;
    }

return checkPalindrome(arr);
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