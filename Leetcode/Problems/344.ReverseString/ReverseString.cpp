/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseString.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
       
        int left = 0;
        int right = s.size()-1;
        
        while(left <= right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
