/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : MakeTheStringGreat.cpp
 * Created on : Tue Nov 08 2022 
 ***************************************************************
 */

class Solution {
public:
    string makeGood(string s) {

        unordered_map<char ,char> m;

        for(char i = 'a', j='A'; i<='z'; i++, j++) {
            m[i]=j;
            m[j]=i;
        }
        string result = "";
        int n = s.size();
        for(int i = 0; i<n; i++) {
            cout<<result.back()<<endl;
            if(!result.empty() && result.back() == m[s[i]]) {
                result.pop_back();
            }
            else 
                result.push_back(s[i]);
        }
        return result;

        
    }
};