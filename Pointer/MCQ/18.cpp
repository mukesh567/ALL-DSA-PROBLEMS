
#include <bits/stdc++.h>
using namespace std;

void update(int *ptr)
{
    *ptr = (*ptr) * 2;

}


int main()
{
    int i=10;

    update(&i);

    cout<<i<<endl;
    
    return 0;
}