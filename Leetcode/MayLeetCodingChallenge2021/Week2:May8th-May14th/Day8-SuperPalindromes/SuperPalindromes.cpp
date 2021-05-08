#define ll long long int
class Solution {
public:
    bool checkPalindrome(ll A, ll l, ll r)
    {
        if(A<l || r<A) 
            return false;
        string s = to_string(A);
        int left = 0;
        int right = s.size()-1;
        while(left<=right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    int superpalindromesInRange(string left, string right) {
        
        ll l = stoll(left);
        ll r = stoll(right);
        ll num = 0;
        int count = 0;
        for(int i = 1; i<=9; i++)
        {
            num = i*i;
            if(checkPalindrome(num, l, r))
                count++;   
        }
        
        for(int i = 1; i<10000; i++)
        {
            string s = to_string(i);
            string firstHalf = s;
            reverse(s.begin(),s.end());
            string secondHalf = s;
            string buildNum = firstHalf+secondHalf;
            num = stoll(buildNum);
            num =num*num;
            if(checkPalindrome(num, l, r))
                count++;    
            for(int j = 0; j<=9; j++)
            {
                buildNum = firstHalf + to_string(j) + secondHalf;
                num = stoll(buildNum);
                num =num*num;
                if(checkPalindrome(num, l, r))
                    count++;   
            }
            
        }
        return count;
    }
};
