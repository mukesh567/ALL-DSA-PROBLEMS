
#include <bits/stdc++.h>
using namespace std;

void reverseString(char ch[], int n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        swap(ch[start++], ch[end--]);
    }

    cout << "String is reversed : " << ch << endl;
}

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

int main()
{
    char ch[] = "Mukesh";

    int len = getLength(ch);
    
    reverseString(ch, len);

    return 0;
}