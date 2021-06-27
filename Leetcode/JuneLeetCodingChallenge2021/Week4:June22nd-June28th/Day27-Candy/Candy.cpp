/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Candy.cpp
 * Created on : Sun Jun 27 2021
 ****************************************************************
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> res(n,1);
        
        for(int i = 1; i<n; i++)
        {
            if(ratings[i-1] < ratings[i])
                res[i] = res[i-1]+1;
        }
        
        for(int i = n-2; i>=0; i--)
        {
            if(ratings[i+1] < ratings[i])
                res[i] = max(res[i], res[i+1]+1);
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};
