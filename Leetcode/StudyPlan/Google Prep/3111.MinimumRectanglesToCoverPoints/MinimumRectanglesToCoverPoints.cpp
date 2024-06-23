/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumRectanglesToCoverPoints.cpp
 * Created on : Sun Jun 23 2024
 ****************************************************************
 */

class Solution {
public:
    static bool compare(vector<int> a1, vector<int> b1) {
        return a1[0] < b1[0];
    }
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), compare);
        int n = points.size();
        int rectangles = 0;
        for(int i = 0; i<n; i++) {
            int x_start = points[i][0];
            int x_end = points[i][0];
            rectangles++;
            i++;
            while(i<n) {
                x_end = points[i][0];
                if(x_end - x_start > w)
                    break;
                i++;
            }
            i--;
        }
        return rectangles;
    }
};
