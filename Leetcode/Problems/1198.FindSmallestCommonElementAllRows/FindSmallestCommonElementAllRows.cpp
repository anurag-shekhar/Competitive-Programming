/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindSmallestCommonElementAllRows.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        
        map<int ,int > m;
        int r = mat.size();
        int c = mat[0].size();
        
        for(vector<int> i : mat)
        {
            for(int j : i)
            {
                m[j]++;
            }
        }
        
        for(pair<int,int> i : m)
        {
            if(i.second == r)
                return i.first;
        }
        return -1;
        
    }
};
