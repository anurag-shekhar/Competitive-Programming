class cell
{
    public : 
    int left; 
    int right;
    int top; 
    cell(int a, int b, int c): left(a), right(b), top(c){} 
};

int solve(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<cell > > dp(r,vector<cell> (c,cell(0,0,0)));
    int res = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(matrix[i][j] == 1)
                continue;
            if(i==0)
            {
                dp[i][j].top = 1;
                if(j!=c-1)
                    dp[i][j].right = 1;
                if(j==0)
                    dp[i][j].left = 1;
                else 
                {
                    dp[i][j].left = max(dp[i][j-1].left, dp[i][j-1].top);
                    dp[i][j].left = dp[i][j].left==0 ? dp[i][j].left : dp[i][j].left+1;
                }  
            }
            else 
            {   
                dp[i][j].top = max(dp[i-1][j].top, max(dp[i-1][j].left, dp[i-1][j].right));
                dp[i][j].top = dp[i][j].top ==0 ? dp[i][j].top : dp[i][j].top + 1;

                if(j!=0)
                {
                    dp[i][j].left = max(dp[i][j-1].left, dp[i][j-1].top);
                    dp[i][j].left = dp[i][j].left==0 ? dp[i][j].left : dp[i][j].left+1;
                }  
            }
        }

        for(int j = c-1; j>=0; j--)
        {
            if(matrix[i][j] == 1)
                continue;
            if(i==0)
            {
                if(j!=c-1)
                {
                    dp[i][j].right = max(dp[i][j+1].right, dp[i][j+1].top);
                    dp[i][j].right = dp[i][j].right==0 ? dp[i][j].right : dp[i][j].right+1;
                }  
            }
            else 
            {
                if(j!=c-1)
                {
                    dp[i][j].right = max(dp[i][j+1].right, dp[i][j+1].top);
                    dp[i][j].right = dp[i][j].right==0 ? dp[i][j].right : dp[i][j].right+1;
                }  
            }   

            if(i==r-1)
                res = max(res, max(dp[i][j].top, max(dp[i][j].left, dp[i][j].right)));
        }
    }


    // for(vector<cell> v : dp)
    // {
    //     for(cell a : v)
    //         cout<<"("<<a.left<<","<<a.top<<","<<a.right<<") "<<" ";
    //     cout<<endl;    
    // }
    return res;

}


/*
0, 0, 0, 0
1, 0, 0, 0
0, 0, 0, 0

(1,1,4)  (2,1,3)  (3,1,2)  (4,1,0)  
(0,0,0)  (0,4,7)  (5,4,6)  (6,5,0)  
(0,0,10) (0,8,9)  (9,7,8)  (10,7,0)  
*/
