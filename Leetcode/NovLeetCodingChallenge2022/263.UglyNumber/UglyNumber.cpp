/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : UglyNumber.cpp
 * Created on : Sat Nov 19 2022 
 ***************************************************************
 */

class Solution {
public:
    bool isUgly(int n) {

        if(n==0)
            return false;
        for(int i = 2; i<=5; i++) {
            if(i!=4) {
                while (n%i==0) 
                    n=n/i;
            }
        }
        if(n==1)
            return true;
        return false;
    }
};