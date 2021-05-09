/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 6.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

vector<int> solve(vector<int>& nums) {

    int n = nums.size();
    vector<int> prefixProd(n), suffixProd(n);

    for(int i = 0; i<n; i++)
    {
        if(i==0)
        {
            prefixProd[i] = nums[i];
            suffixProd[n-i-1] = nums[n-i-1];
        }
        else 
        {
            prefixProd[i] = prefixProd[i-1]*nums[i];
            suffixProd[n-i-1] = suffixProd[n-i]*nums[n-i-1];
        }
    }

    for(int i = 0; i<n; i++)
    {
        if(i==0)
            nums[i] = suffixProd[i+1];
        else if(i==n-1)
            nums[i] = prefixProd[i-1];
        else 
            nums[i] = suffixProd[i+1]*prefixProd[i-1];        
    }
    return nums; 
}

/*
 1.   2   6   24  120
120  120. 60  20   5   

120. 60   40  

*/
