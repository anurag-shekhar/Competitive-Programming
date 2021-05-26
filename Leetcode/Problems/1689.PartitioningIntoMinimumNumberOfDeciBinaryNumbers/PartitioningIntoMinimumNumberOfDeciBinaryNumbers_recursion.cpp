/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PartitioningIntoMinimumNumberOfDeciBinaryNumbers_recursion.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    int minPartitions(string A) {
  
        int n = A.size();
        bool flag = true;
        for(int i = 0; i<n; i++)
        {
            if(A[i] > '0')
            {
                flag = false;
                A[i]--;
            }      
        }
        if(flag)
            return 0;
        return 1+minPartitions(A);
    }
};
