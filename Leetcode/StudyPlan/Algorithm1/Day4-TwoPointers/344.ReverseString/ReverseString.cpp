/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseString.cpp
 * Created on : Fri Jan 14 2022
 ****************************************************************
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int left = 0, right = s.size()-1;
        char ch;
        while(left < right)
        {
            ch = s[left];
            s[left] = s[right];
            s[right] = ch;
            left++;
            right--;
        }
    }
};