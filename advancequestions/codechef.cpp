#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int num;
    cin >> num;
    while (num--)
    {
        int n, sum = 0, i;
        scanf("%d", &n);
        while (n != 0)
        {
            i = n % 10;
            sum += i;
            n = n / 10;
        }
       cout<<sum<<"\n";
    }
    return 0;
}
