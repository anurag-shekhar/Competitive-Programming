/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : ReverseWordsInString.cpp
 * Created on : Sun Nov 13 2022 
 ***************************************************************
 */

class Solution {
public:
    string reverse(string s) {
        int right = s.size()-1, left = 0;

        while(left < right) {
            int temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
        return s;
    } 
    string reverseWords(string s) {

        int idx = 0;
        int n = s.size();
        string res = "";
        while(idx < n) {
            while(idx < n && s[idx] == ' ')
                idx++;
            int wordEndIdx = idx;
            while(wordEndIdx < n && s[wordEndIdx] != ' ')
                wordEndIdx++;
            if(wordEndIdx != idx && res.size() != 0)
                res+=" ";
            for(int i = wordEndIdx-1; i>=idx; i--)
                res += s[i];
            idx = wordEndIdx;
        }
        res = reverse(res);
        return res;
        
    }
};