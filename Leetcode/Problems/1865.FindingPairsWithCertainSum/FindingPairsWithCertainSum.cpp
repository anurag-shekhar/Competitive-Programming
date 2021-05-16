/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindingPairsWithCertainSum.cpp
 * Created on : Mon May 17 2021
 ****************************************************************
 */

class FindSumPairs {
public:
    vector<int> A,B;
    unordered_map<int,int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        A = nums1;
        B = nums2;
        
        for(int a : nums2)
            m[a]++;
    }
    
    void add(int index, int val) {
        
        int v = B[index];
        B[index] += val;
        
        m[v]--;
        v += val;
        m[v]++;
    }
    
    int count(int tot) {
        
        int res = 0;
        for(int i = 0; i<A.size(); i++)
        {
            int val = tot - A[i];
            res += m[val];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
