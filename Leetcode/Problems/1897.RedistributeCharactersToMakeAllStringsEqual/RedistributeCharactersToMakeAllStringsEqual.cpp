/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RedistributeCharactersToMakeAllStringsEqual.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    bool makeEqual(vector<string>& words) {
     
        unordered_map<char, int> m;
        for(auto w : words)
        {
            for(char ch : w)
            {
                m[ch]++;
            }
        }
        int n = words.size();
        
        for(auto p : m)
            if(p.second%n)
                return false;
        return true;
    }
};
