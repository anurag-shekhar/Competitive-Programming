/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 579.cpp
 * Created on : Wed Jan 19 2022
 ****************************************************************
 */

vector<int> solve(vector<int>& prices) {
    stack<int> s;

    int n = prices.size();
    vector<int> result(n, 0);
    for(int i = 0; i<n; i++)
    {
        while(!s.empty() && prices[s.top()] < prices[i])
        {
            result[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
    {
        result[s.top()] = 0;
        s.pop();
    }
    return result;
}
