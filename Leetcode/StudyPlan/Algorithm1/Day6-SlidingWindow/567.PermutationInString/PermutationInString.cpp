/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PermutationInString.cpp
 * Created on : Sun Jan 23 2022
 ****************************************************************
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        int charLeft = 0;
        
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2 < n1)
            return false;
        for(int i = 0; i<n1; i++)
        {
            m[s1[i]]++;
        }
        charLeft = m.size();
        
        int left = 0, right = 0;
        
        while(right<n1)
        {
            if(m.count(s2[right]))
            {
                m[s2[right]]--;
                if(m[s2[right]] == 0)
                    charLeft--;
                else if(m[s2[right]] == -1)
                    charLeft++;
            }    
            right++;    
        }
        if(charLeft == 0)
            return true;
        
        while(right < n2)
        {
            if(m.count(s2[right]))
            {
                m[s2[right]]--;
                if(m[s2[right]] == 0)
                    charLeft--;
                else if(m[s2[right]] == -1)
                    charLeft++;
            }  
            if(m.count(s2[left]))
            {
                m[s2[left]]++;
                if(m[s2[left]] == 0)
                    charLeft--;
                else if(m[s2[left]] == 1)
                    charLeft++;
            }  
            if(charLeft == 0)
                return true;
            right++;
            left++;
        }
        return false;
        
            
    }
};