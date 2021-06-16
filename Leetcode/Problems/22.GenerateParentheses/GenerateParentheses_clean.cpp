/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GenerateParentheses_clean.cpp
 * Created on : Wed Jun 16 2021
 ****************************************************************
 */

class Solution {
public:
    vector<string> res;
    
    void backtrack(string A, int open, int close)
    {
        if(open == 0 && close == 0)
        {
            res.push_back(A);
            return;
        }
        
        if(open > close || open == -1)
            return;
        A.push_back('(');
        backtrack(A,open-1, close);
        A.pop_back();
        A.push_back(')');
        backtrack(A,open, close-1);
        A.pop_back(); 
    }
    
    vector<string> generateParenthesis(int n) {
        res.clear();
        
        backtrack({}, n,n);
        return res;
    }
};
