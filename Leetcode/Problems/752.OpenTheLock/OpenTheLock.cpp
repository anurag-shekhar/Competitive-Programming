/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : OpenTheLock.cpp
 * Created on : Fri Jun 04 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_set<string> visited;
    
    vector<string> neighbours(string s)
    {
        vector<string> res;
        
        string temp = s;
        vector<int> dir = {1,-1};
        for(int i = 0; i<s.size(); i++)
        {
            for(int j = 0; j<2; j++)
            {
                int val = temp[i]-'0';
                val = ((val + dir[j]+10)%10);
                temp[i] = (val+'0');
                
                if(!visited.count(temp))
                    res.push_back(temp);
                temp[i] = s[i];
            }
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        
        string start = "0000";
        queue<pair<string,int> > q;
        
        for(string d : deadends)
            visited.insert(d);
        if(!visited.count(start))
            q.push({start,0});
        visited.insert(start);

        while(!q.empty())
        {
            pair<string, int> p = q.front();
            q.pop();
        
            if(p.first == target)
                return p.second;
            
            
            vector<string> n = neighbours(p.first);
            
            for(string a : n)
            {
                q.push({a,p.second+1});
                visited.insert(a);
            }
                
        }
        return -1;
    }
};
