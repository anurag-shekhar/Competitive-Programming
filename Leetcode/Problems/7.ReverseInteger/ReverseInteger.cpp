/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseInteger.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:
    int reverse(long x) {
        
        queue<int> q; 
        bool negFlag = false;
        if(x<0)
        {
            x*=-1;
            negFlag = true;
        }    
        
        while(x)
        {
            q.push(x%10);
            x/=10;
        }
        
        while(!q.empty())
        {
            int digit = q.front();
            q.pop();
            x = x*10 + digit;
        }
        if(x<INT_MIN || x>INT_MAX)
            return 0;
        if(negFlag)
            return -1*x;
        return x;
            
            
    }
};
