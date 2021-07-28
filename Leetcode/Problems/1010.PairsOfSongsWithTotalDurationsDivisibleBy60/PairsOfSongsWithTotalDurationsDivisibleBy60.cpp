/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PairsOfSongsWithTotalDurationsDivisibleBy60.cpp
 * Created on : Wed Jul 28 2021
 ****************************************************************
 */

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int, int> m;
        int n = time.size();
        int res = 0;
        for(int i = 0;i<n; i++)
        {
            int val = time[i]%60;
            res += m[60 - val];
            if(val==0 )
                m[60]++;
            else 
                m[val]++;
        }
        return res;
    }
};
