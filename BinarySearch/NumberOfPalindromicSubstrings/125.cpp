/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 125.cpp
 * Created on : Sat Jun 12 2021
 ****************************************************************
 */

int solve(string s) {

    int n = s.size();

    vector<vector<bool> > dp(n, vector<bool> (n,false));
    int count  = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; i+j<n; j++)
        {
            int x = j;
            int y = i+j;

            if(i==0)
                dp[x][y] = true;
            else if(i==1)
            {
                if(s[x] == s[y])
                    dp[x][y] = true;
            }    
            else 
            {
                if(s[x] == s[y] && dp[x+1][y-1])
                    dp[x][y] = true;
            }
            if(dp[x][y])
                count++;

        }
    }
    return count;
}
/*

         t a c o c a t
       t 1 0 0 0 0 0 1
       a.  1 0 0 0 1 0
       c.    1 0 1 0 0
       o.      1 0 0 0
       c         1 0 0  
       a           1 0
       t             1 
*/
