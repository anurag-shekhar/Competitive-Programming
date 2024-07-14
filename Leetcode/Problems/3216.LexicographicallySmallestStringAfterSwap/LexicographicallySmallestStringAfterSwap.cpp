/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LexicographicallySmallestStringAfterSwap.cpp
 * Created on : Mon Jul 15 2024
 ****************************************************************
 */

class Solution {
public:
    string getSmallestString(string s) {
        
        int n = s.size();
        for(int i = 1; i<n; i++) {
            int n1 = s[i-1] - '0';
            int n2 = s[i] - '0';
            if((n1%2) == (n2%2) && n2 < n1) {
                swap(s[i], s[i-1]);
                break;
            }
        }
        return s;
    }
};