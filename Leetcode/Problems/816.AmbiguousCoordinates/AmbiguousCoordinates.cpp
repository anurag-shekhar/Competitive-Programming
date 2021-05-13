/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AmbiguousCoordinates.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

class Solution {
public:
    bool isValid(string s,char ch)
    {
        int n = s.size();
        if(ch == 'l' && s.size() > 1 && s[0] == '0')
            return false;
        if(ch=='r' && s[n-1] == '0')
            return false;
        
        return true;
            
    }
    vector<string> generateValidAxisValues(string s)
    {
        
        vector<string> res;
        if(isValid(s,'l'))
            res.push_back(s);
        
        if(s.size()==1)
            return res;
        
        for(int i = 1; i<s.size(); i++)
        {
            string a = s.substr(0,i);
            string b = s.substr(i);
            if(isValid(a,'l') && isValid(b,'r'))
            {
                string builder = a + "." + b;
                res.push_back(builder);
            }
        }
        return res;
        
    }
    void backtrack(vector<string> &res, string s)
    {
        if(s.size()<=1)
            return;
        int n = s.size();
        
        for(int i = 1; i<n; i++)
        {
            vector<string> x = generateValidAxisValues(s.substr(0,i));
            vector<string> y = generateValidAxisValues(s.substr(i));
            
            for(int xi = 0; xi<x.size(); xi++)
            {
                for(int yi = 0; yi<y.size(); yi++)
                {
                    string builder = "(" + x[xi] + ", "+ y[yi] + ")";
                    res.push_back(builder);
                }
            }
        }
    }
    vector<string> ambiguousCoordinates(string s) {
        
        vector<string> res;
        backtrack(res, s.substr(1,s.size()-2));
        return res;
        
    }
};
