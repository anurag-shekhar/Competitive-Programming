/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOf1Bits_trick.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        //Method 2
        int count = 0;
        while(n)
        {
            n = n&(n-1);
            count++;
        }
        return count;
    }
};
