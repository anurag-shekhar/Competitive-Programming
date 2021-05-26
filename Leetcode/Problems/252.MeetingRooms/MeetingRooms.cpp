/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MeetingRooms.cpp
 * Created on : Thu May 27 2021
 ****************************************************************
 */

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < a[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        for(int i = 1; i<n; i++)
        {
            if(intervals[i-1][1] > intervals[i][0])
                return false;
        }
        return true;
    }
};
