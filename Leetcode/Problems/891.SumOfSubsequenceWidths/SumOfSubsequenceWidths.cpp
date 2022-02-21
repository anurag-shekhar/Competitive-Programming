/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfSubsequenceWidths.cpp
 * Created on : Mon Feb 21 2022
 ****************************************************************
 */

#define MOD 1000000007
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        long res = 0;
        
        vector<long> exp(n);
        exp[0] = 1;
        for(int i = 1; i<n; i++)
            exp[i] = (exp[i-1]*2)%MOD;
        
        for(int i = 0; i<n; i++)
        {
            res += exp[i]*nums[i];
            res -= exp[n-i-1]*nums[i];

            res = (res+MOD)%MOD;
        }
        return res%MOD;
    }
};