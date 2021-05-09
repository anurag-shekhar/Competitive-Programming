/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 591.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool check(vector<int>& nums, int k, int capacity)
{
    int bucket = 1;
    int sum = 0;
    for(int i = 0; i<nums.size(); i++)
    {   
        sum += nums[i];
        if(sum >= capacity)
        {
            bucket++;
            // if(bucket == k)
            //     return make_pair(false, minBucket);  
            sum = 0;    
        }    
    }
    if(bucket > k)
        return true;
    return false;
}
int solve(vector<int>& nums, int k) {
    
    int low = nums[0];
    int high =0;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        low = min(low, nums[i]);
        high += nums[i];
    }

    int res = 0;
    while(low<=high)
    {
        int mid = (low+high)/2;
    
        if(check(nums, k, mid))
        {
            res = max(mid,res);
            low = mid + 1;
        }
        else 
            high = mid-1;            
    }
    return res;
}
