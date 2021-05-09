/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 808.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool check(int mid, vector<int> &nums, int k)
{
    int sum  = 0;
    int bucket = 0;
    for(int i = 0; i<nums.size(); i++)
    {
        if(nums[i]>mid)
            return false;
        if(sum + nums[i] > mid)
        {
            bucket++;
            if(bucket == k)
                return false;
            sum = nums[i];
        }
        else 
            sum += nums[i];
    }
    return true;
}
int solve(vector<int>& nums, int k) {
    
    int n = nums.size();
    int low = *min_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    //high -= min(nums[0], nums[n-1]);
    int res = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(check(mid, nums, k))
        {
            res = mid;
            high = mid -1;
        }
        else 
            low = mid+1;
    }
    return res;
    
}
