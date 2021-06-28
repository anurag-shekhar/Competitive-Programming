/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestSubstringWithAtMostTwoDistinctCharacters.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<char, int> m;
        int n = s.size();
        int left = 0, right = 0;
        int res = 0;
        while(right<n)
        {
            if(m.size()<=2)
            {
                m[s[right]]++;
                
                right++;
                if(m.size()<=2)
                    res = max(res, right - left);
            }
            else 
            {
                m[s[left]]--;
                if(m[s[left]]==0)
                    m.erase(s[left]);
                left++;
            }
        }
        return res;
    }
};
