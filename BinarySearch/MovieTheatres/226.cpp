/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 226.cpp
 * Created on : Wed Jul 07 2021
 ****************************************************************
 */

int solve(vector<vector<int>>& intervals) {
    
    map<int, int> timeline;

    for(auto v : intervals)
    {
        timeline[v[0]]++;
        timeline[v[1]]--;
    }

    int numTheatre = 0;
    int currTheatre = 0;
    for(auto p : timeline)
    {
        currTheatre += p.second;
        numTheatre = max(numTheatre, currTheatre);
    }
    return numTheatre;


}
