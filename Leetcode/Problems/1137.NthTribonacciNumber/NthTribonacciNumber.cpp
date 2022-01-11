/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NthTribonacciNumber.cpp
 * Created on : Wed Jan 12 2022
 ****************************************************************
 */

class Solution {
public:
    int tribonacci(int n) {
        
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        
        vector<int> cache(n+1, 1);
        cache[0] = 0;
        
        for(int i = 3; i<n+1; i++)
        {
            cache[i] = cache[i-3] + cache[i-2] + cache[i-1]; 
        }
        return cache[n];
    }
};
