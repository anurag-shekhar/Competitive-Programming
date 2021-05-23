/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumNumberOfVerticesToReachAllNodes.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> in_degree(n,0);
        
        for(auto e : edges)
            in_degree[e[1]]++;
        
        vector<int> res;
        for(int i = 0; i<n; i++)
            if(in_degree[i]==0)
                res.push_back(i);
        return res;
    }
};
