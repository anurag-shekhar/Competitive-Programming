/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumXORSumOfTwoArrays.cpp
 * Created on : Sun May 30 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> dp;
    int sum;
    int xorSum(vector<int>& nums1, vector<int>& nums2, int idx, int n, int mask)
    {
        if(idx==n)
            return 0;
        
        if(dp[mask] == INT_MAX)
            for(int i = 0; i<n; i++)
                if((mask & (1<<i)) == 0)
                    dp[mask] = min(dp[mask], (nums1[idx] ^ nums2[i]) + xorSum(nums1, nums2, idx+1, n, (mask | (1<<(i)))));
        return dp[mask];
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        sum = INT_MAX;
        int n = nums1.size();
        dp = vector<int>(1<<n, INT_MAX);
        return xorSum(nums1, nums2, 0, n, 0);
    }
};
/*
    1,2,3
    4,5,6
    
                            1,(4,5,6)
                            /   |    \
                           /    |     \
                     2(5,6)   2(4,6)   2(4,5)
                    /  \
                   /    \
                3(6)    3(5)  
                     
*/
