/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TaskScheduler.cpp
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
         //Method1
        for(int i = 25; i>0; i--)
            idleTime -= min(freq[0]-1, freq[i]);
        
        if(idleTime > 0)
            res += idleTime;
        */    
        return res;
    }
};

/*
A B C A B C D _ _ D


A B C D A B C D
*/
