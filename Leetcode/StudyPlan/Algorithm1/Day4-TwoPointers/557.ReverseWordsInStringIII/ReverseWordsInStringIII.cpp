/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseWordsInStringIII.cpp
 * Created on : Fri Jan 14 2022
 ****************************************************************
 */

class Solution {
public:
    
    void reverse(string &s, int start, int end)
    {
        while(start <= end)
        {
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        
        int ptr = 0;
        int n = s.size();
        while(ptr < n)
        {
            int start = ptr; 
            while(ptr<n && s[ptr] != ' ')
                ptr++;
            reverse(s, start, ptr-1);
            ptr++;
        }
        return s;
    }
};