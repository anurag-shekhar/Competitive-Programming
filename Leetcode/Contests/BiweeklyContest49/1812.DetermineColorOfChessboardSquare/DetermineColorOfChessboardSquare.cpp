/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DetermineColorOfChessboardSquare.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

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
