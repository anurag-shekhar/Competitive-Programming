/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumAbsoluteSumDifference.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

#define MOD 1000000007
#define ll long long int
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        ll maxAbsDiff = 0;
        vector<ll> idxAbsDiff;
        
        ll res = 0;
        for(int i =0; i<n; i++)
        {
            ll check = abs(nums1[i] - nums2[i]);
            maxAbsDiff = max(maxAbsDiff, check);
        }
        //cout<<maxAbsDiff<<endl;
        if(maxAbsDiff == 0)
            return 0;
        
        bool flag = false;
        for(int i =0; i<n; i++)
        {
            ll check = abs(nums1[i] - nums2[i]);
            
            if(check == maxAbsDiff)
            {
                if(flag)
                {
                    res += check;
                    res %=MOD;
                }
                flag = true;
                idxAbsDiff.push_back(i);
            }
            else 
            {
                res += check;
                res %=MOD;
            }
                
                
        }
        
        //cout<<res<<endl;
        
        ll minAbsDiff = INT_MAX;
        sort(nums1.begin(), nums1.end());
        for(int i = 0; i<idxAbsDiff.size(); i++)
        {
            auto search = lower_bound(nums1.begin(), nums1.end(), nums2[idxAbsDiff[i]]);
            ll idx = search - nums1.begin();
            ll minVal;
            if(idx>0)
                minVal = min(abs(nums2[idxAbsDiff[i]] - nums1[idx]), abs(nums2[idxAbsDiff[i]] - nums1[idx-1]));
            else 
                minVal = abs(nums2[idxAbsDiff[i]] - nums1[idx]);
            
            minAbsDiff = min(minAbsDiff,minVal);   
        }
        res += minAbsDiff;
        res %=MOD; 
        //cout<<res<<endl;
        return res;
    }
};

/*
[1,7,5]
[2,3,5]
[2,4,6,8,10]
[2,4,6,8,10]
[1,10,4,4,2,7]
[9,3,5,1,7,4]
*/
