/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PartitioningIntoMinimumNumberOfDeciBinaryNumbers_trick.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    int minPartitions(string A) {
  
        int n = A.size();
        int res = 0;
        for(int i = 0; i<n; i++)
            res = max(res, A[i]-'0');

        return res;
    }
};
