/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FactorCombinations.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int> > res;
    int N;
    void backtrack(vector<int> local, int n, int val)
    {
        
        if(n<=1)
        {
            if(n==1 && local.size()!=0)
                res.push_back(local);
            return;
        }
        for(int i = val; i<=n && i<N; i++)
        {
            if(n%i==0)
            {
                //cout<<i<<endl;
                local.push_back(i);
                backtrack(local, n/i, i);
                local.pop_back();  
            }
            
        }
    }
    vector<vector<int> > getFactors(int n) {
        
        N = n;
        res.clear();
        backtrack({}, n, 2);
        return res;
    }
};
