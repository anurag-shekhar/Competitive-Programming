/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AndroidUnlockPatterns.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int> > skip;
    vector<bool> visited;
    int backtrack(int num, int count)
    {
        if(count==0)
            return 1;
        visited[num] = true;
        int res = 0;
        for(int i = 1; i<=9; i++)
        {
            if(!visited[i] && visited[skip[num][i]])
                res+=backtrack(i, count-1);
        }
        visited[num] = false;
        return res;
    }
    int numberOfPatterns(int m, int n) {
        skip = vector<vector<int> > (10,vector<int> (10,0));
        skip[1][9] = skip[9][1] = 5;
        skip[3][7] = skip[7][3] = 5;
        skip[2][8] = skip[8][2] = 5;
        skip[4][6] = skip[6][4] = 5;
        skip[1][3] = skip[3][1] = 2;
        skip[3][9] = skip[9][3] = 6;
        skip[9][7] = skip[7][9] = 8;
        skip[7][1] = skip[1][7] = 4;
        visited = vector<bool> (10, false);
        visited[0] = true;
        
        int res = 0;
        
        for(int i = m; i<=n; i++)
        {
            res += backtrack(1,i-1)*4;
            res += backtrack(2,i-1)*4;
            res += backtrack(5,i-1);  
        }
        return res;
    }
};
