class Solution {
public:
    int minSwaps(vector<int>& data) {
        
        int n = data.size();
        if(n==1)
            return 0;
        for(int i = 1; i<n; i++)
            data[i]+=data[i-1];
        
        int left = 0, right = data[n-1]-1;
        
        if(right < 0)
            return 0;
        int max1Subarray = 0;
        while(right < n)
        {
            int ones = data[right];
            if(left !=0)
                ones -= data[left-1];
            max1Subarray = max(max1Subarray, ones);
            left++;
            right++;
        }
        return (data[n-1] - max1Subarray);
        
    }
};
/*
1,0,1,0,1,0,0,1,1,0,1
1 1 2 2 3 3 3 4 5 5 6
            ^       ^
*/
