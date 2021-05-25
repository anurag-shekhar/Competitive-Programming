/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumDominoRotationsForEqualRow.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        
        vector<bool> diceNumber(7,true);
        int n = tops.size();
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 1; j<=6; j++)
            {
                if(j!=tops[i] && j!=bottoms[i])
                    diceNumber[j] = false;
            }
        }
        
        unordered_map<int,vector<int> > candidate;
        
        for(int j = 1; j<=6; j++)
        {
            if(diceNumber[j])
                candidate[j] = {0,0};
        }
        if(candidate.size()==0)
            return -1;
        
        for(int i = 0; i<n; i++)
        {
            if(diceNumber[tops[i]] && bottoms[i]!=tops[i])
                candidate[tops[i]][0]++;
            if(diceNumber[bottoms[i]] && bottoms[i]!=tops[i])
                candidate[bottoms[i]][1]++;
        }       
        
        int res = INT_MAX;
        for(pair<int,vector<int> > p: candidate)
        {
            res = min(res, min(p.second[0], p.second[1]));
        }
        return res;
    }
};
