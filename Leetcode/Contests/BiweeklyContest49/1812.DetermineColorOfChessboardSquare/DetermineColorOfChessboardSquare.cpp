

class Solution {
public:
    bool squareIsWhite(string s) {
        
        int firstDigit = s[0]-'a';
        int secondDigit = s[1]-'0';
        
        if(firstDigit%2)
        {
            if(secondDigit%2)
                return true;
            return false;
        }
        else 
        {
            if(secondDigit%2)
                return false;
            return true;
        }
        
    }
};
