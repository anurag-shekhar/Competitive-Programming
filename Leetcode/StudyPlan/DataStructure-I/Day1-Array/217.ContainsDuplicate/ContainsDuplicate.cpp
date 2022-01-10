/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ContainsDuplicate.cpp
 * Created on : Mon Jan 10 2022
 ****************************************************************
 */


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int a : nums)
            s.insert(a);
        
        return nums.size() != s.size();
    }
};
