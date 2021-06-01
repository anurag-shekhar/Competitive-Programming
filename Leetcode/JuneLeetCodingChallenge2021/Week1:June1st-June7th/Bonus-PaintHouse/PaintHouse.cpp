/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PaintHouse.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

class Solution {
public:
    
    int minCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            firstMin = INT_MAX, secondMin = INT_MAX;
            for(int j = 0; j<3; j++)
            {
                if(i!=0)
                    costs[i][j] += costs[i-1][j];
                
                if(costs[i][j] < firstMin)
                {
                    secondMin = firstMin;
                    firstMin = costs[i][j];
                }
                else if(costs[i][j] < secondMin)
                    secondMin = costs[i][j];
            }
 
            for(int j = 0; j<3; j++)
            {
                if(costs[i][j]==firstMin)
                    costs[i][j] = secondMin;
                else
                    costs[i][j] = firstMin;
            }    
        }
        return firstMin;
        
    }
};

/*
    17  2  17
    16  5  16
    14  3  19
    
    
     2  17   2
    18  18  18
    32  21  27
    
*/
