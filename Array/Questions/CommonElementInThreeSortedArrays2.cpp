
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int arr1[n1], arr2[n2], arr3[n3];

    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    for (int i = 0; i < n3; i++)
        cin >> arr3[i];

    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            ans.push_back(arr1[i]);
            i++, j++, k++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
        // duplicate handle karne k liye
        int x = arr1[i - 1];
        while (arr1[i] == x)
            i++;
        int y = arr2[j - 1];
        while (arr2[j] == y)
            j++;
        int z = arr3[k - 1];
        while (arr1[k] == z)
            k++;
    }

    if (ans.size() == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}