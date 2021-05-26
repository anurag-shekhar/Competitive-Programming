/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BasicCalculatorII.cpp
 * Created on : Thu May 27 2021
 ****************************************************************
 */

class Solution {
public:
    
    vector<string> tokenize(string &s)
    {
        int n = s.size();
        vector<string> res;
        for(int i = 0; i<n; i++)
        {
            if(s[i]==' ')
                continue;
            string extract = "";
            if(isdigit(s[i]))
            {
                while(i<n && isdigit(s[i]))
                    extract += s[i++];
                i--;
            }
            else
                extract += s[i];
            res.push_back(extract);
        }
        return res;
    }
    
    int evaluate(int a, int b, string op)
    {
        if(op=="-")
            return a-b;
        if(op=="+")
            return a+b;
        if(op=="*")
            return a*b;
        return a/b;
    }
    

    int calculate(string s) {
        
        unordered_map<string, int> precedence;
        precedence["+"] = 1;precedence["-"] = 1;
        precedence["*"] = 2;precedence["/"] = 2;
        vector<string> tokens = tokenize(s);
        stack<int> num;
        
        string op = "";
        int n = tokens.size();
        
        for(int i = 0; i<n; i++)
        {
            if(precedence.count(tokens[i]))
            {
                int a = num.top();
                if(precedence[tokens[i]]==2)
                {
                    num.pop();
                    num.push(evaluate(a,stoi(tokens[i+1]),tokens[i]));
                    i++;
                }
                else if(op.size()==0)
                    op = tokens[i];
                else
                {
                    num.pop();
                    int b = num.top(); num.pop();
                    num.push(evaluate(b,a,op));
                    op = tokens[i];
                }   
            }
            else
                num.push(stoi(tokens[i]));
        }
        if(op.size())
        {
            int a = num.top(); num.pop();
            int b = num.top(); num.pop();
            num.push(evaluate(b,a,op));
        }    

        return num.top();
    }
};
