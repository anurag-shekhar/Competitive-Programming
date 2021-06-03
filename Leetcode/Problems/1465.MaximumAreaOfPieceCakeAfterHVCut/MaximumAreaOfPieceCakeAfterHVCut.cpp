/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumAreaOfPieceCakeAfterHVCut.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

#define ll long long
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int> vCuts) {
            
        hCuts.push_back(0);
        hCuts.push_back(h);
        vCuts.push_back(0);
        vCuts.push_back(w);
        
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        
        int maxHeight = 0,maxWidth = 0;
        
        for(int i=1; i<hCuts.size(); i++)
        {
            maxHeight = max(maxHeight, hCuts[i]-hCuts[i-1]);
        }
        for(int i=1; i<vCuts.size(); i++)
        {
            
            maxWidth = max(maxWidth, vCuts[i]-vCuts[i-1]);
        }
        //cout<<1e9;
        int N = 1e9+7;
        ll maxW = maxWidth%N;
        ll maxH = maxHeight%N;
        return (maxH*maxW)%N;
    }
};
