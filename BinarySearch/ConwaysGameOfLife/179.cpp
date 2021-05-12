/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 179.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

vector<vector<int>> solve(vector<vector<int>>& mat) {
    
    int r = mat.size();
    int c = mat[0].size();

    vector<vector<int>> prefixSum(r,vector<int> (c)),res(r,vector<int> (c));

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            prefixSum[i][j] = mat[i][j];

            if(i>0)
                prefixSum[i][j] += prefixSum[i-1][j];
            if(j>0)
                prefixSum[i][j] += prefixSum[i][j-1];
            if(i>0 && j>0)
                prefixSum[i][j]-=prefixSum[i-1][j-1];       
        }
    }

    for(vector<int> v:prefixSum)
    {
        for(int a : v)
            cout<<a<<" ";
        cout<<endl;    
    }

    cout<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            int sum = prefixSum[min(i+1,r-1)][min(j+1,c-1)];
            if(i-2>=0)
                sum -= prefixSum[i-2][min(j+1,c-1)];
            if(j-2 >= 0)
                sum -= prefixSum[min(i+1,r-1)][j-2];
            if(j-2 >= 0 && i-2>=0)    
                sum += prefixSum[i-2][j-2];

            sum -= mat[i][j];

            if(mat[i][j])
            {
                if(sum==2 && sum==3)
                    res[i][j] = 1;
                else 
                    res[i][j] = 0;
            }
            else 
            {
                if(sum==3)
                    res[i][j] = 1;
                else 
                    res[i][j] = 0;    
            }
        }
    }
    return res;
}
