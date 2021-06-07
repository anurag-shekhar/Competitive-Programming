/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReductionOperationsToMakeTheArrayElementsEqual.cpp
 * Created on : Tue Jun 08 2021
 ****************************************************************
 */

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        map<int, int> m;
        
        for(int a : nums)
            m[a]++;
        
        int count = 0;
        while(m.size()!=1)
        {
            auto itr = m.rbegin();
            auto prev_itr = next(itr);
            
            count+=itr->second;
            prev_itr->second += itr->second;
            m.erase(itr->first);
        }
        return count;
        
    }
};
