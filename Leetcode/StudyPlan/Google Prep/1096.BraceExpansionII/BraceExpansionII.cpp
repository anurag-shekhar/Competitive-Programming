/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BraceExpansionII.cpp
 * Created on : Sun Jun 23 2024
 ****************************************************************
 */

class Solution {
public:
    vector<string> unioniser(string s) {
        set<string> hayStack;
        int n =s.size();
        int idx = 0; 
        while(idx<n) {
            string token = "";
            bool flag1 = false, flag2= false;
            while(idx<n && s[idx] !=',') {
                
                if(idx < n && s[idx] == '{') {
                    flag2 = true;
                    int count = 1;
                    token += s[idx];
                    idx++;
                    while(count!=0) {
                        if(s[idx] == '{') count++;
                        if(s[idx] == '}') count--;
                        token += s[idx];
                        idx++;
                    }
                } else {
                    flag1 = true;
                    token += s[idx++];
                }
            }
            idx++;
            if(!flag2)
                hayStack.insert(token);
            else {
                vector<string> tokenise = braceExpansionII(token);
                for(string t : tokenise)
                    hayStack.insert(t);    
            }    
        }
        vector<string> res;
        for(string needle : hayStack) {
            res.push_back(needle);
        }
        return res;
    }
    void helper(int idx, string expression, string build, vector<string> &res) {
        if(idx == expression.size()) {
            res.push_back(build);
            return;
        }
        if(expression[idx] == '{') {
            int count = 1; 
            string expr = "";
            int i = idx+1;
            while(count != 0) {
                if(expression[i] == '{')
                    count++;
                if(expression[i] == '}')
                    count--;
                if(count !=0)
                    expr += expression[i];
                i++;
            }
            idx = i;
            vector<string> tokens = unioniser(expr);
            for(string token : tokens) {
                helper(idx, expression, build + token, res);
            }
        } else {
            helper(idx+1, expression, build + expression[idx], res);
        }
    }
    vector<string> braceExpansionII(string expression) {
        
        vector<string> res;
        helper(0, expression, "", res);
        sort(res.begin(), res.end());
        return res;
        
    }
};
/*
"{a,b}{c,{d,e}}"

"{a,b}{c,d,e}"
a, ab, bc, z

*/
