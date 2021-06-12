/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CriticalConnectionsInNetwork.cpp
 * Created on : Sat Jun 12 2021
 ****************************************************************
 */


class Solution {
public:
    vector<vector<int> > graph, res;
    vector<int> parent, discovery, lowestReach;
    int time;
    void tarjan(int u)
    {
        discovery[u] = time;
        lowestReach[u] = time;
        time++;
        for(int v : graph[u])
        {
            if(discovery[v]==-1)
            {
                parent[v] = u;
                tarjan(v);
                
                if(discovery[u] < lowestReach[v])
                    res.push_back({u,v});
                lowestReach[u] = min(lowestReach[u], lowestReach[v]);
            }
            else 
            {
                if(parent[u]!=v)
                    lowestReach[u] = min(lowestReach[u], lowestReach[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        res.clear();
        graph = vector<vector<int> > (n);
        
        parent = vector<int> (n,-1);
        discovery = vector<int> (n,-1);
        lowestReach = vector<int> (n,-1);
        time = 0;
        
        for(auto edge : connections)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i<n; i++)
        {
            if(discovery[i]==-1)
                tarjan(i);
        }
        return res;
    }
};
/*
*/
