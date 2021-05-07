class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n,false));
        
        int start=0,end=0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; i+j<n; j++)
            {
                if(j== i+j)
                   dp[j][i+j] =true;
                else if(j+1 == i+j)
                {
                     if(s[j]==s[i+j]) 
                    {    
                        dp[j][i+j] = true;
                        start = j;
                        end = i+j;
                    }
                    else 
                        dp[j][i+j] = false;
                }
                else 
                {
                    if(s[j]==s[i+j] && dp[j+1][i+j-1]) 
                    {    
                        dp[j][i+j] = dp[j+1][i+j-1];
                        start = j;
                        end = i+j;
                    }
                }    
            }
        }

        // for(vector<int> v : dp){
        //     for(int a : v)
        //         cout<< a << " ";
        // cout<<endl;
        // }
        return s.substr(start,end - start +1 );
    }
};
