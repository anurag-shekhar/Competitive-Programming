/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RemoveAllOccurrencesOfSubstring.cpp
 * Created on : Sun Jun 27 2021
 ****************************************************************
 */

class Solution {
public:
    string removeOccurrences(string A, string part) {
        stack<char> s;
        int np = part.size();
        for(int i = 0; i<A.size(); i++)
        {
                s.push(A[i]);
            if(s.top() == part[np-1])
            {
                stack<char> temp;
                int idx = np-1;
                while(idx >=0 && !s.empty() && part[idx] == s.top())
                {
                    temp.push(s.top());
                    s.pop();
                    idx--;
                }
                if(idx != -1)
                {
                    while(!temp.empty())
                    {
                        s.push(temp.top());
                        temp.pop();
                    }
                }
            }
        }
        
        string res = "";
        
        while(!s.empty())
        {
            res+= s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
