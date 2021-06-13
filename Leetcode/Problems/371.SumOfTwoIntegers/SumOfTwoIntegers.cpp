/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfTwoIntegers.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    int getSum(int a, int b) {
        
        if(b>a)
            return getSum(b,a);
        
        int carry = 0;
        int c = 0;
        bool sign = false;
        if(a<0)
        {
            sign = true;
            a = abs(a);
            b = abs(b);
        }
        while(a)
        {
            int aLSM = a%2;
            
            int bLSM = 0;
            a>>=1;

            int sumLSM = (aLSM ^ carry);
            if(b)
            {
                bLSM = b%2;
                sumLSM ^= bLSM;
                b>>=1;
            }
            c = c*2 + sumLSM ;
            
            if(aLSM&bLSM || aLSM&carry || bLSM&carry)
                carry = 1;
            else 
                carry = 0;
        }
        if(carry)
            c = c*2 + carry;
        if(sign)
            return -1*c;
        return c;
        
            
    }
};
/*
10
11


*/
