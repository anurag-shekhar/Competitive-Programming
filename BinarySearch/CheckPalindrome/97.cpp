/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 97.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(string s) {
    
    int l = 0, r = s.size()-1;

    while(l<=r)
    {
        if(s[l]!=s[r])
            return false;
        l++;
        r--;    
    }
    return true;
}
