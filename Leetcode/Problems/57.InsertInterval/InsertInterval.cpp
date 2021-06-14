/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : InsertInterval.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int> > res;
        
        int i = 0;
        
        while(i<n && newInterval[0] > intervals[i][0])
        {
            res.push_back(intervals[i]);
            i++;
        }   
        if(res.size()==0|| res.back()[1] < newInterval[0])
            res.push_back(newInterval);
        else 
        {
            res.back()[1] = max(res.back()[1], newInterval[1]);
        }
        
        while(i<n)
        {
            if(res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else 
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            i++;
        }
        return res;    
    }
};

/*

           |---------|    |----|    |--------|
1)   |---|
2)   |---------|
3)   |-----------------|
4)             |---|
5)             |-------|
6)             |-------------|
7).            |------------------|
8)                                        |---------|
9)                                                  |------|
*/
