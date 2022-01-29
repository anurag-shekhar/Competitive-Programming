/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DeleteAndEarn.cpp
 * Created on : Sat Jan 29 2022
 ****************************************************************
 */

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        map<int, int> count;
        
        for(int a : nums)
            count[a]++;
        
        int first = 0, second = 0, res = 0;
        for(auto itr = count.begin(); itr!=count.end(); itr++)
        {
            int val = itr->second*itr->first;
            if(itr->first -1 == prev(itr)->first) 
                res = max(first + val, second);
            else 
                res += val;
            
            first = second;
            second = res;
        }
        return res;
    }
};
