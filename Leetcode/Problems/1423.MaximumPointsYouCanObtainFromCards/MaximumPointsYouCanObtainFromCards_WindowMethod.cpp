/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumPointsYouCanObtainFromCards_WindowMethod.cpp
 * Created on : Tue May 11 2021
 ****************************************************************
 */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        

        int n = cardPoints.size();
        
        for(int i = 1; i<n; i++)   //prefix sum
            cardPoints[i] += cardPoints[i-1];
        
        if(k==n)
            return cardPoints[n-1];
        
        int res = 0;
        for(int i = -1; i<k; i++)
        {
            int sum = 0;
            if(i>=0)
                sum += cardPoints[i];
            sum += (cardPoints[n-1] - cardPoints[n+i-k]);
            
            res = max(sum, res);
        }
        return res;
        
    }
};
