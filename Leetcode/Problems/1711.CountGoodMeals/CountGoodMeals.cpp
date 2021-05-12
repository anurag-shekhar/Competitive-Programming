/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountGoodMeals.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

#define MOD 1'000'000'007
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        
        unordered_map<int,int> m;
        int res = 0;
        for(int a : deliciousness)
        {
            for(int pow2 = 1; pow2 <= (1<<21); pow2*=2)
            {
                res = (res + m[pow2-a])%MOD;
            }
            m[a]++;
        }
        return res % MOD;
        
    }
};
