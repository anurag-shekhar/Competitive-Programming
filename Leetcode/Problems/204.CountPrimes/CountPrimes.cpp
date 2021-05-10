/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountPrimes.cpp
 * Created on : Mon May 10 2021
 ****************************************************************
 */

class Solution {
public:
    int countPrimes(int n) {
        
        if(n<=1)
            return 0;
        vector<bool> mark(n,false);
        
        
        
        int count = 0;
        for(int i = 2; i<n; i++)
        {
            if(!mark[i])
            {
                count++;
                
                for(int j = i; j<n; j+=i)
                    mark[j] = true;
            }
        }
        return count;
        
    }
};
