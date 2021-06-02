/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidMountainArray.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        if(n<3)
            return false;
        int idx= 1;
        
        while(idx<n && arr[idx-1] < arr[idx]) idx++;
        
        if(idx==n || idx==1)
            return false;
        
        while(idx<n && arr[idx-1] > arr[idx]) idx++;
        
        if(idx==n)
            return true;
        return false;
    }
};
