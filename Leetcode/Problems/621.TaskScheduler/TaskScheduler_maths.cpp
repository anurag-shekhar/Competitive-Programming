/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TaskScheduler_maths.cpp
 * Created on : Fri May 21 2021
 ****************************************************************
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26,0);
        for(char ch : tasks)
            freq[ch-'A']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        int res = tasks.size();
        int idleTime = (freq[0]-1) * n;

        
        int i = 1;
        while(i<freq.size() && freq[i-1] == freq[i]) i++;
        int numOfMaxFreqEle = i;
        
        res = max (res , (freq[0]-1)*(n+1) + numOfMaxFreqEle);
        
        
        return res;
    }
};

/*
A B C A B C D _ _ D


A B C D A B C D
*/
