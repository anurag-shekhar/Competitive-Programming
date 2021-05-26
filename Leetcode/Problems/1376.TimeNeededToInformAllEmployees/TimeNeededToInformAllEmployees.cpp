/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TimeNeededToInformAllEmployees.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    
    void dfs(int headID,vector<int> &time, vector<int>& informTime,   unordered_map<int, vector<int > > &edge, int currTime)
    {
        time[headID] = currTime;
        for(auto dr : edge[headID])
            dfs(dr ,time, informTime,  edge, currTime + informTime[headID]);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> time(n,INT_MAX);
        
        unordered_map<int, vector<int> > edge;
        
        for(int i = 0; i<manager.size(); i++)
            if(manager[i]!=-1)
                edge[manager[i]].push_back({i});
        
        dfs(headID, time,informTime,  edge, 0);
        int res = 0;
        for(int i = 0; i<n; i++)
        {
            if(i!=headID)
                res = max(res, time[i]);
        }
        return res;
    }
};
