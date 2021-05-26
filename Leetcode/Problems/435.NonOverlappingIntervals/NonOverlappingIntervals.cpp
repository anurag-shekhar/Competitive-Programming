/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NonOverlappingIntervals.cpp
 * Created on : Thu May 27 2021
 ****************************************************************
 */

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1] || (a[1]==b[1] && a[0]<b[0]);
    }
    int eraseOverlapIntervals(vector<vector<int> >& A) {
        
        sort(A.begin(), A.end(), compare);
        
        int n = A.size();
        int count = 0;
        int lastTime = A[0][1];
        for(int i = 1; i<n; i++)
        {
            if(lastTime <= A[i][0])
                lastTime = A[i][1];
            else 
                count++;
        }
        return count;
    }
};
