/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PairsOfSongsWithTotalDurationsDivisibleBy60_2.cpp
 * Created on : Fri Jul 19 2024
 ****************************************************************
 */

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> m;
        int n = time.size();
        int result = 0;
        for(int i = 0; i<n; i++) {
            int time = time[i]%60;
            int findTime = (60-time) % 60;
            result += m[findTime];
            m[time]++;
        }
        return result;
    }
};