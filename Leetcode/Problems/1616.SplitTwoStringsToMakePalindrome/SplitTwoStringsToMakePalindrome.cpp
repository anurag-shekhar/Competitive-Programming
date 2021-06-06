/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SplitTwoStringsToMakePalindrome.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

class Solution {
public:
    
    bool isPalin(string s,int start, int end)
    {
    
        while(start<= end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    bool checkPalindromeFormation(string a, string b, bool flag = true) {
        
        
        if(flag && checkPalindromeFormation(b,a,false))
            return true;
        
        if(isPalin(a,0,a.size()-1) || isPalin(b, 0, b.size()-1))
            return true;
        
        int idxA = 0, idxB = b.size()-1; 
        
        while(idxA<a.size() && idxB >=0)
        {
            if(a[idxA]!=b[idxB])
            {   
                if(isPalin(a,idxA,idxB) || isPalin(b,idxA, idxB))
                    return true;
                return false;
            }
            
            idxA++;
            idxB--;
        }
        return false;
    }
};



