/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RotatingTheBox.cpp
 * Created on : Sat May 15 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        
        int r = box.size();
        int c = box[0].size();
        for(int i = 0; i<r; i++)
        {  
            for(int j = c-1; j>=0; j--)
            {
                if(box[i][j]=='*')
                    continue;
                int hash = 0;
                int k = j;
                while(k>=0 && box[i][k]!='*')
                {
                    if(box[i][k] == '#')
                        hash++;
                    k--;
                }
                k++;
                while(k<=j)
                {
                    if(hash)
                    {
                        box[i][j] = '#';
                        hash--;
                    }
                    else 
                        box[i][j] = '.';
                    j--;
                }    
            }
        }
        vector<vector<char> > res(c,vector<char>(r));
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                res[j][r-i-1] = box[i][j];
            }
        }
        return res;       
    }
};
