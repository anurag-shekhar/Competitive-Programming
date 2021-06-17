/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 642.cpp
 * Created on : Thu Jun 17 2021
 ****************************************************************
 */

int solve(vector<int>& nums, int k) {
    
    unordered_map<int, int> m;
    m[0] = 1;
    int res = 0;
    for(int i = 0; i<nums.size(); i++)
    {
        if(i!=0)
            nums[i] += nums[i-1];
        
        int val = nums[i]%k;
        res += m[val];
        m[val]++;
    }
    return res;
}
/*


 5 3 2  10 
 5 8 10 20

5 1 5
5 6 5

0 - 1
1 - 1
1 3 4 3
1 4 8 11 


*/
