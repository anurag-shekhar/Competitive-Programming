/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfDigitsInBaseK.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

class Solution {
public:
    int sumBase(int n, int k) {
        
        int sum = 0;
        
        while(n)
        {
            sum += n%k;
            n/=k;
        }
        return sum;
        
    }
};
