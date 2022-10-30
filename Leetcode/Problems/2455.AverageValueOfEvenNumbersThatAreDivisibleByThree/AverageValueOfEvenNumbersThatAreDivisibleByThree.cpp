/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : AverageValueOfEvenNumbersThatAreDivisibleByThree.cpp
 * Created on : Sun Oct 30 2022 
 ***************************************************************
 */

class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        double sum = 0;
        int count = 0;
        for(int n : nums) {
            if(n%3==0 && n%2==0) {
                sum += n;
                count++;
            }
        }
        if(count==0)
            return 0;
        sum = sum/count;
        return (int)sum;
        
    }
};
