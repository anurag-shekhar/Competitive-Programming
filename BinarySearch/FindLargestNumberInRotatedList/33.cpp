/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 33.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(vector<int>& arr) {
    
    int n = arr.size();
    int left = 0, right = n-1;

    int res = arr[0];
    while(left <= right)
    {
        int mid = (right-left)/2 + left;
        
        if(arr[mid] > arr[(mid-1+n)%n] && arr[mid] > arr[(mid+1)%n])
            return arr[mid];
        else if(arr[left] <= arr[mid])
            left = mid+1;
        else 
            right = mid-1;        
    }
    return res;

}
