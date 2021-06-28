/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RotateFunction.cpp
 * Created on : Mon Jun 28 2021
 ****************************************************************
 */

class Solution {
public:
    int maxRotateFunction(vector<int>& input) {
        int sum = 0;
        int score = 0;
        int n = input.size();
        for(int i = 0; i<n; i++)  // init & preprocessing
        {
            score += input[i] * i;
            sum += input[i];
        }
        int res = score;
        for(int i = 0; i<n; i++)
        {
            score = score + input[i]*n - sum;
            res = max(res, score);
        }
        return res;

    }
};
