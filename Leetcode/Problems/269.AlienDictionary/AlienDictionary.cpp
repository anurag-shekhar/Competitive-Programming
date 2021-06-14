/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AlienDictionary.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        unordered_map<char, unordered_set<char> > m;
        unordered_map<char,int> indegree;
        
        int n = words.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<words[i].size(); j++)
            {
                indegree[words[i][j]] = 0;
            }
        }
        
        
        for(int i = 0; i<n-1; i++)
        {
            int minLen = min(words[i].size(), words[i+1].size());
            for(int j = 0; j<minLen; j++)
            {
                if(words[i][j] != words[i+1][j])
                {
                    if(!m[words[i][j]].count(words[i+1][j]))
                    {
                        m[words[i][j]].insert(words[i+1][j]);
                        indegree[words[i+1][j]]++;
                    }
                    break;
                }
                if(j==minLen-1 && words[i].size() > words[i+1].size())
                    return "";
            }
        }
        queue<char> q;
        
        for(pair<char, int> p : indegree)
        {
            if(p.second==0)
                q.push(p.first);
        }
        string res = "";
        while(!q.empty())
        {
            char ch = q.front();
            q.pop();
            res += ch;
            
            for(char c : m[ch])
            {
                indegree[c]--;
                if(indegree[c]==0)
                    q.push(c);
            }
        }
        
        if(res.size() != indegree.size())
            return "";
        return res;
        
    }
};
