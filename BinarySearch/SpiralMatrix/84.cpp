/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 84.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

vector<int> solve(vector<vector<int>>& matrix) {
    vector<int> res;
    int r = matrix.size();
    if(r==0)
        return res;
    int c = matrix[0].size();
    int ver = 0, hor = 0;
    bool flag = true;
    while(1)
    {
        flag = false;
        for(int j = hor; j<c-hor; j++)
        {                          
            res.push_back(matrix[ver][j]);
            flag = true;
        }
        if(res.size()==r*c) break;  
        for(int i = ver+1; i<r-ver; i++)  // [2,5)
        {
            res.push_back(matrix[i][c-hor-1]);
            flag = true;
        }    
        if(res.size()==r*c) break;

        for(int j = c-hor-2; j>=hor; j--) //[0,1]
        {
            res.push_back(matrix[r-ver-1][j]);
            flag = true;
        }
        if(res.size()==r*c) break;
            

        for(int i = r-ver-2; i>ver; i--) //[3,2]
        {
            res.push_back(matrix[i][hor]);
            flag = true;
        }
        if(res.size()==r*c) break;
        ver++;
        hor++;        
    }
    return res;
}
