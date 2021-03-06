/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : XOfKindInDeckOfCards.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int, int> m;
        
        for(auto a : deck)
            m[a]++;
        
        int minBucket = m.begin()->second;
        bool firstFlag = true;
        for(auto p : m)
        {
            if(firstFlag)
            {
                firstFlag = false;
                continue;
            }
            minBucket = gcd(minBucket, p.second);
        }
        if(minBucket <2)
            return false;
        return true;
    }
};
