/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 4Sum.cpp
 * Created on : Mon Jul 26 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int> > uniq_res;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(j - i > 2)
                {
                    int left = i + 1; 
                    int right = j - 1;
                    int search = target - nums[i] - nums[j];
                    while(left < right)
                    {
                        int sum = nums[left] + nums[right];
                        if(sum == search)
                        {
                            uniq_res.insert({nums[i], nums[left], nums[right], nums[j]});
                            left++;
                            right--;
                        }
                        else if(sum > search)
                            right--;
                        else 
                            left++;
                    }
                }
            }
        }
        
        vector<vector<int> > res;
        for(auto v : uniq_res)
            res.push_back(v);
        return res;
    }
};
/*

a + b+ c+ d = t
x + c + d = t

c + d (O(n)) = t - x(O(n^2))
*/
