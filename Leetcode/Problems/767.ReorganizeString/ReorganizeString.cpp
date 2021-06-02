/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReorganizeString.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    
    string reorganizeString(string s) {
        
        
        vector<int> charCount(26,0);
        
        int n = s.size();
        for(char ch : s)
            charCount[ch-'a']++;
        
        priority_queue<vector<int>> maxHeap;
        for(int i = 0; i<26; i++)
        {
            if((2*charCount[i]-1) > n)
                return "";
            if(charCount[i])
                maxHeap.push({charCount[i], i});
        }
        
        string res = "";
        while(maxHeap.size() >= 2)
        {
            vector<int> a = maxHeap.top(); maxHeap.pop();
            vector<int> b = maxHeap.top(); maxHeap.pop();
            
            res += ('a'+a[1]);
            res += ('a'+b[1]);
            a[0]--;
            b[0]--;
            
            if(a[0])
                maxHeap.push(a);
            if(b[0])
                maxHeap.push(b);
            
        }
        
        if(maxHeap.size()==1)
        {
            vector<int> a = maxHeap.top(); maxHeap.pop();
            if(a[0]  > 1)
                return "";
            res += ('a'+a[1]);          
        }
        
        return res;
    }
};
