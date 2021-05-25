/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : EvaluateReversePolishNotation.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */


class Solution {
public:
    
    int operation(int a, int b, string op)
    {
        if(op=="+")
            return b+a;
        if(op=="/")
            return b/a;
        if(op=="*")
            return b*a;
        return b-a;
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        unordered_set<string> op;
        op.insert("+");
        op.insert("-");
        op.insert("*");
        op.insert("/");
        
        int n = tokens.size();
        for(int i = 0; i<n; i++)
        {
            if(op.count(tokens[i]))
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                
                s.push(operation(a,b,tokens[i]));
            }
            else 
                s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};
