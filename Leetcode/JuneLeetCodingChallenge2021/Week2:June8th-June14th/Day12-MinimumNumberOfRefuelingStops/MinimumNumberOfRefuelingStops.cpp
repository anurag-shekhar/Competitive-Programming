/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumNumberOfRefuelingStops.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int> maxHeap;
        
        int currPos = startFuel; 
        int noOfStops = 0;
        
        
        for(auto s : stations)
        {
            int stationPos = s[0];
            int stationFuel = s[1];
            
            while(currPos < stationPos)
            {
                if(maxHeap.empty())
                    return -1;
                int fuel = maxHeap.top();
                maxHeap.pop();
                currPos += fuel;
                noOfStops++;
            }
            maxHeap.push(stationFuel);
        }
        while(currPos < target)
        {
            if(maxHeap.empty())
                return -1;
            int fuel = maxHeap.top();
            maxHeap.pop();
            currPos += fuel;
            noOfStops++;
        }
        return noOfStops;
    }
};

/*
1000
83
[[47,220],[65,1],[98,113],[126,196],[186,218],[320,205],[686,317],[707,325],[754,104],[781,105]]
 
1000
75
[[14,41],[55,70],[88,26],[102,34],[179,63],[230,24],[238,58],[258,59],[280,50],[314,46],[317,66],[345,14],[393,72],[417,66],[523,27],[528,1],[567,75],[621,68],[636,48],[669,74],[786,12],[806,23],[809,30],[815,13],[904,14]] 
 1 2 3 4 5 6
*/
