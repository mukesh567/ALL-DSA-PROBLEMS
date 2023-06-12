
#include <bits/stdc++.h>
using namespace std;

vector<int>  MergeArrays( vector<int> &arr1, vector<int> &arr2)
{
     int n = arr1.size();
     int m = arr2.size();

     int i=n-1;
     int j=m-1;

     int lastInd = m+n-1;

     while(j>=0)
     {
         if(i>=0 && arr1[i]>arr2[j])
         {
             arr1[lastInd]=arr1[i];
             i--;
         }
         else
         {
             arr1[lastInd]=arr2[j];
             j--;
         }

         lastInd--;
     }

     return arr1;
}

int main()
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 5, 6};

    vector<int> ans = MergeArrays(arr1, arr2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}