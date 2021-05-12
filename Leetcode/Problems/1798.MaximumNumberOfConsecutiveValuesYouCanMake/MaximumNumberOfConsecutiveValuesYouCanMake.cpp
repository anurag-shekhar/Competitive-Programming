/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumNumberOfConsecutiveValuesYouCanMake.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int sum = 1;
        for(int c : coins){
            if(c > sum)
                break;
            sum += c;
        }    
        return sum;
            
        
    }
};
