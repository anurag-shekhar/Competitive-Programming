/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfWaysToSeparateNumbers.cpp
 * Created on : Sat Aug 21 2021
 ****************************************************************
 */

#define MOD 1000000007
class Solution {
public:
    
    vector<unordered_map<int,int> > dp;  
    int helper(string num, int comma, int pos, int lastVal)
    {
        
        cout<<pos<<comma<<endl;
        if(pos == num.size())
            return 1;
        if(num[pos] == '0')
            return 0;
        
        long ans = 0;
        
        int currVal = num[pos] - '0';
        for(int i = pos+1; i<num.size(); i++)
        {
            if(currVal >= lastVal)
            {
                ans += helper(num, comma+1, i, currVal);
                ans %= MOD;
            }
            
            currVal = currVal*10 + num[i]-'0';
            
        }
        
        return dp[pos][comma]  = ans;
    }
    int numberOfCombinations(string num) {
        
        dp = vector<unordered_map<int, int> > (num.size());
        helper(num, 0, 0, 1);
        return dp[0][0]%MOD;
    }
};
