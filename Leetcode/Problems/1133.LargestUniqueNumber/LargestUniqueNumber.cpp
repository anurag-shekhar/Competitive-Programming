class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        
        sort(A.begin(), A.end());
        
        for(int i = A.size()-1; i>=0;)
        {
            int res = 0;
            int count  = 0;
            while(i > 0 && A[i] ==A[i-1])
            {
                count++;
                i--;
            }
            if(!count)
                return A[i];
            i--;
        }
        return -1;
    }
};
