/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MostStonesRemovedWithSameRowOrColumn.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */


class Solution {
public:
    unordered_map<int, vector<int> > X,Y;
    unordered_set<string> visited;
    void dfsX(int x)
    {
        for(auto i : X[x])
        {
            string hash = to_string(x) + "," + to_string(i);
            if(!visited.count(hash))
            {
                visited.insert(hash);
                dfsY(i);
            }
        }
    }
    void dfsY(int y)
    {
        for(auto i : Y[y])
        {
            string hash = to_string(i) + "," + to_string(y);
            if(!visited.count(hash))
            {
                visited.insert(hash);
                dfsX(i);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        X.clear(),Y.clear();
        
        for(auto v : stones)
        {
            X[v[0]].push_back(v[1]);
            Y[v[1]].push_back(v[0]);
        }
        
        int count = 0;
        for(auto v : stones)
        {
            string check = to_string(v[0])+","+to_string(v[1]);
            if(!visited.count(check))
            {
                dfsX(v[0]);
                dfsY(v[1]);
                count++;    
            }   
        }
        
        return stones.size() - count;
        
        
    }
};



