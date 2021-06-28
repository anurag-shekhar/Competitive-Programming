/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : JewelsAndStones.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        
        for(char c : jewels)
            s.insert(c);
        
        int res = 0;
        for(char c : stones)
            if(s.count(c))
                res++;
        return res;
        
    }
};
