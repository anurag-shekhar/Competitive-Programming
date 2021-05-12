/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : JumpGameII.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int reach = 0;
        int maxReach = 0;
        int jump = 0;
        int n = nums.size();
        if(n==1)
            return 0;
        
        for(int i = 0; i<n; i++)
        {
            maxReach = max(maxReach, i+nums[i]);
            
            if(maxReach >= n-1)
                return jump+1;
            if(i==reach)
            {
                jump++;
                reach = maxReach;
            }
                
        }
        return jump;
    }
};
