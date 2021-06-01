/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReorderRoutesToMakeAllPathsLeadToTheCityZero_bfs.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int,vector<int > > m;
    unordered_map<int,unordered_set<int> > directed;
    
    int bfs(int root)
    {
        queue<int> q;
        q.push(root);
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            visited.insert(node);
            
            for(auto a : m[node])
            {
                if(visited.count(a))
                    continue;
                
                if(directed[node].count(a))
                    count++;
                q.push(a);  
            }
        }
        return count;
            
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        visited.clear();
        m.clear();
        directed.clear();
        
        for(auto c : connections)
        {
            directed[c[0]].insert(c[1]);
            m[c[0]].push_back(c[1]);
            m[c[1]].push_back(c[0]);
        }
        return bfs(0);
        
    }
};
