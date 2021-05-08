class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = 0;
        int left = 0, right = 0;
        bool leftFlag = false, rightFlag = true;
        unordered_map<char, int> m;
        char check;
        
        while(right <= s.size())
        { 
            if(rightFlag)
            {
                if(right == s.size())
                    break;
                m[s[right]]++;
                if(m[s[right]]==2)
                {
                    leftFlag = true;
                    rightFlag = false;
                    check = s[right];  
                }  
                else 
                    len = max(len, right - left + 1);
                right++;
            }
            else if(leftFlag)
            {
                m[s[left]]--;
                if(m[check] == 1)
                {
                    leftFlag = false;
                    rightFlag = true;
                }
                left++;
            }
        }
        return len;
    }
};
