/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumNumberOfOperationsToMoveAllBallsToEachBox.cpp
 * Created on : Thu May 20 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        //Method 2 - O(n)
        int n = boxes.size();
        vector<int> prefix(n,0),suffix(n,0);
        
        int countP = 0, countS = 0;
        for(int i = 0; i<n; i++)
        {
            if(i!=0)
            {
                prefix[i] = prefix[i-1] + countP; 
                suffix[n-1-i] = suffix[n-i] + countS;
            }
            if(boxes[i] == '1')
                countP++;
            if(boxes[n-1-i] == '1')
                countS++;
        }
        for(int i = 0; i<n; i++)
            prefix[i] += suffix[i];
        
        return prefix;
        
     /* //Method 1 (Brute Force) - O(n^2)
     int n = boxes.size();
        vector<int> res(n,0);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i!=j && boxes[j]=='1')
                {
                    res[i] += abs(i-j);
                }
            }
        }
        return res;
     */   
    }
};
