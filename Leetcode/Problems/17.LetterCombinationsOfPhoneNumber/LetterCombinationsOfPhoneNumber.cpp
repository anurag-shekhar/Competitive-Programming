class Solution {
public:
    string mapping(char c)
    {
        vector<string> v = {"", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int num = c - '0';
        return v[num];
    }
    void backtrack(vector<string> &res, string &digits, int currIdx,int n, string ans)
    {
        if(currIdx == n)
        {    
            res.push_back(ans);
            return;
        }    
        
        string s = mapping(digits[currIdx]);
        for(int i = 0; i<s.size(); i++)
        {
            ans.push_back(s[i]);
            backtrack(res, digits, currIdx+1, n,ans);
            ans.pop_back();
        }
        return;
        
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        int n = digits.size();
        if(n==0)
            return res;
        backtrack(res,digits, 0, n,"");
        return res;
  
    }
};
