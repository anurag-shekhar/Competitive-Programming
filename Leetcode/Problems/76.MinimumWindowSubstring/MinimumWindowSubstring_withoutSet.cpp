/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumWindowSubstring_withoutSet.cpp
 * Created on : Wed Jun 16 2021
 ****************************************************************
 */

class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> m;
        
        for(char ch : t)
        {
            m[ch]++;
        }
        int check = m.size();
        
        int n = s.size();
        int left = 0, right = 0;
        int start = 0, end  = INT_MAX;
        
        while(right <= n)
        {
            if(check)
            {
                if(right == n)
                    break;
                
                if(m.count(s[right]))
                {
                    m[s[right]]--;
                    if(m[s[right]]==0)
                        check--;
                }
                right++;
                
                
            }
            else 
            {
                if(check == 0)
                {
                    if((right - left) < (end - start))
                    {
                        start = left;
                        end = right;
                    }
                }
                if(m.count(s[left]))
                {
                    m[s[left]]++;
                    if(m[s[left]]==1)
                        check++;
                }
                left++;
            }
        }
        if(end == INT_MAX)
            return "";
        return s.substr(start,end-start);
        
    }
};
