/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PowerOfTwo.cpp
 * Created on : Mon Jan 24 2022
 ****************************************************************
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        bool counter = false;
        
        while(n)
        {
            if(n&1)
            {
                if(counter)
                    return false;
                else 
                    counter = true;
            }
            n >>= 1;
        }
        return counter;
    }
};