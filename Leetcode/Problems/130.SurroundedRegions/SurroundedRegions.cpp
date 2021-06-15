/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SurroundedRegions.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    int r, c;
    bool isValid(int i, int j)
    {
        if(0<=i && 0<=j && i<r && j<c)
            return true;
        return false;    
    }
    void fillZero( vector<vector<char>>& matrix, int i, int j, char fill, char check)
    {
        if(matrix[i][j]!=check)
            return;
        matrix[i][j]=fill;
        int dx[] = { 1, 0, -1, 0 };
        int dy[] = { 0, 1, 0, -1};

        for(int k = 0; k<4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k]; 
            if(isValid(x,y))
                fillZero(matrix, x, y,fill,check);
        }

    }
    void solve(vector<vector<char>>& matrix) {

        r = matrix.size();
        c = matrix[0].size();
        
        for(int i = 0; i<r; i++)
        {
            fillZero(matrix, i, 0, '#', 'O');
            fillZero(matrix, i, c-1, '#', 'O');
        }
        for(int j = 0; j<c; j++)
        {
            fillZero(matrix, 0, j, '#', 'O');
            fillZero(matrix, r-1, j, '#', 'O');
        }
        for(int i = 1; i<r-1; i++)
        {
            for(int j = 1; j<c-1; j++)
            {
                fillZero(matrix, i, j, 'X', 'O');
            }   
        }
        for(int i = 0; i<r; i++)
        {
            fillZero(matrix, i, 0, 'O', '#');
            fillZero(matrix, i, c-1, 'O', '#');
        }
        for(int j = 0; j<c; j++)
        {
            fillZero(matrix, 0, j, 'O', '#');
            fillZero(matrix, r-1, j, 'O', '#');
        }
    }
};
