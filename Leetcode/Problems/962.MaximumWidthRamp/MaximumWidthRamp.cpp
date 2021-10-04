/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumWidthRamp.cpp
 * Created on : Tue Oct 05 2021
 ****************************************************************
 */

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        vector<vector<int> > m;
        int n = nums.size();
        for(int i = 0;i<n; i++)
        {
            m.push_back({nums[i], i});
        }
        
        sort(m.begin(), m.end());
        
        stack<int> s;
        int res = 0;
        
        for(int i = 0; i<n; i++)
        {
            if(s.empty())
            {
                s.push(m[i][1]);
            }
            else
            {
                if(s.top() > m[i][1])
                {
                    s.pop();
                    s.push(m[i][1]);
                }
                else 
                    res = max(res, m[i][1] - s.top());
            }
        }
        return res; 
    }
};
