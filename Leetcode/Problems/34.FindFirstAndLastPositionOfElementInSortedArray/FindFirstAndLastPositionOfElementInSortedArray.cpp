/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindFirstAndLastPositionOfElementInSortedArray.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

class Solution {
public:
    
    int bsearch(vector<int>& nums, int left, int right, int target,bool isStart)
    {
        if(left > right)
            return -1;
        
        int mid = (right-left)/2 +left;
        
        if(nums[mid] == target)
        {
            if(isStart)
            {
                if(mid==0 || nums[mid-1] != target)
                    return mid;
                return bsearch(nums, left, mid-1, target, isStart);
            }
            else 
            {
                if(mid==right || nums[mid+1] != target)
                    return mid;
                return bsearch(nums, mid+1, right, target, isStart);
            }
            
        }
        else if(nums[mid] > target)
            return bsearch(nums, left, mid-1, target, isStart);
        else 
            return bsearch(nums, mid + 1, right, target, isStart);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,0);
        
        res[0] = bsearch(nums, 0, nums.size()-1, target, true);
        res[1] = bsearch(nums, 0, nums.size()-1, target, false);
        return res;
    }
};



/*
1 3 4 5 6 7 7 7 7 7 8 9 9  
*/
