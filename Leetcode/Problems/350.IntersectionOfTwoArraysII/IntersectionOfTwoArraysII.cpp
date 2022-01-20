/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : IntersectionOfTwoArraysII.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        unordered_map<int, int> m;
        
        for(int i = 0;i<nums1.size(); i++)
            m[nums1[i]]++;
        for(int i = 0;i<nums2.size(); i++)
        {
            if(m[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return res;
        
    }
};
