/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PacificAtlanticWaterFlow.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<pair<int, int> > > islandReach;
    int r,c;
    bool isValid(int x, int y)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    void flow(vector<vector<int> > &island, int i, int j, char ocean)
    {
        if(ocean=='P')
            islandReach[i][j].second = 1;
        if(ocean=='A')
            islandReach[i][j].first = 1;
        
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        for(int k = 0; k<4; k++)
        {
            int x = i+dx[k];
            int y = j+dy[k];
            
            if(isValid(x,y) && island[x][y] >= island[i][j])
            {
                if(ocean=='P' && islandReach[x][y].second != 1)
                {
                    flow(island, x,y,ocean);
                }
                if(ocean=='A' && islandReach[x][y].first != 1)
                {
                    flow(island, x,y,ocean);
                }
            }
        }
        
    }   

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& island) {
        
	    r = island.size();
	    c = island[0].size();
	
	    islandReach = vector<vector<pair<int, int> > > (r, vector<pair<int,int> > (c, make_pair(0,0)));
        vector<vector<int> > result;
	    
        
        for(int i = 0; i<r; i++)
        {
            flow(island, i, 0,'P');
            flow(island, i, c-1,'A');
        }
        for(int i = 0; i<c; i++)
        {
            flow(island, 0, i,'P');
            flow(island, r-1, i,'A');
        }
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                 if(islandReach[i][j].first && islandReach[i][j].second)
                    result.push_back({i,j});
            }
        }
        return result;

    }   
};



