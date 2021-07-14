/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 582.cpp
 * Created on : Wed Jul 14 2021
 ****************************************************************
 */

bool solve(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0;
    int res = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        sum += nums[i];
        int diff = sum%k;
        if(i!=0 && diff ==0)
            return true;
        if(m.count(diff))
        {
            if(i-m[diff] >= 2)
                return true;
        }
        else 
            m[diff] = i;
    } 
    return false;
}
