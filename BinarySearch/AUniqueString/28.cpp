/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 28.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(string s) {
    unordered_map<char,int> m;
    for(char c : s)
    {
        m[c]++;
        if(m[c]==2)
            return false;
            
    }
    return true;
}
