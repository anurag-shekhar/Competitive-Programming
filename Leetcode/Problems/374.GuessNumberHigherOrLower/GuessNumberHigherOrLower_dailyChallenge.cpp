/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : GuessNumberHigherOrLower_dailyChallenge.cpp
 * Created on : Wed Nov 16 2022 
 ***************************************************************
 */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int bsearch(long low, long high) {
        long mid = (low+high)/2;
        int guessVal = guess(mid);
        if(guessVal == -1)
            return bsearch(low, mid-1);
        else if(guessVal == 1) 
            return bsearch(mid+1, high);
        return mid;
    }

    int guessNumber(int n) {
        return bsearch(1, n);
    }
};