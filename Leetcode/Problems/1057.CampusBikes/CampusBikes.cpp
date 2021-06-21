/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CampusBikes.cpp
 * Created on : Tue Jun 22 2021
 ****************************************************************
 */

class Solution {
public:
    int manhattanDist(vector<int> a, vector<int> b)
    {
        return abs(a[0]-b[0]) + abs(a[1] - b[1]);
    }
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
         
        
        map<int, vector<vector<int> > > m;
        vector<int> res(workers.size(), -1);
        vector<bool> bikeTaken(bikes.size(), false);
        for(int i = 0; i<bikes.size(); i++)
        {
            for(int j = 0; j<workers.size(); j++)
            {
                int dist = manhattanDist(bikes[i], workers[j]);
                m[dist].push_back({i,j});
            }
        }
        
        for(auto p : m)
        {
            for(vector<int> a : p.second)
            {
                if(bikeTaken[a[0]] || res[a[1]] != -1)
                    continue;
                else
                {
                    bikeTaken[a[0]] = true;
                    res[a[1]] = a[0];
                }
            }
        }
        return res;
    }
};
