/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SortIntegersByThePowerValue.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

#define ll long long int
unordered_map<ll,ll> storePower;
class Solution {
public:
    
    static ll getPower(ll A)
    {   
        if(A==1)
            return storePower[A]=0;
        
        if(storePower.count(A))
            return storePower[A];
        if(A%2)
            return storePower[A] = 1+getPower(A*3+1);
        return storePower[A] = 1+getPower(A/2);
    }
    
    static bool compare(int a, int b)
    {
        int x = getPower(a);
        int y = getPower(b);
        
        if(x<y || (x==y && a<b))
            return true;
        return false;
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<int> A;
        for(int i = lo; i<=hi; i++)
            A.push_back(i);
        
        sort(A.begin(), A.end(), compare);
        
        return A[k-1];
        
    }
};
