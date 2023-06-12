
#include <bits/stdc++.h>
using namespace std;

void createDuplicateArray(vector<pair<string, int>> &dupArray, vector<string> &wordAr, int size)
{
    for (int i = 0; i < size; i++)
    {
        dupArray.push_back(make_pair(wordAr[i], i));
    }
}

void printAnagramsTogether(vector<string> &wordArr, int size)
{

    vector<pair<string, int>> dupArray;
    createDuplicateArray(dupArray, wordArr, size);

    for (int i = 0; i < size; ++i)
    {
        sort(dupArray[i].first.begin(), dupArray[i].first.end());
    }

    // now sort the whole vector to get the identical words
    sort(dupArray.begin(), dupArray.end());

    for (int i = 0; i < size; ++i)
        cout << wordArr[dupArray[i].second] << " ";
}

int main()
{
    vector<string> wordArr = {"cat", "dog", "tac", "god", "act"};

    printAnagramsTogether(wordArr, wordArr.size());

    return 0;
}
