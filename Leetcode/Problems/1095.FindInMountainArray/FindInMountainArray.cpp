/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindInMountainArray.cpp
 * Created on : Wed Jun 30 2021
 ****************************************************************
 */


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        
        int left = 0, right = n - 1;
        int mountainIdx = -1;
        
        while(left <= right)
        {
            int mid = (right-left)/2 + left;
            
            int immediateLeft = -1, immediateRight = -1;
            
            if(mid != 0)
                immediateLeft = mountainArr.get(mid-1);
            if(mid != n-1)
                immediateRight = mountainArr.get(mid+1);
            int val = mountainArr.get(mid);
            
            if(mid!=0 && mid!=n-1 && val > immediateRight && val > immediateLeft)
            {
                mountainIdx = mid;
                break;
            }
            else if(mid==0 || val > immediateLeft)
                left = mid+1;
            else 
                right = mid-1;
        }
        left = 0;
        right = mountainIdx;
        while(left <= right)
        {
            int mid = (right-left)/2 + left;
            
            int val = mountainArr.get(mid); 
            if(val == target)
                return mid;
            else if(val > target)
                right = mid-1;
            else 
                left = mid+1;
        }
        left = mountainIdx;
        right = n-1;
        while(left <= right)
        {
            int mid = (right-left)/2 + left;
            
            int val = mountainArr.get(mid); 
            if(val == target)
                return mid;
            else if(val < target)
                right = mid-1;
            else 
                left = mid+1;
        }
        
        return -1;
    }
};
