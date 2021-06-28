/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PeakIndexInMountainArray.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        
        int left = 0, right = n-1;
        
        while(left<=right)
        {
            int mid = (right-left)/2 + left;
            
            if(mid < n-1 && mid > 0 && arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
                return mid;
            else if(mid ==0 || arr[mid-1] < arr[mid])
                left = mid+1;
            else if(mid == n-1 || arr[mid] > arr[mid+1])
                right = mid -1;
        }
        return -1;
        
        
    }
};


/*

       
          /  \ 
        /      \
                 \
                  \

         l   ^1     r

     l > m > r
     l < m > r
     l < r < m
*/
