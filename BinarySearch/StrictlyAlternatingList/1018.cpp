/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1018.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(vector<int>& nums) {
    
    int n = nums.size();
    if(nums[0] >= nums[1])
        return false;

    for(int i = 1; i<n; i++)
    {
        if(nums[i]==nums[i-1])
            return false;
    }    
    return true;
}
