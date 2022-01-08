/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DailyTemperatures.cpp
 * Created on : Sat Jan 08 2022
 ****************************************************************
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        
        int n = temperatures.size();
        vector<int> res(n, 0);
        for(int i = n-1; i>=0; i--)
        {
             while(!s.empty() && temperatures[i] >= temperatures[s.top()])
                 s.pop();
             if(!s.empty())
                 res[i] = s.top() - i;
            s.push(i);
        }
        return res;
        
    }
};
