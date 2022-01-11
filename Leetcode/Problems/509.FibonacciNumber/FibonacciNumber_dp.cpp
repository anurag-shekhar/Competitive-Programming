/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FibonacciNumber_dp.cpp
 * Created on : Wed Jan 12 2022
 ****************************************************************
 */

class Solution {
public:
    int fib(int n) {
        
        if(n<=1)
            return n;
        vector<int> cache(n+1, 0);
        cache[1] = 1;
        
        for(int i = 2; i<n+1; i++)
        {
            cache[i] = cache[i-1] + cache[i-2]; 
        }
        return cache[n];
        
    }
};
