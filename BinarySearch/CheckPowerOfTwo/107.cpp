/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 107.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(int n) {
    int count = 0;
    while(n)
    {
        count += n%2;
        n = n>>1;
    }
    if(count == 1)
        return true;
    return false;    
}
