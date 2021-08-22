/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindUniqueBinaryString.cpp
 * Created on : Sun Aug 22 2021
 ****************************************************************
 */

class Solution {
public:
    
    unordered_set<string> s;
    
    string backtrack(string local, int pos, int n)
    {
        if(pos == n)
        {
            if(s.count(local))
                return "";
            return local;
        }
        
        string res = backtrack(local+'0', pos+1, n);
        if(res.size())
            return res;
        res = backtrack(local+'1', pos+1, n);
        if(res.size())
            return res;
        return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();  
        s.clear();
        for(string a : nums)
            s.insert(a);
        
        return backtrack("", 0, n);
        
    }
};
