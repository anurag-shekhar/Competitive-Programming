/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PalindromePermutation.cpp
 * Created on : Tue Jun 08 2021
 ****************************************************************
 */

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        vector<int> charMap (26,0);
        
        for(char c : s)
            charMap[c-'a']++;
        
        int oddCount = 0;
        for(int a : charMap)
            if(a%2)
                oddCount++;
        
        if(oddCount>1)
            return false;
        return true;
    }
};
