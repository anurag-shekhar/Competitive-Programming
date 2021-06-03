/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumAreaOfPieceCakeAfterHVCut.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

#define MOD 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        
        
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long maxH = 0, maxW = 0;
        
        int h_size = horizontalCuts.size();
        for(int i = 1; i<h_size; i++)
        {
            maxH = max(maxH, (long)(horizontalCuts[i]-horizontalCuts[i-1]));
        }
        
        int w_size = verticalCuts.size();
        for(int i = 1; i<w_size; i++)
        {
            maxW = max(maxW, (long)(verticalCuts[i]-verticalCuts[i-1]));
        }
        maxW = maxW%MOD;
        maxH = maxH%MOD;
        
        return (maxW*maxH)%MOD;
    }
};