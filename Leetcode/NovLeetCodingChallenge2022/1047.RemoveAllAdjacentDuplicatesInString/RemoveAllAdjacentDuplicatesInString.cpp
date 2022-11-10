/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RemoveAllAdjacentDuplicatesInString.cpp
 * Created on : Mon Jun 28 2021
 ****************************************************************
 */

class Solution {
public:
    string removeDuplicates(string A) {
        
        int n = A.size();
        stack<char> s;
        
        for(int i = 0; i<n; i++)
        {
            if(s.empty() || s.top() != A[i])
                s.push(A[i]);
            else 
            {
                while(!s.empty() && s.top() == A[i])
                    s.pop();
            }
        }
        string res = "";
        while(!s.empty())
        {
            res+= s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
