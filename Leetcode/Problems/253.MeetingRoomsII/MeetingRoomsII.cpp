/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MeetingRoomsII.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& A) {
        
        int n = A.size();
        vector<int> startTime(n),endTime(n);
        
        for(int i = 0; i<n; i++)
        {
            startTime[i] = A[i][0];
            endTime[i] = A[i][1];
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        
        int currRoom = 0,maxRoom = 0;
        int startPtr = 0,endPtr = 0;
        while(startPtr < n)
        {
            if(startTime[startPtr] < endTime[endPtr])
            {
                startPtr++;
                currRoom++;
            }   
            else 
            {
                endPtr++;
                currRoom--;
            }
            maxRoom = max(maxRoom, currRoom);
            
        }
        return maxRoom;
        
    
    }
};
