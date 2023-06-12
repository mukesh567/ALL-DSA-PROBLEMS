
#include <bits/stdc++.h>
using namespace std;

int LeastRecUsedAlgo(int pages[], int n, int capacity)
{
    // create the set
    unordered_set<int> s;

    // create the map to store recently used index
    unordered_map<int, int> ind;

    // store oyr answer
    int pageFaults = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                // insert the value
                s.insert(pages[i]);

                // increament our answer
                pageFaults++;
            }
            // store recently used page with index
            ind[pages[i]] = i;
        }
        
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                // find out our least recently used val
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (ind[*it] < lru)
                    {
                        lru = ind[*it];
                        val = *it;
                    }
                }

                // delete that val
                s.erase(val);

                // insert rest of the array
                s.insert(pages[i]);

                // increament our answer
                pageFaults++;
            }

            // store recently used page with index
            ind[pages[i]] = i;
        }
    }

    // return our answer
    return pageFaults;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    int pageFaults = LeastRecUsedAlgo(pages, n, capacity);

    cout << "According to  given pages we allocate the pageFault is :  " << pageFaults << endl
         << endl;

    return 0;
}