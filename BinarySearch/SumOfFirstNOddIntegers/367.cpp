/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 367.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(int n) {
    
    int num = 1;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += num;
        num+=2;
    }
    return sum;
}
