/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 982.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(vector<int>& rooms, int target) {
    

    for(int a : rooms)
    {
        if(a>= target)
            return a;
    }
    return -1;
}
