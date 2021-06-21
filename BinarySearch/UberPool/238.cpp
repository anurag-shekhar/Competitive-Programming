/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 238.cpp
 * Created on : Tue Jun 22 2021
 ****************************************************************
 */

bool compare(vector<int> &a, vector<int> &b)
{
    if(a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]))
        return true;
    return false;
}
bool solve(vector<vector<int>>& trips, int capacity) {
    vector<vector<int> > timeline;

    for(auto t : trips)
    {
        timeline.push_back({t[0], 0-t[2]});
        timeline.push_back({t[1], t[2]});
    }
    sort(timeline.begin(), timeline.end(), compare);


    for(auto t : timeline)
    {
        capacity += t[1];
        if(capacity< 0)
            return false;
    }
    return true;
}
