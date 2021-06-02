/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumDistanceToTypeWordUsingTwoFingers.cpp
 * Created on : Wed Jun 02 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_map<int, pair<int,int> > keyboard;
    vector<vector<int > > dist;
    vector<vector<vector<int> > > dp;
    int n;
   
    int minCost(string &word, int idx, int f1, int f2)
    {
        if(idx==n)
            return 0;
        
        int curr = word[idx] -'A';

        if(dp[idx][f1][f2] == -1)
        {
            dp[idx][f1][f2] = min(dist[f1][curr] + minCost(word, idx+1, curr, f2) , dist[f2][curr] + minCost(word, idx+1, f1, curr));
        }
        return dp[idx][f1][f2];
        
    }
    int minimumDistance(string word) {
        
        int alpha = 0;
        for(int i = 0; i<5 && alpha <26 ; i++)
        {
            for(int j = 0; j<6 && alpha <26; j++)
            {
                keyboard[alpha++] = make_pair(i,j);
            }
        }
    
        n = word.size();
        dist = vector<vector<int > > (27, vector<int> (27,0));
        
        for(int i = 0; i<26; i++)
        {
            for(int j = i+1; j<26; j++)
            {
                int d = abs(keyboard[i].first - keyboard[j].first) + abs(keyboard[i].second - keyboard[j].second);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }
        
        dp = vector<vector<vector<int> > > (n, vector<vector<int>> (27, vector<int> (27, -1)));
        
        return minCost(word,0,26,26);
       
        
    }
};
