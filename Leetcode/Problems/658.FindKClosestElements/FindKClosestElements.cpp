/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindKClosestElements.cpp
 * Created on : Fri Jul 02 2021
 ****************************************************************
 */

class Solution {
public:
    void bsearch(vector<int> &arr, int left, int right, int &idx, int diff, int x)
    {
        if(left > right)
            return;
        
        int mid = (right-left)/2 + left;
        
        int currDiff = abs(arr[mid]-x);
        if(currDiff < diff || (currDiff == diff && mid < idx))
        {
            idx = mid;
            diff = currDiff;
        }
        
        if(arr[mid] <= x)
            bsearch(arr, mid+1, right, idx, diff, x);
        else 
            bsearch(arr, left, mid-1, idx, diff, x);
            
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int idx = -1;
        int n = arr.size();
       
        bsearch(arr, 0, n-1, idx, INT_MAX, x); 
        vector<int> res;
        res.push_back(arr[idx]);
        
        cout<<idx<<" "<<arr[idx]<<endl;
        int left = idx-1;
        int right = idx+1;
        
        while(res.size() < k)
        {
            
            if(left >=0 && right < n)
            {
                if(abs(arr[left]-x) <= abs(arr[right]-x))
                {
                    res.push_back(arr[left]);
                    left--; 
                }
                else 
                {
                    res.push_back(arr[right]);
                    right++;
                }
            }
            else if(left >= 0)
            {
                res.push_back(arr[left]);
                left--;
            }
            else if(right< n)
            {
                res.push_back(arr[right]);
                right++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
