class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        arr[0]=1;
        int prev = 1;
        for(int i = 1; i<n; i++)
        {
            arr[i] = min(prev+1,arr[i]);
            prev = arr[i];
        }
        
        return arr[n-1];
    }
};
