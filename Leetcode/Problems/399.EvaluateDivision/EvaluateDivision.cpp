/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : EvaluateDivision.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_map<string, vector<string> > edge;
    unordered_map<string, int> m;
    vector<vector<double> > cost;
    bool calculate(string s , string t, unordered_set<int> visited)
    {
        
        if(cost[m[s]][m[t]]!=0.0)
            return true;
        if(visited.count(m[s]))
            return false;
        visited.insert(m[s]);
        for(string e : edge[s])
        {
            
            if( visited.count(m[e])==0 && calculate(e,t,visited))
            {
               cost[m[s]][m[t]] = cost[m[s]][m[e]] *cost[m[e]][m[t]];
               return true;
            }
        }
        return false;
        
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        int assign_id = 0;
        for(auto e : equations)
        {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
            
            if(m.count(e[0])==0)
                m[e[0]] = assign_id++;
            if(m.count(e[1])==0)
                m[e[1]] = assign_id++;            
        }
        
        cost = vector<vector<double> >(assign_id, vector<double>(assign_id, 0.0));
        
        int n = values.size();
        for(int i = 0; i<n; i++)
        {
            cost[m[equations[i][0]]][m[equations[i][1]]] = values[i];
            cost[m[equations[i][1]]][m[equations[i][0]]] = 1.0/values[i];
            
            cost[i][i] = 1.0;
        }
        int mask = (1<<assign_id) - 1;
        vector<double> res;
        for(auto q : queries)
        {
            if(m.count(q[0]) ==0 || m.count(q[1]) ==0)
                res.push_back(-1.0);
            else
            {
                if(calculate(q[0],q[1], {}))
                    res.push_back(cost[m[q[0]]][m[q[1]]]);
                else 
                   res.push_back(-1.0); 
            }
                
        }
        return res;
    }
};
