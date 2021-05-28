/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 36.cpp
 * Created on : Fri May 28 2021
 ****************************************************************
 */

bool solve(string s) {
    
    unordered_map<char , char> m;
    m[')']  = '(';
    m['}']  = '{';
    m[']']  = '[';
    stack<char> stk;
    int n = s.size();

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
