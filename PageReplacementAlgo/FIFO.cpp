
#include <bits/stdc++.h>
using namespace std;

int FirstINFirstOutAlgo(int *pages, int n, int capacity)
{
    // step-1 create a set to insert the intialiy pages
    unordered_set<int> s;

    // step-2 create a queue to maintain first in first out property ..to find oldpages
    queue<int> ind;

    // step-3 create the ans variable
    int pageFaults = 0;

    // step-4 iterate the enitre array
    for (int i = 0; i < n; i++)
    {
        // set is empty
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);

                // than increase the pageFault
                pageFaults++;

                // push into the queue
                ind.push(pages[i]);
            }
        }

        // set is full
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int EraseValue = ind.front();
                ind.pop();

                // than delete from the set
                s.erase(EraseValue);

                // than insert the next elements
                s.insert(pages[i]);

                // than push into the queue
                ind.push(pages[i]);

                // increament our answer
                pageFaults++;
            }
        }
    }

    return pageFaults;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4,
                   2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    int pageFaults = FirstINFirstOutAlgo(pages, n, capacity);

    cout << "According to  given pages we allocate the pageFault is :  " << pageFaults << endl
         << endl;

    return 0;
}