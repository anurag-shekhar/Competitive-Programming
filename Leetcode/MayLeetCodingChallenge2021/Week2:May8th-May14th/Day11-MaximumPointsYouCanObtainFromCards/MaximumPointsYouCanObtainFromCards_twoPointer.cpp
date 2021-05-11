/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumPointsYouCanObtainFromCards_twoPointer.cpp
 * Created on : Tue May 11 2021
 ****************************************************************
 */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for(int i = 1; i<n; i++)
            cardPoints[i] += cardPoints[i-1];

        int sum = INT_MIN;
        int left = 0, right = n-k-1;

        if(n==k)
            return cardPoints[n-1];
        while(right<n)
        {
            if(left>0)
                sum = max(sum , cardPoints[left-1]+cardPoints[n-1] - cardPoints[right]);   
            else 
                sum = max(sum ,cardPoints[n-1] - cardPoints[right]);

            left++;
            right++;       
        }
        return sum;
    }
};
