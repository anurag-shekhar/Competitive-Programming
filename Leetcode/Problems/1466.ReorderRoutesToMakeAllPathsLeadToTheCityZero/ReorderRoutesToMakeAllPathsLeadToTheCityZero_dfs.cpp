/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReorderRoutesToMakeAllPathsLeadToTheCityZero_dfs.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

class Solution {
public:
    int res;
    unordered_map<int, unordered_set<int> > in, out;
    
    void dfs(int root)
    {
        for(int a : out[root])
        {
            res++;
            in[a].erase(root);
            dfs(a);
        }
        for(int a : in[root])
        {
            
            out[a].erase(root);
            dfs(a);
        }
        
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        res = 0;
        in.clear();
        out.clear();
        for(auto c : connections)
        {
            out[c[0]].insert(c[1]);
            in[c[1]].insert(c[0]);
        }
        dfs(0);
        return res;
        
            
            
    }
};
