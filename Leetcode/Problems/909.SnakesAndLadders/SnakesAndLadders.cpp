/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SnakesAndLadders.cpp
 * Created on : Sun Feb 20 2022
 ****************************************************************
 */

class Solution {
public:
    
    vector<int> getCell(int x, int n)
    {
        int r = n-1 - (x-1)/n;
        int c = (x-1)%n;
        
        if(r%2==n%2)
            c = n - 1 - c;
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        vector<vector<bool > >  visited(n, vector<bool> (n,false)); 
        queue<vector<int> > q;
        q.push({1,0});
        
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            
            if(cell[0] == n*n)
                return cell[1];
            
            for(int k = 1; k<=6; k++)
            {
                int x = cell[0] + k;
                if(x > n*n)
                    break;
                vector<int> cordinates = getCell(x, n);
                if(visited[cordinates[0]][cordinates[1]])
                    continue;
                visited[cordinates[0]][cordinates[1]] = true;
                if(board[cordinates[0]][cordinates[1]]!=-1)
                    q.push({board[cordinates[0]][cordinates[1]], cell[1]+1});
                else 
                    q.push({x, cell[1]+1});
                
            }
        }
        return -1;
    }
};