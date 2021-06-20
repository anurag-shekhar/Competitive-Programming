/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SequenceReconstruction.cpp
 * Created on : Sun Jun 20 2021
 ****************************************************************
 */

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        
        unordered_map<int, unordered_set<int> > graph;
        unordered_map<int, int> indegree;
        
        for(auto v : seqs)
        {
            for(int i = 0; i<v.size(); i++)
            {
                if(i==0)
                {
                    indegree[v[i]] = indegree[v[i]];
                }
                else     
                    graph[v[i-1]].insert(v[i]);
            }
        }
        
        for(auto u : graph)
        {
            for(auto v : u.second)
            {
                indegree[u.first] = indegree[u.first];
                indegree[v]++;
            }
        }
        
        queue<int> q;
        int idx = 0;
        for(auto p : indegree)
        {
            if(p.second == 0)
                q.push(p.first);
        }
        
        while(!q.empty())
        {
            if(q.size()>1)
                return false;
            int pt = q.front();
            q.pop();
            
            if(idx >= org.size() || pt != org[idx++])
                return false;
            for(auto v : graph[pt])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        return idx==org.size() && indegree.size() == idx;
    }
};
