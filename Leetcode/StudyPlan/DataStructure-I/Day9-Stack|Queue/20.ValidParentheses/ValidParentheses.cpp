/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidParentheses.cpp
 * Created on : Tue Jan 25 2022
 ****************************************************************
 */

class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> m;
        m[']'] = '[';
        m['}'] = '{';
        m[')'] = '(';
        
        int n = s.size();
        stack<char> stk;
        
        for(int i = 0; i<n; i++)
        {
            if(m.count(s[i]))
            {
                if(stk.empty() || stk.top() != m[s[i]])
                    return false;
                stk.pop();
            }
            else 
                stk.push(s[i]);
        }
        return stk.empty();
    }
};