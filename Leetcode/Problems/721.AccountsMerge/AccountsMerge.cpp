/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AccountsMerge.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string> > graph;
    
    void dfs(string email, vector<string> &local)
    {
        if(email=="")
            return;
        visited.insert(email);
        local.push_back(email);
        for(string nextEmail : graph[email])
        {
            if(!visited.count(nextEmail))
                dfs(nextEmail, local);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        
        graph.clear();
        unordered_map<string, string> emailToName;
        visited.clear();
        
        for(int i = 0; i<accounts.size();i++)
        {
            emailToName[accounts[i][1]] = accounts[i][0];
            if(accounts[i].size()==2)
                graph[accounts[i][1]].push_back({""});
            else 
            {
                for(int j = 2; j<accounts[i].size(); j++)
                {
                    graph[accounts[i][j]].push_back(accounts[i][1]);
                    graph[accounts[i][1]].push_back(accounts[i][j]);
                    emailToName[accounts[i][j]] = accounts[i][0];
                } 
            }
            
        }
        
        vector<vector<string> > res;
        
        for(auto p : graph)
        {
            if(!visited.count(p.first))
            {
                vector<string> local;
                local.push_back(emailToName[p.first]);
                dfs(p.first, local);
                sort(local.begin()+1, local.end());
                res.push_back(local);
            }
        }
        return res;
    }
};


