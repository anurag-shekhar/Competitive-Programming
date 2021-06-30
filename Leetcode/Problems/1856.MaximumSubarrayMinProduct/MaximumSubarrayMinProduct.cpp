/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumSubarrayMinProduct.cpp
 * Created on : Wed Jun 30 2021
 ****************************************************************
 */

#define ll long long int
#define MOD 1000000007 
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        
        int n = nums.size();
        vector<ll> prefix(n, 0);
        stack<vector<int> > s;
        
        for(int i = 0; i<n; i++)
        {
            prefix[i] = nums[i];
            if(i!=0)
                prefix[i] += prefix[i-1];
        }
        ll res = 0;
        for(int i = 0; i<n; i++)
        { 
            vector<int> currItem = {i, nums[i]};
            while(!s.empty() && nums[i] < s.top()[1])
            {   ll sum = prefix[i-1];
                if(s.top()[0]>=1)
                    sum -= prefix[s.top()[0]-1];
                ll score = sum * s.top()[1];
                res = max(res, score);
                currItem[0] = s.top()[0];
                s.pop();
            }
            s.push(currItem);
        }
        
        while(!s.empty())
        {
            ll sum = prefix[n-1];
            if(s.top()[0]>=1)
                    sum -= prefix[s.top()[0]-1];
            ll score = sum * s.top()[1];
            res = max(res, score);
            s.pop();
        }
        return res%MOD;
    }
};
/*
3,1,5,6,4,2

*/
