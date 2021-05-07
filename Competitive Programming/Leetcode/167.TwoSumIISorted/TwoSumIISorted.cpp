class Solution {
public:
    int Bsearch(vector<int>& A,int left, int right, int target)
    {
        if(left > right)
            return -1;
        int m = (left+right)/2;
        if(A[m]==target)
            return m;
        if(target <= A[m])
            return Bsearch(A,left,m-1,target);
        else 
            return Bsearch(A,m+1,right, target);
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        for(int i = 0; i<n; i++)
        {
            int idx = Bsearch(numbers,i+1,n-1,target-numbers[i]);
            if(idx != -1)
                return {i+1,idx+1};
        }
        return {};
    }
};
