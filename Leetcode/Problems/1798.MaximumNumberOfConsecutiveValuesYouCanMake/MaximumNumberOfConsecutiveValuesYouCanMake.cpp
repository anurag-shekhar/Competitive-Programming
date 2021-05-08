class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int sum = 1;
        for(int c : coins){
            if(c > sum)
                break;
            sum += c;
        }    
        return sum;
            
        
    }
};
