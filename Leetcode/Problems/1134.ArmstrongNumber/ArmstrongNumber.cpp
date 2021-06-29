/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ArmstrongNumber.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

class Solution {
public:
    int getKthPower(int d, int k)
    {
        int sum = 1;
        for(int i = 0; i<k; i++)
        {
            sum *=d;
        }
        return sum;
    }
    bool isArmstrong(int n) {
        
        vector<int> digit;
        int originalNum = n;
        while(n)
        {
            digit.push_back(n%10);
            n/=10;
        }
        
        int k = digit.size();
        
        int sum = 0;
        for(int i = 0; i<digit.size(); i++)
        {
            sum += getKthPower(digit[i], k);
            if(sum > originalNum)
                return false;
        }
        
        if(sum==originalNum)
            return true;
        return false;
    }
};
