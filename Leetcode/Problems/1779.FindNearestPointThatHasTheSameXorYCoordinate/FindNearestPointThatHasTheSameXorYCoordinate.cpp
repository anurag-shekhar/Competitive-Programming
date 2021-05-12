/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindNearestPointThatHasTheSameXorYCoordinate.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
    int manDist(int a, int b){
        return abs(a-b);
    }
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        
        int resMin = -1;
        int resDist = INT_MAX;
          
        for(int i = 0; i<points.size(); i++)
        {
            int dist = INT_MAX;
            if(x==points[i][0]){
                dist = manDist(y,points[i][1]);
            }
            else if(y==points[i][1]) {
                dist = manDist(x,points[i][0]) ;               
            } 
            if(resDist > dist)
            {
                resDist = dist;
                resMin = i;
            }
        }
        return resMin;
        
    }
};
