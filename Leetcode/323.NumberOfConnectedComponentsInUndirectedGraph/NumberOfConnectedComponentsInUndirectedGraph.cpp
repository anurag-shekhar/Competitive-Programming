class Solution {
public:
    void dfs(vector<vector<int> > &adjList,unordered_set<int> &visited, int pt)
    {
        if(visited.find(pt)!=visited.end())
            return;
        visited.insert(pt);
        
        for(int a : adjList[pt])
            dfs(adjList,visited, a);

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adjList(n);
        
        for(vector<int> e : edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        unordered_set<int> visited;
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(visited.count(i)==0)
            {
                dfs(adjList, visited, i);
                count++;
            }
        }
        return count;
    }
};
