/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 19.cpp
 * Created on : Fri May 28 2021
 ****************************************************************
 */

bool solve(vector<int>& nums) {
    
    int n = nums.size();

    bool incrFlag = true;
    bool decrFlag = true;
    for(int i = 1; i<n; i++) // incr
    {
        if(nums[i-1] >= nums[i])
        {
            incrFlag = false;
            break;
        }
    }
    for(int i = 1; i<n; i++) // decr
    {
        if(nums[i-1] <= nums[i])
        {
            decrFlag = false;
            break;
        }
    }

    return (incrFlag || decrFlag);
       
}
