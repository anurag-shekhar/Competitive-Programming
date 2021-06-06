/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LargestRectangleInHistogram.cpp
 * Created on : Sat Jun 05 2021
 ****************************************************************
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxRes = 0;
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        for(int i = 0; i<n; i++)
        {
            int res;
            while(!s.empty() && heights[s.top()] > heights[i])
            {
                int idx = s.top();
                s.pop();
                res = heights[idx];
                if(s.empty())
                    res *= i;
                else 
                    res *= (i-s.top()-1);
                maxRes = max(maxRes, res);
            }  
            s.push(i);
        }
        return maxRes;
        
    }
};
