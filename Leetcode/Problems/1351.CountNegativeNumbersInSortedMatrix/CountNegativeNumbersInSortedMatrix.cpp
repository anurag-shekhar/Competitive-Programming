/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountNegativeNumbersInSortedMatrix.cpp
 * Created on : Sun Jun 23 2024
 ****************************************************************
 */

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        int i = 0;
        int j = c-1;
        int result = 0;
        while( i<r && j>=0) {
            while(j>=0 && grid[i][j] < 0) {
                j--;
            }
            if(j==-1) {
                result += (r-i) * c;
                break;
            }
            result += (c-j-1);
            i++;
        }
        return result;
        
    }
};