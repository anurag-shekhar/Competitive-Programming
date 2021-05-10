/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ConstructTargetArrayWithMultipleSums.cpp
 * Created on : Mon May 10 2021
 ****************************************************************
 */

class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int n = target.size();
        
        if(n==1)
            return target[0]==1;
        
        priority_queue<int> maxHeap;
        long sum = 0;
        for(int a : target)
        {
            sum += a;
            maxHeap.push(a);
        }
        
        //maxEle = delta + remaining element  | delta>0
        while(maxHeap.top() > 1)
        {
            int maxEle = maxHeap.top();
            maxHeap.pop();
            
            int remainingSum = sum - maxEle;
            
            if(remainingSum == 1)
                return true;
            
            int delta = maxEle % remainingSum;
            
            if(delta < 1 || delta == maxEle)
                return false;
            
            maxHeap.push(delta);
            sum -= maxEle;
            sum += delta;
        }
        return true;
        
        
    }
};
