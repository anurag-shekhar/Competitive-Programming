/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumAreaRectangle_2.cpp
 * Created on : Sun Jun 23 2024
 ****************************************************************
 */

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        set<vector<int> > s;
        for(auto p : points) {
            s.insert(p);
        }
        int minArea = INT_MAX;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i!=j && points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    vector<int> p3 =  {points[i][0], points[j][1]};
                    vector<int> p4 =  {points[j][0], points[i][1]};
                    
                    if(s.find(p3)!=s.end() && s.find(p4)!=s.end()) {
                        long area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                        minArea = min(minArea, (int)area);
                    }
                }
            }
        }
        if(minArea == INT_MAX)
            return 0;
        return minArea;
    }
};