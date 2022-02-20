/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TheKthFactorOfN.cpp
 * Created on : Sun Feb 20 2022
 ****************************************************************
 */

class Solution {
public:
    int kthFactor(int n, int k) {
        
        vector<int> divisors;
        int sqrtN = sqrt(n);
        for(int i = 1; i<sqrtN +1 ; i++)
        {
            
            if(n%i==0)
            {
                k--;
                if(k==0)
                    return i;
                divisors.push_back(i);
            }
        }
        if(sqrtN * sqrtN == n)
            k++;
        int len = divisors.size();
        if(len>=k)
            return n/divisors[len-k];
        return -1;
    }
};