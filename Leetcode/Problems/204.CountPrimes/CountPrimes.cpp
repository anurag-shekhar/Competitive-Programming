class Solution {
public:
    int countPrimes(int n) {
        
        if(n<=1)
            return 0;
        vector<bool> mark(n,false);
        
        
        
        int count = 0;
        for(int i = 2; i<n; i++)
        {
            if(!mark[i])
            {
                count++;
                
                for(int j = i; j<n; j+=i)
                    mark[j] = true;
            }
        }
        return count;
        
    }
};
