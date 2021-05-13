/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FrequencyOfTheMostFrequentElement.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

#define ll long long int
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n==0 || n==1)
            return n;
            
        sort(nums.begin(), nums.end());
        
        int left = 0, right=0;
        ll sum = 0;
        int maxFreq = 1;
        while(right<n)
        {
            if( ((ll)(right-left)*nums[right]-sum) <= k )
            {
                sum += nums[right];
                maxFreq = max(maxFreq, right-left+1);
                right++;
            }
            else 
            {
                sum -= nums[left];
                left++;
            }
                
        }
        return maxFreq;
    }
};
