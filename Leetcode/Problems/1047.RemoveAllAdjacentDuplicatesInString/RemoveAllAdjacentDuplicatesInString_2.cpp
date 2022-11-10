/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : RemoveAllAdjacentDuplicatesInString_2.cpp
 * Created on : Thu Nov 10 2022 
 ***************************************************************
 */

class Solution {
public:
    string removeDuplicates(string s) {

        string res = "";
        for(char si : s) {
            if((!res.empty() && res.back() == si)) {
                while(!res.empty() && res.back() == si)
                    res.pop_back();
            } else 
                    res.push_back(si);
        }
        return res;
        
    }
};