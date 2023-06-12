
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
    
    unordered_set<int> map;
    int left = 0, res = -1, sum = 0;
    for(int right = 0; right<nums.size(); right++)
    {
        while(left < right && (map.count(nums[right]) || map.size() >= k))
        {
            sum -= nums[left];
            map.erase(nums[left]);
            left++;
        }
        sum +=nums[right];
        map.insert(nums[right]);
            
        if (map.size() == k)
            res = max(res, sum);
    }
   cout<<res<<endl;
    return 0;
}