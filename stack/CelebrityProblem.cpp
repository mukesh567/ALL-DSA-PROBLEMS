
#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &arr, int a, int b)
{
    if (arr[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrityElement(vector<vector<int>> &arr, int n)
{
    // push all the elements in stack
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // two elements nikalne par
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        // agar a ,b ko janta hai
        if (knows(arr, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    // single element in stack is may be our celebrity
    int candidate = s.top();
    // than verify it

    // iske row me saare elements zero hone chahiye
    // row check
    bool rowCheck = false;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[candidate][i] == 0)
        {
            zeroCount++;
        }
    }
    // all zeroes
    if (zeroCount == n)
    {
        rowCheck = true;
    }

    // col me saare one hone chahiye
    // col check
    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][candidate] == 1)
        {
            oneCount++;
        }
    }
    // agar all one hai ak ko chod kar
    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

int main()
{

    vector<vector<int>> arr = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};

    int n = arr.size();
    

    int ans = celebrityElement(arr, n);
    cout << "Celebrity element is : " << ans << endl;
    return 0;
}