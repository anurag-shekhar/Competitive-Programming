/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CouplesHoldingHands.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        //Greedy Approach        
        int count = 0;
        int n = row.size();
        
        unordered_map<int,int> m;
        for(int i = 0; i<n;i++)
            m[row[i]] = i;
        
        for(int i = 0; i<n; i+=2)
        {
            if((row[i]%2) && (row[i+1]!=(row[i]-1))) // odd
            {
                m[row[i+1]] = m[row[i]-1];
                swap(row[i+1], row[m[row[i]-1]]);
                count++;
            }
            else if((row[i]%2==0) && (row[i+1]!=(row[i]+1)))
            {
                m[row[i+1]] = m[row[i]+1];
                swap(row[i+1], row[m[row[i]+1]]);
                count++;
            }
            
        }
        return count;
    }
};
