/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PowerOfTwo.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if(n<0)
            return false;
        while(n)
        {
            count += n%2;
            n = n>>1;
        }
        if(count == 1)
            return true;
        return false;    
    }
};
