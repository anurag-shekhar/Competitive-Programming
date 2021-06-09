/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : JumpGameVI.cpp
 * Created on : Wed Jun 09 2021
 ****************************************************************
 */

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        deque<int> dq;
        vector<int> dp(n,0);
        for(int i = 0; i<n; i++)
        {
            if(i==0)
            {
                dp[i] = nums[i];
                dq.push_back(i);
            }
            else 
            {
                while(dq.front() < i-k)
                    dq.pop_front();
            
                dp[i] = nums[i] + dp[dq.front()];
                
                while(!dq.empty() && dp[dq.back()] < dp[i])
                    dq.pop_back();
                dq.push_back(i);
            }
        }
        
        return dp[n-1];
    }
};
