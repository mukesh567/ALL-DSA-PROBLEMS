
#include <bits/stdc++.h>
using namespace std;

bool UniqueOccurrence(vector<int> &arr, int size)
{
    unordered_map<int, int> mp;

    for (auto i : arr)
    {
        // We store the frequency of the elements
        mp[i]++; 
    }
    
    unordered_map<int, int> mp2;

    for (auto i : mp)
    {
        if (mp2.find(i.second) == mp2.end())
        {
            mp2[i.second]++;
        }
        
        else
        {
        //If a frequency is already present in the map that means it is not unique so we can return false
            return false; 
        }
    }

    return true;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3, 3};

    cout << UniqueOccurrence(arr, 7);

    return 0;
}