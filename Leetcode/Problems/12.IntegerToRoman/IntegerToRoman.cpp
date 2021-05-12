/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : IntegerToRoman.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:
    string intToRoman(int num) {
        
        if(num == 0)
            return "";
        vector<int> I = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> C = {"I","IV","V", "IX", "X", "XL","L", "XC","C", "CD", "D", "CM", "M"};
        
        int i = 12;
        
        while(i>=0)
        {
            if(I[i] <= num)
                break;
            i--;
        }
        return C[i] + intToRoman(num - I[i]);
        
        
    }
};
