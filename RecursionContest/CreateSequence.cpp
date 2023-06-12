//Ninja is good at numbers. So today his friend gave him a task that required him to find out numbers made of 2 and 5 only less than a given limit.
//Given an integer N, you need to print all numbers less than N which are having digits only 2 or 5 or both.

//For Example :
//All numbers less than 30 with digits 2 and 5 are 2, 5, 22, 25.

#include <bits/stdc++.h>
using namespace std;

void createSequenceHelper(long long current, long long n, vector<long long> &result)
{

    //Base case
    if (current > n)
    {
        return;
    }

    //Add the current number to result
    if (current != 0)
    {
        result.push_back(current);
    }

    //Recurse by adding 2 and 5 to the end of the number
    createSequenceHelper(current * 10 + 2, n, result);
    createSequenceHelper(current * 10 + 5, n, result);
}

vector<long long> createSequence(long long n)
{

    vector<long long> result;

    // Call the function to add numbers to the result.
    createSequenceHelper(0, n, result);
    sort(result.begin(), result.end());

    // Return result.
    return result;
}

int main()
{
    long long n = 30;

    vector<long long> ans = createSequence(n);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}