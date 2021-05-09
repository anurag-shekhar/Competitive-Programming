/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 758.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(string a, string b) {

    
    int r = b.size();
    int c = a.size();
    if(r==0)
        return c;
    if(c==0)
        return r;    
    vector<vector<int> > dp(r, vector<int>(c));

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = b[i] == a[j] ? 0 : 2;
            else if(i==0)
                dp[i][j] = b[i] == a[j] ? j : dp[i][j-1]+1;
            else if(j==0)
                dp[i][j] = b[i] == a[j] ? i : dp[i-1][j]+1;
            else 
                dp[i][j] = b[i] == a[j] ? dp[i-1][j-1] : min(dp[i-1][j], dp[i][j-1]) +1;  

        }
    }

    return dp[r-1][c-1];
    
}



/*
      z  y  y  x
    y 2  1  2  3        
    f 3  2  3  4            
    y 4. 3  2. 3          
    x 5            

*/
