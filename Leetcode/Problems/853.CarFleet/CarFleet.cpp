/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CarFleet.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<vector<int > > cars;
        
        int n = speed.size();
        if(n==0)
            return 0;
        
        for(int i = 0; i<n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), compare);
        
        vector<double> timeToDest;
        
        for(int i = 0; i<n; i++)
        {
            timeToDest.push_back((target-cars[i][0])/(double)cars[i][1]);
        }
        
        unordered_set<double> s;
        s.insert(timeToDest[n-1]);
        for(int i = n-2; i>=0; i--)
        {
            timeToDest[i] = max(timeToDest[i+1], timeToDest[i]);
            s.insert(timeToDest[i]);
        }
        
        return s.size();
    }
};
/*
10 8 0 5 3
2  4 1 1 3

12  3  7  1  1
0 3 5 8 10   12
1 3 1 4 2
*/
