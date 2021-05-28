/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumErasureValue.cpp
 * Created on : Fri May 28 2021
 ****************************************************************
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int,int> m;
        int n = nums.size();
        int left = 0, right = 0;
        bool check = true;
        
        vector<int> prefix(n+1,0);
        prefix[0] = 0;
        
        for(int i = 1; i<=n; i++)
            prefix[i] = prefix[i-1] + nums[i-1];
        
        vector<int> location(2,0);
        int res =0; 
        while(right<=n)
        {
            if(check)
            {
                if(right == n)
                    break;
                m[nums[right]]++;
                if( m[nums[right]]==2)
                    check = false;
                right++;
                if(check)
                    res = max(res, prefix[right] - prefix[left]); 
            }
            else 
            {
                m[nums[left]]--;
                if(m[nums[left]]==1)
                    check = true;
                left++;
                
            }
        }
        return res;
    }
};
