/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 79.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

vector<int> solve(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j= 0;
    int an = a.size(), bn = b.size();
    while(i<an && j < bn)
    {
        if(a[i]<=b[j])
            res.push_back(a[i++]);
        else 
            res.push_back(b[j++]);
    }
    while(i<an)
        res.push_back(a[i++]);
    while(j<bn)
        res.push_back(b[j++]);
    return res;
}
