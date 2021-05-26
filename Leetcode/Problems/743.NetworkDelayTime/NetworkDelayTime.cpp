/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NetworkDelayTime.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:

    void bfs(unordered_map<int, vector<pair<int,int> > > &m, vector<int> &time, int k)
    {
        queue<pair<int, int> > q;
        q.push({k,0});

        while(!q.empty())
        {
            pair<int, int> node  = q.front();
            q.pop();
            
            if(time[node.first] <= node.second)
                continue;
            else 
            {
                time[node.first] = node.second;
                for(pair<int,int> p : m[node.first])
                    q.push({p.first, node.second + p.second});

            }       
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> time(n+1, INT_MAX);
        unordered_map<int, vector<pair<int,int> > >m;
        for(vector<int> a : times)
        {
            m[a[0]].push_back({a[1], a[2]});
        } 
        bfs(m, time, k);
        
        int res = 0;
        for(int i =1; i<=n; i++)
            res = max(res , time[i]);

        if(res == INT_MAX)
            return -1;
            
        return res;  
    }


};
