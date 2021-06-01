/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GuessNumberHigherOrLower.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int binary_search(int left, int right)
    {
        int mid = (right-left)/2 + left;
        int g = guess(mid);
        if(g==0)
            return mid;
        else if(g==-1)
            return binary_search(left, mid-1);
        else 
            return binary_search(mid+1, right);
    }
    int guessNumber(int n) {
        
        return binary_search(1,n);
        
    }
};
