/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GrayCode.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        
        if(n == 1)
            return {0,1};
        
        vector<int> res = grayCode(n-1);
        int size = res.size();
        for(int i = size-1; i>=0; i--)
            res.push_back(res[i] + (1<<(n-1)));
        return res;
    }
};
