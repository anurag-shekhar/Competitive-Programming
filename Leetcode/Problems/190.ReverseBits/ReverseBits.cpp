/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseBits.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t res = 0;
        
        for(int i = 0; i<=31; i++)
        {
            res = res*2 + ((n>>i)&1);
        }
        return res;
    }
};
