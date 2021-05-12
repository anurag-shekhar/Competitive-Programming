/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximalRectangle.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int r = matrix.size();
        if(r==0)
            return 0;
        int c = matrix[0].size();
        vector<vector<int>> A(r,vector<int>(c));
        

        for(int i =0 ; i<r; i++){
            for(int j = 0;j<c; j++){
                A[i][j] = matrix[i][j]-'0';
                if(j>0 && A[i][j])
                    A[i][j] += A[i][j-1];  
            }
        }
        
        // for(int i =0 ; i<r; i++){
        //     for(int j = 0;j<c; j++){
        //         cout<<A[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }    
        long result = 0,localMax;
        for(int j = 0; j<c; j++){
            for(int i = 0; i<r; i++){
                long minVal = INT_MAX;
                for(int k = i; k<r; k++){
                    minVal = minVal > (A[k][j]) ? (A[k][j]) : minVal;//min(minVal, A[k][j]);
                    localMax = (long)(k-i+1) * minVal;
                    result = max(result,localMax);
                }
            }    
        }
        return result;
    }
};
