/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindPositiveIntegerSolutionForGivenEquation_optimised.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
     
        vector<vector<int> > res;
        
        int left = 1, right=1000;
        
        while(left<1001 && right > 0)
        {
            int val = customfunction.f(left,right);
            if(z < val)
                right--;
            else if( z > val)
                left++;
            else 
                res.push_back({left++, right--});
        }
        return res;
    }
};
