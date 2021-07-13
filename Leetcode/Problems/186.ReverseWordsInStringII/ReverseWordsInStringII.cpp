/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseWordsInStringII.cpp
 * Created on : Wed Jul 14 2021
 ****************************************************************
 */

class Solution {
public:
    void reverse(vector<char>& s, int left, int right)
    {
        while(left <= right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    void reverseWords(vector<char>& s) {
        
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            if(s[i] != ' ')
            {
                int left = i;
                while(i < n && s[i]!= ' ')
                    i++;
                i--;
                reverse(s, left, i);
            }
        }
        reverse(s, 0, n-1);
    }
};
