/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 359.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

#define ld long double

bool isValid(int x, int y, int n)
{
    if(0<=x && 0<=y && x<n && y<n)
        return true;
    return false;    
}
ld numSteps(vector<vector<vector<ld> > > &dp, int i,int j,int step, int n)
{
    if(step == 0)
        return 1;
    if(dp[i][j][step] != -1)
        return dp[i][j][step];
    dp[i][j][step] = 0;    
    int dx[] = {2,  2,  1, -1, -2, -2, -1, 1};
    int dy[] = {1, -1, -2, -2, -1,  1,  2, 2};

    for(int k = 0; k<8; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if(isValid(x,y,n))
            dp[i][j][step] += numSteps(dp, x, y, step-1, n); 
    }    
    dp[i][j][step] /= 8.0;
    return dp[i][j][step];
}

int solve(int n, int x, int y, int k) {

    vector<vector<vector<ld> > > dp(n,vector<vector<ld>>(n, vector<ld> (k+1, -1)));

    ld totalInsidePositions = numSteps(dp, x, y, k, n);

    ld percentage = totalInsidePositions * 100;

    return percentage;

}
