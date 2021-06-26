/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestRepeatingCharacterReplacement.cpp
 * Created on : Sat Jun 26 2021
 ****************************************************************
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        unordered_map<char, int> m;
        m.clear();
        int mostFreq = 0;
        int left = 0, right = 0, res= 0;
        
        while(right < n)
        {
            m[s[right]]++;
            mostFreq = max(mostFreq, m[s[right]]);
            right++;
            while(right-left - mostFreq > k )
            {
                m[s[left]]--;
                left++;
                for(auto p : m)
                {
                    mostFreq = max(mostFreq, p.second);
                }
            }
            res = max(res, right - left);
            
        }
        return res;
    }   
};
