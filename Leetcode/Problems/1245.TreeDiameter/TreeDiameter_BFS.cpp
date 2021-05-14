/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TreeDiameter_bfs.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int> > edge;
        
        for(vector<int> e : edges)
        {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        
        queue<vector<int>> q;
        q.push({edges[0][0]});
        
        int firstFarthest = edges[0][0];
        
        unordered_set<int> visited;
        visited.insert(edges[0][0]);
        while(!q.empty())
        {
            vector<int> p = q.front();
            q.pop();
            
            firstFarthest = p[0];
            for(int a : edge[p[0]])
            {
                if(!visited.count(a))
                {
                    visited.insert(a);
                    q.push({a});
                }
            }
        }
        visited.clear();
        int farthest = 0;
        q.push({firstFarthest, 0});
        while(!q.empty())
        {
            vector<int> p = q.front();
            q.pop();
            
            farthest = p[1];
            for(int a : edge[p[0]])
            {
                if(!visited.count(a))
                {
                    visited.insert(a);
                    q.push({a, p[1]+1});
                }    
                    
            }
        }
        return farthest;
        
    }
};

/*


*/
