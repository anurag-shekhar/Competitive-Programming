/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestSubstringWithoutRepeatingCharacters.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> m;
        bool check = true;
        
        int left = 0, right = 0;
        
        int n =s.size();
        int res = 0;
        while(right<=n)
        {
            if(check) // valid
            {
                if(right==n)
                    break;
                m[s[right]]++;
                if(m[s[right]]==2)
                    check = false;
                right++;
                if(check)
                    res = max(res, right-left);
            }
            else
            {
                m[s[left]]--;
                if(m[s[left]]==1)
                    check = true;
                left++;
                
            }
        }
        return res;
        
    }
};
/*
x - be any char
m[x] = 1 // valid


m[x1] = 1
m[x2] = 1
m[x3] = 1



