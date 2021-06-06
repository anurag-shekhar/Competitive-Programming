/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PalindromicSubstrings.cpp
 * Created on : Mon Jun 07 2021
 ****************************************************************
 */

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        string original = s;
        //reverse(s.begin(), s.end());
        vector<vector<bool> > dp(n, vector<bool> (n, false));
        
        int res = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j+i< n ; j++)
            {
                int x = j;
                int y = j+i;
            
                if(i==0)
                    dp[x][y] = true;
                else if(i==1)
                    dp[x][y] = (s[x] == original[y]);
                else 
                    dp[x][y] = (s[x] == original[y] && dp[x+1][y-1]);
                
                if(dp[x][y])
                    res++;
            }
        }
        return res;
    }
};


/*   
    a b c 
  a 
*/


   
