/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ParallelCourses.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */


class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
         
        vector<int> in_degree(n+1,0);
        vector<vector<int> > edges(n+1);
        
        for(auto r : relations)
        {
            in_degree[r[1]]++;
            edges[r[0]].push_back(r[1]);
        }
        
        queue<pair<int,int> > q;
        for(int i = 1;i<=n; i++)
        {
            if(in_degree[i]==0)
                q.push({i,1});
        }
        int res = 0;
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            
            res = p.second;
            
            for(auto e : edges[p.first])
            {
                in_degree[e]--;
                if(in_degree[e]==0)
                    q.push({e,p.second+1});
            }   
        }
        for(int i = 1; i<=n; i++)
            if(in_degree[i] != 0)
                return -1;
        
        return res;
    }
};
