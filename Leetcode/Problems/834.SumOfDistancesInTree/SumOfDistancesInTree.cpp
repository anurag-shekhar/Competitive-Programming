/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfDistancesInTree.cpp
 * Created on : Thu Jun 17 2021
 ****************************************************************
 */

class Solution {
public:
    
    vector<int> nodesBelowMe;
    vector<int> res;
    unordered_map<int, vector<int> > graph;
    vector<bool> visited;
    void dfs2(int root, int n, int prev)
    {
        visited[root] = true;
        
        res[root] = res[prev] - nodesBelowMe[root] + n -  nodesBelowMe[root];
        for(auto i : graph[root])
        {
            if(!visited[i])
                dfs2(i,n,root);
            
        }
            
        visited[root] = false;
    }
    void dfs1(int root)
    {
        int val = 0;
        visited[root] = true;
        nodesBelowMe[root] = 1;
        res[root] = 0;
        for(auto i : graph[root])
        {
            if(!visited[i])
            {
                dfs1(i);
                nodesBelowMe[root] += nodesBelowMe[i];
                res[root] += (res[i] + nodesBelowMe[i]);
            }
                
        }
        visited[root] = false;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        res = vector<int> (n,0);
        nodesBelowMe = vector<int> (n,0);
        visited = vector<bool> (n,false);
        graph.clear();
        for(auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        dfs1(0);
        visited[0] = true;
        for(auto i : graph[0])
            dfs2(i,n,0);
        return res;
    }
};
/*
     0(8)
    / \
1(0)   2(3)  ( 1 + 1 +1 + 1+ 2 = 6 | 8 - 4 + (6-4)  = 6 )
      /|\
     3 4 5
     0 0 0  6 - 1 + (6-1) = 10 = 2+2+1+2+3
*/
