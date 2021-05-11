class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        reverse(num.begin(), num.end());
        
        int n = num.size();
        int i = 0, carry = 0,val;
        
        while(k || carry)
        {
            val = carry;
            if(i<n)
                val += num[i];
            val += k%10;
            k /=10;
            
            if(i<n)
                num[i++] = val%10 ;
            else 
                num.push_back(val%10);
            carry = val/10;
        }
            
        reverse(num.begin(), num.end());
        
        return num;
        
    }
};
