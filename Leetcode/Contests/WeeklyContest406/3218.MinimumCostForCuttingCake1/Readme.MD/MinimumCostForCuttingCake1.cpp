/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumCostForCuttingCake1.cpp
 * Created on : Mon Jul 15 2024
 ****************************************************************
 */

class Solution {
public:
    long long helper(int v_box, int h_box, vector<int>& horizontalCut, vector<int>& verticalCut /*vector<pair<int,int> > h_cut, vector<pair<int,int> > v_cut*/) {
        
        int v_idx = 0, h_idx = 0;
        long long cost = 0;
        while(v_idx < verticalCut.size() && h_idx < horizontalCut.size()) {
            if(horizontalCut[h_idx] >= verticalCut[v_idx]) {
                cost += horizontalCut[h_idx++] * h_box;
                v_box++;
            } else {
                cost += verticalCut[v_idx++] * v_box;
                h_box++;
            }
        }
         while(v_idx < verticalCut.size()) {
             cost += verticalCut[v_idx++] * v_box;
         }
        while(h_idx < horizontalCut.size()) {
             cost += horizontalCut[h_idx++] * h_box;
         }
        return cost;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        return helper(1,1,horizontalCut, verticalCut);
    }
};