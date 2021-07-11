/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountSquareSumTriples.cpp
 * Created on : Sun Jul 11 2021
 ****************************************************************
 */

class Solution {
public:
    int countTriples(int n) {
        
        unordered_set<int> s;
        
        for(int i = 1; i<=n; i++)
        {
            s.insert(i*i);
        }
        
        int count  = 0;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(s.count((i*i) + (j*j)))
                    count++;
            }
        }
        return count;
        
    }
};
