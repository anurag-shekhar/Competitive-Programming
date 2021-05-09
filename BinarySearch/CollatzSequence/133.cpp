/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 133.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(int n) {
    vector<int> res;
    int count = 0;
    while(n!=1)
    {
        count++;
        if(n%2)
        {
            n = 3*n+1;
        }
        else 
            n /=2;

    }
    count++;
    return count;
}
