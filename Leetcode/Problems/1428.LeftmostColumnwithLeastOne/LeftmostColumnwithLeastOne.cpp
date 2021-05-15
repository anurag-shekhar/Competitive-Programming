/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LeftmostColumnwithLeastOne.cpp
 * Created on : Sat May 15 2021
 ****************************************************************
 */


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int binarysearch(int low, int high,BinaryMatrix &mat, int row)
    {
        int idx = INT_MAX;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(mat.get(row, mid))
            {
                high = mid-1;
                idx = mid;
            }
                
            else 
                low = mid+1;
        }
        return idx;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dim = binaryMatrix.dimensions();
        
        int minIdx = dim[1];
        
        for(int i = 0; i<dim[0]; i++)
        {
            int idx = binarysearch(0,dim[1]-1, binaryMatrix, i);
            minIdx = min(minIdx, idx);
        }
        if(minIdx == dim[1])
            return -1;
        return minIdx;     
    }
};
