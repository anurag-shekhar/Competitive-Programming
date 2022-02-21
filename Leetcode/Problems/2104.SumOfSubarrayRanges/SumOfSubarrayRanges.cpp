/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfSubarrayRanges.cpp
 * Created on : Mon Feb 21 2022
 ****************************************************************
 */

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        
        int n = arr.size();
        vector<pair<int, int> > rangeMin(n), rangeMax(n);
        
        stack<int> s;
        
        for(int i = 0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
            {
                rangeMin[s.top()].second = i-1;
                s.pop();
            }
            
            if(!s.empty())
                rangeMin[i].first = s.top()+1;
            else 
                rangeMin[i].first = 0;
            s.push(i);
        }
        while(!s.empty())
        {
            rangeMin[s.top()].second = n-1;
            s.pop();
        }
        ////////////////////////
        for(int i = 0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] < arr[i])
            {
                rangeMax[s.top()].second = i-1;
                s.pop();
            }
            
            if(!s.empty())
                rangeMax[i].first = s.top()+1;
            else 
                rangeMax[i].first = 0;
            s.push(i);
        }
        while(!s.empty())
        {
            rangeMax[s.top()].second = n-1;
            s.pop();
        }
        
        long res = 0;
        
        for(int i = 0; i<n; i++)
        {
            long val1 = arr[i];
            val1 *= (i-rangeMin[i].first+1);
            val1 *= (rangeMin[i].second-i+1);
            
            long val2 = arr[i];
            val2 *= (i-rangeMax[i].first+1);
            val2 *= (rangeMax[i].second-i+1);
            
            res += val2-val1;
        }
        return res;
    }
};