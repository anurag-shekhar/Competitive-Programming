/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FirstUniqueCharacterString.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> idxMap;
        for(char i : s)
            idxMap[i]++;
    
        for(int i=0; i<s.size(); i++)
        {
            if(1==idxMap[s[i]])
                return i;    
        }
        return -1;
            
    }
};
