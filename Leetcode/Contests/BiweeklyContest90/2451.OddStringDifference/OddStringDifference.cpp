/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : OddStringDifference.cpp
 * Created on : Sun Oct 30 2022 
 ***************************************************************
 */

class Solution {
public:
    
    string differenceArray(string s, int n)
    {
        string result = "";
        for(int i = 1; i < n; i++) {
            result += to_string(s[i] - s[i-1]);
            result += ",";
        }
        return result;
    }
    string oddString(vector<string>& words) {
        
        int n = words[0].size();
        string diff1 = differenceArray(words[0], n);
        string diff2 = differenceArray(words[1], n);

        if(diff1 != diff2)
        {
            string diff3 = differenceArray(words[2], n);
            if(diff1 == diff3)
                return words[1];
            else 
                return words[0];
        }
        
        for(int i = 2; i <words.size(); i++)
        {
            
            string diff = differenceArray(words[i], n);
            if(diff != diff1)
                return words[i];
        }
        return "";
    }
};
