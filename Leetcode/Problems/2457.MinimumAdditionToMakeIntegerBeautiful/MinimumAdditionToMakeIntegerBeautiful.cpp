/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : MinimumAdditionToMakeIntegerBeautiful.cpp
 * Created on : Sun Oct 30 2022 
 ***************************************************************
 */

class Solution {
public:
    long long makeBeautiful(vector<int> &digits, int target, int place, long sum) {
        
        if(sum <= target) 
            return 0;
        if(digits[place] == 0)
            return 10 * makeBeautiful(digits, target, place+1, sum);
        
        int diff = digits[place] == 0? 0 : 10 - digits[place];
        int carry = 1;
        int i = place+1;
        sum -= (digits[place]);
        while(carry) {
            sum -= digits[i];
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %=10;
            sum += digits[i];
            i++;
        }
        
        return diff + 10 * makeBeautiful(digits, target, place+1, sum);
    }
    
    void tokenize(long long n, vector<int> &digits) {
        
        while(n) {
            digits.push_back(n%10);
            n/=10;
        }
    }
    long long makeIntegerBeautiful(long long n, int target) {
        
        vector<int> digits;
        tokenize(n, digits);
        digits.push_back(0);
        long sum = 0;
        for(int d : digits) {
            sum += d;
        }
        return makeBeautiful(digits, target, 0, sum);
        
    }
};
