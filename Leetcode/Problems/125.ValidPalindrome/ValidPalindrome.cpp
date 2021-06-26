/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidPalindrome.cpp
 * Created on : Sat Jun 26 2021
 ****************************************************************
 */

class Solution {
public:
    bool isPalindrome(string s) {
        
        int left = 0, right = s.size()-1;
        while(left <= right)
        {
            while(left<=right && !isalnum(s[left])) left++;
            while(left<=right && !isalnum(s[right])) right--;
            
            if(left<=right && tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
