/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindXORSumOfAllPairsBitwiseAND.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        
        int arr1XOR = arr1[0];
        int arr2XOR = arr2[0];
        
        int n = arr1.size();
        int m = arr2.size();
        for(int i = 1; i<n; i++)
            arr1XOR ^= arr1[i];
        for(int i = 1; i<m; i++)
            arr2XOR ^= arr2[i];
        
        return (arr2XOR & arr1XOR);
        
    }
};
