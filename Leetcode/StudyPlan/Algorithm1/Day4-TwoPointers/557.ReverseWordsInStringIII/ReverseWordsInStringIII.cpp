/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseWordsInStringIII.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    void reverse(string &s, int left, int right)
    {
        while(left<=right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        
        int left = 0;
        
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            if(s[i]==' ')
            {
                reverse(s, left, i-1);
                left = i+1;
            }
        }
        reverse(s, left, n-1);
        return s;
    }
};
