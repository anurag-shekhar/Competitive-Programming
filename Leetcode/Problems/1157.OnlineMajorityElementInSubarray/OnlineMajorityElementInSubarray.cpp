/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : OnlineMajorityElementInSubarray.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */

class MajorityChecker {
public:
    unordered_map<int, vector<int> > num_idx;
    vector<int> num;
    MajorityChecker(vector<int>& arr) {
        for(int i = 0; i<arr.size();i++)
        {
            num_idx[arr[i]].push_back(i);
            num.push_back(arr[i]);
        }
            
    }
    
    int query(int left, int right, int threshold) {
        
        for(int i = 0; i<10; i++)
        {
            int idx = rand()%(right-left+1) + left;
            
            auto itr = num_idx.find(num[idx]);
            if(itr->second.size() < threshold)
                continue;
            
            auto l = lower_bound(itr->second.begin(), itr->second.end(), left);
            auto r = upper_bound(itr->second.begin(), itr->second.end(), right);
            if(r-l >= threshold) return num[idx];
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
