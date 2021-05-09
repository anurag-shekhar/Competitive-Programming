/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 481.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool isValid(vector<int>& nums, int k, int capacity)
{
    int count = 1;
    int bucket = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        if(nums[i]> capacity)
            return false;
        if(bucket + nums[i] > capacity)
        {
            bucket = nums[i];
            count++;
            if(count > k)
                return false;
        }
        else 
            bucket += nums[i];
    }
    return true;
}

int solve(vector<int>& nums, int k) {
    
    int n = nums.size();

    int right = accumulate(nums.begin(), nums.end(), 0);
    int left = *min_element(nums.begin(), nums.end());

    int res = left;
    while(left <= right)
    {
        int mid = (right - left)/2 + left;
        
        if(isValid(nums,k,mid))
        {
            res = mid;
            right = mid - 1;
        }    
        else 
            left = mid +1;    
    }
    return res;
}
