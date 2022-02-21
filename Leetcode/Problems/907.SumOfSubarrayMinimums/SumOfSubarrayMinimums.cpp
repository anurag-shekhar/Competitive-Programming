/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfSubarrayMinimums.cpp
 * Created on : Mon Feb 21 2022
 ****************************************************************
 */

#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<pair<int, int> > range(n);
        
        stack<int> s;
        
        for(int i = 0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
            {
                range[s.top()].second = i-1;
                s.pop();
            }
            
            if(!s.empty())
                range[i].first = s.top()+1;
            else 
                range[i].first = 0;
            s.push(i);
        }
        while(!s.empty())
        {
            range[s.top()].second = n-1;
            s.pop();
        }
        
        long res = 0;
        
        for(int i = 0; i<n; i++)
        {
            long val = arr[i];
            val *= (i-range[i].first+1);
            val *= (range[i].second-i+1);
            val %= MOD;
            res += val;
            res %= MOD;
        }
        return res%MOD;
        
    }
};