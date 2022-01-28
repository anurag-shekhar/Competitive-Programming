/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximalNetworkRank.cpp
 * Created on : Fri Jan 28 2022
 ****************************************************************
 */

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, int> m; 
        vector<vector<int> > connect(n, vector<int> (n, 0));       
        for(int i = 0; i<roads.size() ;i++)
        {
            m[roads[i][0]]++;
            m[roads[i][1]]++;
            connect[min(roads[i][0], roads[i][1])][max(roads[i][0], roads[i][1])]++;
        }
        
        int rank = 0;
        
        for(int i = 0; i<n ;i++)
        {
            for(int j = i+1; j<n; j++)
                rank = max(rank, m[i] + m[j]  - connect[i][j]);
        }
        return rank;
    }
};
