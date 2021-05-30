/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumGap.cpp
 * Created on : Mon May 31 2021
 ****************************************************************
 */

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        
        /*Pigenhole principle 
            we have n elements 
            remove min and max ele , now we have n-2 ele
            create a bucket of n-1 , then in that case there will be atlest one empty bucket.
        */
        
        int n = nums.size();
        if(n<2)
            return 0;
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        for(int i = 0; i<n; i++)
        {
            minEle = min(minEle, nums[i]);
            maxEle = max(maxEle, nums[i]);
        }
        
        int bucketSize = ceil((maxEle - minEle)/ (double)(n-1));
        vector<int> minOfBucket(n-1, INT_MAX);
        vector<int> maxOfBucket(n-1, INT_MIN);
        //idx of bucket = (nums[i] - minEle) / n-1
        for(int i = 0; i<n; i++)
        {
            if(nums[i]==minEle || nums[i]==maxEle)
                continue;
            int idx = (nums[i] - minEle)/ bucketSize;
            minOfBucket[idx] = min(minOfBucket[idx], nums[i]);
            maxOfBucket[idx] = max(maxOfBucket[idx], nums[i]);
        }
        
        int lastVal = minEle;
        int gap = 0;
        for(int i = 0; i<n-1; i++)
        {
            if(minOfBucket[i] == INT_MAX)
                continue;
            gap = max(gap, minOfBucket[i]-lastVal);
            lastVal = maxOfBucket[i];  
        }
        gap = max(gap, maxEle-lastVal);
        return gap;
        
        
    }
};
/*
[15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740]

[12115,10639,2351,29639,31300,11245,16323,24899,8043,4076,17583,15872,19443,12887,5286,6836,31052,25648,17584,24599,13787,24727,12414,5098,26096,23020,25338,28472,4345,25144,27939,10716,3830,13001,7960,8003,10797,5917,22386,12403,2335,32514,23767,1868,29882,31738,30157,7950,20176,11748,13003,13852,19656,25305,7830,3328,19092,28245,18635,5806,18915,31639,24247,32269,29079,24394,18031,9395,8569,11364,28701,32496,28203,4175,20889,28943,6495,14919,16441,4568,23111,20995,7401,30298,2636,16791,1662,27367,2563,22169,1607,15711,29277,32386,27365,31922,26142,8792]
*/


