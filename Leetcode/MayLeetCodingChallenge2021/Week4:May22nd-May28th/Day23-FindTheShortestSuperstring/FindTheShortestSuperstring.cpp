/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindTheShortestSuperstring.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int> > cost, dp, path;
    int all_visited;
    bool checkPrefix(string a, string b)
    {
        if(b.size() > a.size()) return false;
        
        int n = b.size();
        for(int i = 0; i<n; i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    int getCost(string &a, string &b)
    {
        for(int i =0; i<a.size(); i++)
        {
            if(checkPrefix(b, a.substr(i)))
                return b.size() - a.size()+ i;
        }
        return b.size();
    }
    
    
    /*
    mask - to track of visited words
    pos - curr word and from here on we will be visiting other words.
    */
    int TSP(int mask, int pos, int n) 
    {
        if(mask== all_visited)
            return 0;
        
        if(dp[mask][pos]!=-1)
            return dp[mask][pos];
        
        int res = INT_MAX;
        int bestWordIdx = pos;
        
        for(int wordIdx = 0; wordIdx < n; wordIdx++)
        {
            if((mask & (1<<wordIdx)) == 0) //if the word is not visited
            {
                int localRes = cost[pos][wordIdx] + TSP(mask | (1<<wordIdx) , wordIdx, n);
                if(localRes < res)
                {
                    res = localRes;
                    bestWordIdx = wordIdx;
                }
            }
        }
        
        path[mask][pos] = bestWordIdx;
        dp[mask][pos] = res;
        return dp[mask][pos];
    }
    
    string constructPath(vector<string>& words, int startWordIdx)
    {
        int curr = startWordIdx;
        string res = words[curr];
        
        int mask = (1<<curr);
        int parent = path[mask][curr];
        
        while(parent != -1)
        {
            res += words[parent].substr(words[parent].size() - cost[curr][parent]);
            mask |= (1<<parent);
            curr = parent;
            parent = path[mask][parent];
        }
        return res;
    }
    string shortestSuperstring(vector<string>& words) {
        
        //Travelling salesman problem
        int n = words.size();
        
        cost = vector<vector<int> > (n,vector<int> (n,0));
        
        for(int i =0 ;i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cost[i][j] = getCost(words[i], words[j]);
            }
        }
        
        all_visited = (1<<n)-1;  // 111111
        int ansLen = INT_MAX;
        string ans = "";
        for(int startWordIdx = 0; startWordIdx<n; startWordIdx++)
        {
            dp = vector<vector<int> >((1<<n), vector<int> (n,-1));
            path = vector<vector<int> >((1<<n), vector<int> (n,-1));
            
            TSP((1<<startWordIdx), startWordIdx, n);
            
            string localAns = constructPath(words, startWordIdx);
            
            cout<<localAns<<endl;
            if(localAns.size() < ansLen)
            {
                ansLen = localAns.size();
                ans = localAns;
            }
        }
        return ans;
       
        
    }
};
