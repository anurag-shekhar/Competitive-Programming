/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOf1Bits.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        //Method 1
        int mask = 1;
        int count = 0;
        
        for(int i = 0; i<32; i++)
        {
            if((n & mask) != 0)
                count++;
            n >>= 1;
        }
        return count;
    }
};
