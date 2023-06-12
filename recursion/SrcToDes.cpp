
#include <iostream>
using namespace std;

void reachHome(int src, int dest)
{
    cout << "Source is : " << src << " Destination is : " << dest << endl;

    if (src == dest)
    {
        cout << "Me ghar pahuch gya hu !" << endl;
        return;
    }

    // processing
    src++;

    // recursive call
    reachHome(src, dest);
}

int main()
{
    int src = 1;
    int dest = 10;

    cout << endl;
    reachHome(src, dest);
    return 0;
}