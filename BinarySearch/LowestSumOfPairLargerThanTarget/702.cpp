/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 702.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(vector<int>& nums, int target) {
    
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<int> s;
    int res = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        int search = target - nums[i];
        auto itr = s.upper_bound(search);
        if(itr!=s.end())
        {
            res = min(res, nums[i]+(*itr));
        }
        s.insert(nums[i]);
    }
    return res;
}
