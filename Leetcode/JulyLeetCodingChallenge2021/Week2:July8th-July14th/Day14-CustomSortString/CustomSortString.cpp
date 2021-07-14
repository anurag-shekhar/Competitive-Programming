/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CustomSortString.cpp
 * Created on : Wed Jul 14 2021
 ****************************************************************
 */

unordered_map<char, int> m;
class Solution {
public:
    
    static bool compare(char &a, char &b)
    {
        if(m[a] < m[b])
            return true;
        return false;
    }
    string customSortString(string order, string str) {
        
        m.clear();
        for(int i = 0; i<order.size(); i++)
            m[order[i]] = i;
        
        sort(str.begin(), str.end(), compare);
        return str;
    }
};
