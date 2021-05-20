/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : UniqueNumberOfOccurrences.cpp
 * Created on : Thu May 20 2021
 ****************************************************************
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int a : arr)
            m[a]++;
        
        for(pair<int, int> p : m)
           s.insert(p.second);
        
        if(s.size() == m.size())
            return true;
        return false;
        
    }
};
