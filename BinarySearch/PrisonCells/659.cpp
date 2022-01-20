/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 659.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

vector<int> solve(vector<int>& nums, int k) {

    vector<vector<int > > state;

    state.push_back(nums);

    for(int j = 1; j<15; j++)
    {
        nums[0] = 0;
        nums[7] = 0;
        for(int i = 1; i<7; i++)
        {
            int temp = state[j-1][i-1] + state[j-1][i+1];
            nums[i] = temp%2 ? 0 : 1;
        } 

        // for(int i = 0; i<8; i++)
        //     cout<<nums[i]<<",";
        // cout<<endl;
        state.push_back(nums);
    }    
    k = k%14;
    if(k==0)
        k=14;
    
    return state[k];
}

