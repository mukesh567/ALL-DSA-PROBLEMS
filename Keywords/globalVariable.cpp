
#include <bits/stdc++.h>
using namespace std;

// Declare global variable  (ak baar define karke kitne bhi function me use kar sakte hai)
int marks = 90;
// koi bhi function ese update kar sakta hai esliye yeh use nhi karna hai(Bad prectice)


void muk(int &i)
{
    cout << "Marks in muk function is : " << marks << endl;
}

void mukk(int &i)
{
    cout << "Marks in mukk function is : " << marks << endl;
}

int main()
{
    int i = 5;

    cout << "Marks in main is : " << marks << endl;

    muk(i);
    mukk(i);

    return 0;
}