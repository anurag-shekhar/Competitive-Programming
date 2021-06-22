/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AllPathsFromSourceLeadToDestination.cpp
 * Created on : Tue Jun 22 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_map<int,vector<int> > graph;
    vector<int> state;
    vector<bool> visited;
    bool dfs(int root, int dest)
    {
        if(root == dest)
        {
            return true;
        }
        if(visited[root]) 
            return false;
        visited[root] = true;
        if(state[root] == -1)
        {
            state[root] = 0;
            for(auto v : graph[root])
            {    
                
                if(v==root || !dfs(v, dest))
                {
                    state[root] = 0;
                    visited[root] = false;
                    return false;
                }
                state[root] = 1;
            }
            
        }
        visited[root] = false;
        if(state[root] == 0)
            return false;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        graph.clear();
        state = vector<int> (n, -1);
        visited = vector<bool> (n, false);
        
        
        for(auto e : edges)
        {
            if((e[0]==destination || e[0]==destination) && e[0] == e[1])
                return false;
            graph[e[0]].push_back(e[1]);
        }
        
        if(graph[destination].size()!=0)
            return false;
        return dfs(source, destination);
        
        
    }
};
