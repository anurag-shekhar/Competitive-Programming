/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : IncrementalMemoryLeak.cpp
 * Created on : Sat May 15 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        
        
        int i = 1;
        while(1)
        {
            int size = i;
            if(memory2 > memory1)
            {
                if((memory2 - size) < 0)
                    return {i, memory1, memory2};
                memory2 -= size;
            }
            else
            {
                
                if((memory1 - size) < 0)
                    return {i, memory1, memory2};
                memory1 -= size;
            }
            i++;
        }
        return {};
        
        
        
        
    }
};
