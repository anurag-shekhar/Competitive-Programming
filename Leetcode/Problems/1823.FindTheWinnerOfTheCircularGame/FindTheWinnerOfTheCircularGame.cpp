class Solution {
public:
    int findTheWinner(int n, int k) {
        
        int circle = n;
        vector<int> A(n);
        for(int i = 0; i<n; i++)
            A[i]=i+1;
        int idx = 0;
        while(circle!=1)
        {
            idx = (idx+k-1)%circle;
            int temp = A[idx];
            for(int i = idx; i<circle-1; i++)
                A[i] = A[i+1];
            A[circle-1] = temp;
            circle--;

        }
        return A[0];
        
    }
};
