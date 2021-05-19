/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumKnightMoves.cpp
 * Created on : Wed May 19 2021
 ****************************************************************
 */

class Solution {
public:
    class pt
    {
        public: 
        int x;
        int y;
        int dist;
        pt(int a, int b,int c):x(a), y(b), dist(c){}
    };
    
    int minKnightMoves(int x, int y) {
        
        queue<pt*> q1,q2;
        x = abs(x);
        y = abs(y);
        
        int dx[] = {1,2,-1, 2,  1, -1, -2, -2};
        int dy[] = {2,1,2,-1, -2, -2,  -1, 1};
        
        q1.push(new pt(0,0,0));
        q2.push(new pt(x,y,0));
        unordered_map<int,unordered_map<int,pair<bool,int> > > visited1, visited2;
        visited1[0][0] = make_pair(true, 0);
        visited2[x][y] = make_pair(true, 0);
        
        int res = INT_MAX;
        while(1)
        {
            pt* p1 = q1.front();
            q1.pop();
            pt* p2 = q2.front();
            q2.pop();    
            
            if(visited2[p1->x][p1->y].first)
                return p1->dist + visited2[p1->x][p1->y].second;
            if(visited1[p2->x][p2->y].first)
                return p2->dist + visited1[p2->x][p2->y].second;

            for(int k = 0; k<8; k++)
            {
                int i = p1->x+dx[k];
                int j = p1->y+dy[k];
                
                
                if(!visited1[i][j].first && i>=-1 && j>=-1)
                {
                    visited1[i][j] = make_pair(true, p1->dist+1);
                    q1.push(new pt(i,j,p1->dist+1));
                }
                i = p2->x+dx[k];
                j = p2->y+dy[k];
                
                if(!visited2[i][j].first && i>=-1 && j>=-1)
                {
                    visited2[i][j] = make_pair(true, p2->dist+1);
                    q2.push(new pt(i,j,p2->dist+1));
                }
            
            }
        }    
        return -1;
    }
};
/*
-99
142
*/
