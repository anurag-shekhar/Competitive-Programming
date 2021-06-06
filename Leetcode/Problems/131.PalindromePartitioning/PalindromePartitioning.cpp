/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PalindromePartitioning.cpp
 * Created on : Mon Jun 07 2021
 ****************************************************************
 */

class Solution {
public:
    
    bool isPalin(string s, int left, int right)
    {
        while(left<=right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void backtrack(vector<vector<string> > &res, vector<string> &local, int startIdx, string s)
    {
        if(startIdx==s.size())
        {
            res.push_back(local);
            return;
        }
        
        for(int i = startIdx; i<s.size(); i++)
        {
            if(isPalin(s,startIdx, i))
            {
                local.push_back(s.substr(startIdx, i-startIdx+1));
                backtrack(res, local, i+1,s);
                local.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> local;
        
        backtrack(res,local, 0,s);
        return res;
    }
};
