/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 12.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

int solve(int k, vector<int>& nums) {
    
    unordered_map<int, int> m;
    unordered_set<int> s;
    int left = 0, right = 0;
    int n = nums.size();
    int res = 0;
    while(right <= n)
    {
        if(s.size() <= k)
        {
            if(right == n)
                break;

            m[nums[right]]++;
            if(m[nums[right]] == 1)
                s.insert(nums[right]);
            right++;
            if(s.size() <= k)
                res = max(res, right - left);
        }
        else 
        {
            m[nums[left]]--;
            if(m[nums[left]] == 0)
                s.erase(nums[left]);
            left++;    
        }
    }
    return res;
}
