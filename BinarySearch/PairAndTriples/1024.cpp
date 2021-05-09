/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1024.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(string s) {
    
    unordered_map<char, int> m;

    for(char c : s)
        m[c]++;

    bool pair1 = false;
    for(pair<char, int> p : m)
    {
        if(p.second%3 == 1)
            return false;
        if(p.second%3 == 2)
        {
            if(pair1)
                return false;
            else 
            {
                pair1 = true;
            }    
        }        
    }
    if(pair1)
        return true;
    return false;    
}
