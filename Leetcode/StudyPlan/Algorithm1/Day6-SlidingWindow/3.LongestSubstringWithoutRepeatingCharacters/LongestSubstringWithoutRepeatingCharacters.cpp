/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestSubstringWithoutRepeatingCharacters.cpp
 * Created on : Sun Jan 23 2022
 ****************************************************************
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> m;
        
        int left = 0, right = 0;
        int n = s.size(); 
        int res = 0;
        while(right < n)
        {
            m[s[right]]++;
            if(m[s[right]] == 2)
            {
                while(m[s[right]] != 1)
                {
                    m[s[left]]--;
                    left++;
                }
            }
            right++;
            res = max(res, right- left);
                
        }
        return res;
    }
};