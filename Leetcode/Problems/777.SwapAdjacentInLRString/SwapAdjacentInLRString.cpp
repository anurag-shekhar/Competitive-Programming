/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SwapAdjacentInLRString.cpp
 * Created on : Mon Jun 28 2021
 ****************************************************************
 */

class Solution {
public:
    bool canTransform(string start, string end) {
        
        if(start.size() != end.size())
            return false;
        int n = start.size();
        
        int sX = 0, eX = 0;
        
        for(int i = 0; i<n; i++)
        {
            if(start[i]=='X')
                sX++;
            if(end[i] == 'X')
                eX++;
        }
        if(sX != eX)
            return false;
        
        int sIdx = 0;
        int eIdx = 0;
        while(sIdx < n && eIdx < n)
        {
            while(sIdx < n && start[sIdx] == 'X')
                sIdx++;
            while(eIdx < n && end[eIdx] == 'X')
                eIdx++;
           if(start[sIdx] != end[eIdx] || (start[sIdx] =='L' && sIdx < eIdx) || (start[sIdx] == 'R' && sIdx > eIdx))
                return false;
            
            sIdx++;
            eIdx++;
        }

        return true;
    }
};
