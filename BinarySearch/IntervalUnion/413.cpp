/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 413.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool compare(vector<int> &a, vector<int> &b)
{
    if(a[0] < b[0])
        return true;
    return false;    
}

vector<vector<int>> solve(vector<vector<int>>& intervals) {
    
    sort(intervals.begin(), intervals.end(), compare);

    int n = intervals.size();
    vector<vector<int> > res;
    for(int i = 0; i<n; i++)
    {
        if(res.size()==0 || res.back()[1] < intervals[i][0])
            res.push_back(intervals[i]);
        else
            res.back()[1] = max(res.back()[1] , intervals[i][1]);    
    }
    return res;


}
