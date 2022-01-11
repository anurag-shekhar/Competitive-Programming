/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MergeSortedArray.cpp
 * Created on : Wed Jan 12 2022
 ****************************************************************
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ptr1 = m-1, ptr2= n-1, ptr = m+n-1;
        
        while(ptr1 >= 0 && ptr2 >= 0)
        {
            if(nums1[ptr1] > nums2[ptr2])
            {
                nums1[ptr] = nums1[ptr1];
                ptr1--;
                ptr--;
            }
            else 
            {
                nums1[ptr] = nums2[ptr2];
                ptr2--;
                ptr--;
            }
        }
        
        while(ptr1 >= 0)
        {
            nums1[ptr] = nums1[ptr1];
            ptr1--;
            ptr--;
        }
        
        while(ptr2 >= 0)
        {
            nums1[ptr] = nums2[ptr2];
            ptr2--;
            ptr--;
        }
    }
};
