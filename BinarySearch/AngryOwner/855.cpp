/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 855.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(vector<int>& customers, vector<int>& mood, int k) {
    
    int zeroCustomer = 0;
    int maxZeroCustomer = 0;
    int oneCustomer = 0;
    
    int left = 0, right = 0;
    int n = customers.size();
    while(right < k)
    {
        if(mood[right]==0)
            zeroCustomer += customers[right];
        else 
            oneCustomer += customers[right];    
        right++;    
    }
    maxZeroCustomer = max(maxZeroCustomer, zeroCustomer);
    while(right < n)
    {
        if(mood[left]==0)
            zeroCustomer -= customers[left];

        if(mood[right]==0)
            zeroCustomer += customers[right];
        else 
            oneCustomer += customers[right];        

        maxZeroCustomer = max(maxZeroCustomer, zeroCustomer);
        right++;
        left++;

    }

    return  maxZeroCustomer + oneCustomer;

}
