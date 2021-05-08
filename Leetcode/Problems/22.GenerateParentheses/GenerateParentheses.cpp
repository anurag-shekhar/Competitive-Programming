class Solution {
public:
    
    void backtrack(string s, vector<string> &res, int n1,int n2)
    {
        if(n1==0 && n2==0)
        {
            res.push_back(s);
            return;
        }
        if(n1>n2)
            return;
        if(n1)
        {
            s.push_back('(');
            backtrack(s,res, n1-1,n2);
            s.pop_back();
        }    
        if(n2)
        {
            s.push_back(')');
            backtrack(s,res,n1,n2-1);
            s.pop_back();
        }    
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        //string s = "";
        backtrack("", res, n,n);
        return res;
        
    }
};
