/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PascalsTriangle.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> > res;
        
        for(int i = 0; i<numRows; i++) {
            vector<int> row(i+1);
            for(int j = 0;j<i+1; j++){
                if(i==j || j==0)
                    row[j] = 1;
                else 
                    row[j] = res[i-1][j] + res[i-1][j-1];
            }
            res.push_back(row);
        }
        return res;
    }
};