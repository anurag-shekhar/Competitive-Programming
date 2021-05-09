/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 453.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(vector<int>& nums, int k) {

    unordered_map<int,int> m;
    if(k==0)
        return true;

    for(int a : nums)
        m[a]++;

    int n = nums.size();

    for(pair<int,int> p : m)
    {
        if(p.second > n/k)
            return false;
    }    
    return true;
    
}
