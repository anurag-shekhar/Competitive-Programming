/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : LongestPalindromeByConcatenatingTwoLetterWords.cpp
 * Created on : Thu Nov 03 2022 
 ***************************************************************
 */

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int > m;
        
        for(string word : words) {
            m[word]++;   
        }
        
        int longestPalin = 0;
        bool pivot = false;
        int temp;
        
        for(string cell : words) {
            if(m[cell] != 0) {
                if(cell[0] == cell[1]) {
                    temp = (m[cell] / 2) * 2;
                    longestPalin += 2*temp;
                    m[cell] -= temp;
                    if(m[cell] % 2)
                        pivot = true;
                } else {
                    string reverseStr = "";
                    reverseStr += cell[1];
                    reverseStr += cell[0];
                    temp = min(m[cell], m[reverseStr]);
                    longestPalin += 4*temp;
                    m[cell] -= temp;
                    m[reverseStr] -= temp;
                }
            }
        }
        if(pivot)
            longestPalin += 2; 
        return longestPalin;        
    }
};
