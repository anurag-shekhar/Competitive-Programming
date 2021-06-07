/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PositionsOfLargeGroups.cpp
 * Created on : Tue Jun 08 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        
        vector<vector<int> > res; 
        int n = s.size();
        
        for(int i = 0; i<n; i++)
        {
            char ch = s[i];
            int count = 0;
            int j = i;
            while(i<n && s[i]==ch)
                i++;
            i--;
            if(i-j+1>=3)
            {
                res.push_back({j,i});
            }
        }
        return res;
    }
};
