/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TheEarliestAndLatestRoundsWherePlayersCompete.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    
    int first;
    int second;
    int minRound = INT_MAX;
    int maxRound = INT_MIN;
    void fill(vector<int> &match, vector<int> &newMatch , int left, int right, int idxL, int idxR, int round)
    {
        if(left>right)
        {
            backtrack(newMatch, round+1);
            return;
        }
        
        if((match[left] == first && match[right] == second) || (match[left] == second && match[right] == first))
        {
            minRound = min(minRound, round);
            maxRound = max(maxRound, round);
            return;
        }
        if(match[left]==first || match[left]==second)
        {
            newMatch[idxL] = match[left];
            fill(match, newMatch, left+1, right-1, idxL+1, idxR, round);
            return;
        }
        if(match[right]==first || match[right]==second)
        {
            newMatch[idxR] = match[right];
            fill(match, newMatch, left+1, right-1, idxL, idxR-1, round);
            return;
        }
        newMatch[idxL] = match[left];
        fill(match, newMatch, left+1, right-1, idxL+1, idxR, round);
        newMatch[idxR] = match[right];
        fill(match, newMatch, left+1, right-1, idxL, idxR-1, round);
    }
    void backtrack( vector<int> &match, int round)
    {
        int left = 0;
        int right = match.size()-1;
        
        int size = match.size()/2;
        if(match.size()%2)
            size++;    
        vector<int> newMatch(size);
        fill(match, newMatch, left, right, 0,size-1, round); 
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> match(n,0);
        first = firstPlayer;
        second = secondPlayer;
        
        for(int i = 0; i<n; i++)
            match[i] = i+1;
        
        backtrack(match, 1);
        return {minRound, maxRound};
        
    }
};
