/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PermutationInString.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> m;
        
        for(char ch : s1)
            m[ch]++;
        
        if(s1.size() > s2.size())
            return false;
        
        int left = 0;
        int right = 0;
        
        for(right = 0; right<s1.size(); right++)
        {
            m[s2[right]]--;
            if(m[s2[right]]==0)
                m.erase(s2[right]);
        }    
        if(m.size()==0)
            return true;
        while(right<s2.size())
        {
            m[s2[right]]--;
            if(m[s2[right]]==0)
                m.erase(s2[right]);
            m[s2[left]]++;
            if(m[s2[left]]==0)
                m.erase(s2[left]);
            right++;
            left++;
            if(m.size()==0)
                return true;
            
        }
        return false;
    }
};
