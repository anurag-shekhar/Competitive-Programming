/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GroupShiftedStrings.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    
    int findDist(char c1, char c2)
    {
        int idx1 = c1-'a';
        int idx2 = c2-'a';
        
        if(idx2 > idx1)
            return (idx2-idx1);
        return (26+idx2-idx1);
        
    }
    bool isCyclicShift(string A, string B)
    {
       if(A.size() != B.size())
           return false;
        int shift = findDist(A[0], B[0]);
        for(int i = 1; i<A.size(); i++)
        {
            int check = findDist(A[i], B[i]);
            if(check != shift)
                return false;
        }
        return true;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<vector<string> > res;
        unordered_map<string, vector<string> > group;  
        bool flag = false;
        for(string A : strings)
        {
            flag = true;
            for(auto p : group)
            {
                if(isCyclicShift(p.first, A))
                {
                    group[p.first].push_back(A);
                    flag = false;
                    break;
                }
            }
            if(flag)
                group[A].push_back(A);
        }
        
        for(auto p : group)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
