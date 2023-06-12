#include <bits/stdc++.h>
using namespace std;
int numberOfOnes(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    cout<<endl << "Number of one present in this number is : " << numberOfOnes(5) << endl<<endl;
    return 0;
}