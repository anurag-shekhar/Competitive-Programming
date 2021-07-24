/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ShuffleArray.cpp
 * Created on : Sat Jul 24 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> original,ans;
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ans = original;
        return ans;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        ans = original;
        
        int n = ans.size();
        
        while(n)
        {
            int randIdx = rand()%n;
            int temp = ans[randIdx];
            ans[randIdx] = ans[n-1];
            ans[n-1] = temp;
            n--;
        }
        return ans; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
