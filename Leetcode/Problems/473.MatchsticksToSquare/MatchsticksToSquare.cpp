/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MatchsticksToSquare.cpp
 * Created on : Wed Jun 16 2021
 ****************************************************************
 */

class Solution {
public:
    
    
    vector<int> side;
    bool dp(int idx)
    {
        for(int i =0; i<idx; i++)
        {
            if(side[i] == side[idx])
                return true;
        }
        return false;
    }
    bool backtrack(vector<int>& matchsticks, int pos, int target)
    {
        if(pos == matchsticks.size())
        {
            if(side[0] == target && side[1] == target && side[2] == target && side[3] == target)
                return true;
            return false;
        }
        
        for(int i = 0; i<4; i++)
        {
            if((side[i] + matchsticks[pos] > target) || dp(i))
                continue;
            
            side[i] += matchsticks[pos];
            if(backtrack(matchsticks, pos+1, target))
                return true;
            side[i] -= matchsticks[pos];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        side = vector<int> (4,0);
        
        int sum  = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        if(sum ==0 || (sum%4)!=0 || matchsticks.size()<4)
            return false;
        sum /= 4;
        return backtrack(matchsticks, 0, sum);
        
    }
};
