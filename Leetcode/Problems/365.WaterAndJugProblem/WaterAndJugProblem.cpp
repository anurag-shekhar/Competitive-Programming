/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : WaterAndJugProblem.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b, a%b);
    }

    bool canMeasureWater(int j1, int j2, int target) {
        
        if(j1 + j2 < target)
            return false;
        int val = gcd(j1, j2);
	    if(target % val == 0)
		    return true;
	    return false;
    }
};
