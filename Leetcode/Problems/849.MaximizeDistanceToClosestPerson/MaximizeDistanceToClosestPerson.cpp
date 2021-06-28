/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximizeDistanceToClosestPerson.cpp
 * Created on : Mon Jun 28 2021
 ****************************************************************
 */

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        vector<int> occupied;
        int n = seats.size();
        for(int i = 0; i<seats.size(); i++)
        {
            if(seats[i]==1)
                occupied.push_back(i);
        }
        
        int maxDist = occupied[0];
        
        for(int i = 1; i<occupied.size(); i++)
        {
            maxDist = max(maxDist, (occupied[i] - occupied[i-1])/2);
        }
        maxDist = max(maxDist, n-1-occupied.back());
        return maxDist;
    }
};
