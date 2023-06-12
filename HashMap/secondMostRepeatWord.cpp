
#include <bits/stdc++.h>
using namespace std;

string secondMostWord(vector<string> &arr, int n)
{
    int firstMostWordCount = 0;
    int secondMostWordCount = 0;

    // create a map for first most of times word
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        firstMostWordCount = max(firstMostWordCount, mp[arr[i]]);
    }

    string ans = "";
   
   //second most repeated word 
    for (pair<string, int> i : mp)
    {
        if (i.second > secondMostWordCount && i.second < firstMostWordCount)
        {
            secondMostWordCount = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int main()
{
    vector<string> arr = {"aaa", "bbb", "ccc", "aaa", "ccc", "aaa"};
    int n = arr.size();

    string ans = secondMostWord(arr, n);

    cout << "This is the second most repeated word : " << ans << endl;

    return 0;
}