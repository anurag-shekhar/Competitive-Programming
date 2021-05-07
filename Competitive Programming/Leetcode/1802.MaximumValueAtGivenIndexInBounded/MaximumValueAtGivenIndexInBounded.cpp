class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        int resValue = 1; 
        int sum = n;
        int left = index+1, right = index-1;
        int flag;
        while(1){
            flag =1;
            if(left>0)
            {
                flag = 0;
                left--;
            }    
                
            if(right<n-1){
                flag = 0;
                right++;
            }
            
                
            sum += (right-left+1);
            
            //cout<<left<<" "<<right<<" "<<sum<<" "<<resValue<<endl;
            if(sum >maxSum)
                break;
            resValue++;
            if(flag)
            {
                int newSum = maxSum - sum;
                int freq = newSum/n;
                return resValue + freq;
            }
        }
        return resValue;
    }
};
/*
9
3
16

4 0 4
*/
