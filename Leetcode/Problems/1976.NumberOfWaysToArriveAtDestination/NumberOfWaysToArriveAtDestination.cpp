/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfWaysToArriveAtDestination.cpp
 * Created on : Sat Aug 21 2021
 ****************************************************************
 */

#define MOD 1000000007
class Solution {
public:
    unordered_map<int, vector<vector<int> > > graph;
    vector<vector<long> > ans;
    vector<bool> visited;
    
    
    void dfs(int src, int time)
    {
        if(visited[src])
            return;
        visited[src] = true;
        for(auto v : graph[src])
        {
            
            if(time + v[1] <= ans[v[0]][0])
            {
                time += v[1];
                if(time == ans[v[0]][0])
                    ans[v[0]][1]++;
                else 
                    ans[v[0]][1] = 1;
                ans[v[0]][0] = time;
                dfs(v[0], time);
                time -= v[1];
            }
        }
        visited[src] = false;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        
        graph.clear();
        for(auto v : roads)
        {
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }
        ans = vector<vector<long> > (n, vector<long>(2, 0));
        visited = vector<bool> (n, false);
        
        for(int i = 0; i<n; i++)
        {
            ans[i][0] = INT_MAX;
            ans[i][1] = 0;
        }
        
        dfs(0, 0);
        return ans[n-1][1] % MOD;
    }
};
