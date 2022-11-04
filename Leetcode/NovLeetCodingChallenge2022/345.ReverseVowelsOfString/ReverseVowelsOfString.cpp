/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : ReverseVowelsOfString.cpp
 * Created on : Fri Nov 04 2022 
 ***************************************************************
 */


class Solution {
public:
    string reverseVowels(string s) {
        
        int left = 0;
        int right = s.size()-1;

        set<char> hashVowel;
        hashVowel.insert('a');
        hashVowel.insert('e');
        hashVowel.insert('i');
        hashVowel.insert('o');
        hashVowel.insert('u');
        hashVowel.insert('A');
        hashVowel.insert('E');
        hashVowel.insert('I');
        hashVowel.insert('O');
        hashVowel.insert('U');
        
        bool foundVowel = false;
        while(left < right) {
            while(left < right && hashVowel.count(s[left]) == 0) 
                left++;
            while(right > left && hashVowel.count(s[right]) == 0) 
                right--;
            
            if(left >= right)
                break;
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
        return s;
    }
};
