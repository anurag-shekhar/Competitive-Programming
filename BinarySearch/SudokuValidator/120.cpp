/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 120.cpp
 * Created on : Wed Jul 07 2021
 ****************************************************************
 */

bool solve(vector<vector<int>>& matrix) {
    vector<vector<bool> > row(9,vector<bool> (9, false)), col(9,vector<bool> (9, false)), unit(9, vector<bool> (9, false));

    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            if(matrix[i][j] >9 || matrix[i][j] <=0)
                return false;
            if(col[j][matrix[i][j]-1])
                return false;
            if(row[i][matrix[i][j]-1])
                return false;
            int x = i/3;
            int y = j/3;

            if(unit[x*3+y][matrix[i][j]-1])
                return false;
            col[j][matrix[i][j]-1] = true;
            row[i][matrix[i][j]-1] = true;
            unit[x*3+y][matrix[i][j]-1] = true;
        }
    }
    return true;
}
