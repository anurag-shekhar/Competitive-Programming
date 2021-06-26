/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountOfSmallerNumbersAfterSelf.cpp
 * Created on : Sat Jun 26 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> count,idx;
    void merge(vector<int> &nums, int left,int mid, int right)
    {
        int lSize = mid-left+1;
        int rSize = right - mid;
        vector<int> lIdx(lSize), rIdx(rSize);
        
        for(int i = 0; i<lSize; i++)
            lIdx[i] = idx[i+left];
        for(int i = 0; i<rSize; i++)
            rIdx[i] = idx[i+mid+1];
        
        
        int l=0, r=0, k=left, smallCount = 0;
        
        while(l < lSize && r < rSize)
        {
            if(nums[lIdx[l]] > nums[rIdx[r]])
            {
                idx[k] = rIdx[r];
                smallCount++;
                r++;
            }
            else 
            {
                idx[k] = lIdx[l];
                count[lIdx[l]] += smallCount;
                l++;
            }
            k++;
        }
        
        while(l < lSize)
        {
            idx[k] = lIdx[l];
            count[lIdx[l]] += smallCount;
            k++;
            l++;
        }
        while(r < rSize)
        {
            idx[k] = rIdx[r];
            k++;
            r++;
        }
        
    }
/*
       m
     0 1 2 3 
     2 1 1 0 
    [5,2,6,1]
    
    
    [1,0,3,2]
    [3,1,0,2]
    
*/
    void mergesort(vector<int> &nums, int left, int right)
    {
        if(left<right)
        {
            int mid = (right-left)/2 + left;
            mergesort(nums, left, mid);
            mergesort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        idx = vector<int> (n,0);
        count = vector<int> (n,0);
        
        for(int i = 0; i<n; i++)
            idx[i] = i; 
         
        vector<int> res(n,0);
        mergesort(nums, 0, n-1);
        
        for(int i = 0; i<n; i++)
        {
            res[idx[i]] = count[idx[i]];
        }
        return res;
    }
};



