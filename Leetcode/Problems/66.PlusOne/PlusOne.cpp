/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PlusOne.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(), digits.end());
        
        int carry =1;
        for(int i = 0; i<digits.size(); i++)
        {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        }
        if(carry)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
