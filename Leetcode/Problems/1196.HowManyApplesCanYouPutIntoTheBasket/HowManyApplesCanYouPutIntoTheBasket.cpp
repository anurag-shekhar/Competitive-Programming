/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : HowManyApplesCanYouPutIntoTheBasket.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        
        int capacity = 5000;
        sort(arr.begin(), arr.end());
        int n = arr.size();    
        int store = 0;;
        for(int i = 0; i<n; i++)
        {
            if(store + arr[i] > capacity)
                return i;
            store += arr[i];
        }
        return n;
    }
};
