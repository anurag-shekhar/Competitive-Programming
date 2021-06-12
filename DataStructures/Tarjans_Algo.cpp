/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Tarjans_Algo.cpp
 * Created on : Sat Jun 12 2021
 ****************************************************************
 */

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