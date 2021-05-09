/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 119.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(int n) {
    
    int run = 0;
    int maxRun = 0;

    while(n)
    {
        if(n%2)
        {
            run++;
            maxRun = max(maxRun, run);
        }
        else 
        {
            run = 0;
        }
        n = n>>1;
    }
    return maxRun;
}
