/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountVowelsPermutation.cpp
 * Created on : Sun Jul 04 2021
 ****************************************************************
 */

#define MOD 1000000007 

class Solution {
public:
    
    vector<vector<int> > dp; 
    unordered_map<int, vector<int> > rules;   
    int backtrack(int ch, int currLen, int n)
    {
        if(dp[ch][currLen] != -1)
            return dp[ch][currLen];
        if(currLen == n-1)
            return dp[ch][currLen] = 1;
        dp[ch][currLen] = 0;
        for(int a: rules[ch])
        {
            dp[ch][currLen] += backtrack(a, currLen+1,n);
            dp[ch][currLen] %= MOD;
        } 
        return dp[ch][currLen];
    }
    int countVowelPermutation(int n) {
        dp = vector<vector<int> > (5,vector<int> (n,-1));
        rules[0] = {1};
        rules[1] = {0,2};
        rules[2] = {0,1,3,4};
        rules[3] = {2,4};
        rules[4] = {0};
        
        int res = 0;
        for(int i = 0; i<5; i++)
        {
            res+= backtrack(i, 0, n);
            res %= MOD;
        }
        return res;
    }
    
};
/*
a - 0
e - 1
i - 2
o - 3
u - 4
*/
