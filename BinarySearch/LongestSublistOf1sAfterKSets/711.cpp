/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 711.cpp
 * Created on : Wed Jun 09 2021
 ****************************************************************
 */

int solve(vector<int>& nums, int k) {
    
    int count = 0;
    int left = 0, right = 0;

    int n = nums.size();
    int res = 0;
    while(right<=n)
    {
        if(count<=k)
        {
            if(right == n)
                break;

            if(nums[right] == 0)
                count++;
            right++;
            if(count<=k)
                res = max(res, right-left);
        }
        else 
        {
            if(nums[left]==0)
                count--;
            left++;
        }
    }
    return res;
}
