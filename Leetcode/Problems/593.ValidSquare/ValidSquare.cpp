/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidSquare.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2)
    {
        return (p1[0]-p2[0])*(p1[0]-p2[0])  + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<vector<int> > points;
        
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        
        unordered_set<int> dist;
        for(int i = 0; i<4; i++)
        {
            for(int j = i+1; j<4; j++)
                dist.insert(distance(points[i], points[j]));
        }
        
        if(!dist.count(0) && dist.size()==2)
            return true;
        return false;
        
    }
};
