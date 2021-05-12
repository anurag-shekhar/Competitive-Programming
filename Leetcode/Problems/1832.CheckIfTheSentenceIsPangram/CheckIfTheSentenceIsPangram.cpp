/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CheckIfTheSentenceIsPangram.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for(char ch : sentence)
        {
           s.insert(ch); 
        }
        if(s.size()==26)
            return true;
        return false;
    }
};
