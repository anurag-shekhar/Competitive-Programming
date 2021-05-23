/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindTheTownJudge.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> candidate(n+1, 0);
        
        for(auto edge : trust)
        {
            candidate[edge[0]] = INT_MIN;
            candidate[edge[1]]+=1;
        }
        
        for(int i = 1; i<=n; i++)
        {
            if(candidate[i]==n-1)
                return i;
        }
        return -1;
    }
};
