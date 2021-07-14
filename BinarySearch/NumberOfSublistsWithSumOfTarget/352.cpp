/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 352.cpp
 * Created on : Wed Jul 14 2021
 ****************************************************************
 */

int solve(vector<int>& nums, int target) {
    unordered_map<int,int> m;
    m[0] = 1;
    int sum = 0;
    int res = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        sum += nums[i];
        int diff = sum-target;
        if(m.count(diff))
            res += m[diff];
        
        m[sum] += 1;
    } 
    return res;
}

/*


[2,0,2]
2 2 
*/
